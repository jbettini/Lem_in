/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:17:50 by jbettini          #+#    #+#             */
/*   Updated: 2024/03/22 23:31:59 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemIn.h"

bool    onlyDigitStr(char *str){
    for (int i = 0; str[i]; i++){
        if (!(ft_isdigit(str[i])))
            return false;
    }
    return true;
}

bool    isComment(char *str){
    if (str[0] == '#' && str[1] != '#')
        return true;
    return false;
}

bool    isStart(char *str) {
    if (ft_strcmp(str, "##start") == 0)
        return true;
    return false;
}

bool    isEnd(char *str){
    if (str[0] == '#' && str[1] == '#' && ft_strlen(str) == 5 && ft_strequ((str + 2), "end"))
        return true;
    return false;
}

bool    isRoom(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ' || !ft_isdigit(str[i]))
            return false;
    }
    return true;
}


bool    isLink(char *str) {
    if (ft_strchr(str, '-') != 0)
        return true;
    return false;
}

bool    isInstruction(char *str){
    if (str[0] == '#' && str[1] == '#')
        return true;
    return false;
}

bool isNullOrEmpty(char *str) {
    if (ft_strlen(str) == 0 || (ft_strlen(str) == 1 && str[0] == '\0') || str == NULL)
        return true;
    return false;
}


//is Room
//is link

t_simulation    *parseStdin(char *filename) {
    t_simulation    *simu   = getEmptySimulation();
    int             fd      = open(filename, O_RDONLY);
    char            *line;

    for (int i = 0; (line = get_next_line(fd)); i++) {
        
        if (isNullOrEmpty(line))// Check if the current line is empty or null
            break;

        if (i == 0) {
            line[ft_strlen(line) - 1] = '\0';
            if (onlyDigitStr(line)) {
                simu->ants = ft_atoi(line);
            }
            else {
                badInputFile(line);
                free(line);
                exit(1);
            }
        }
        else if (isComment(line)) {
            continue;
        } else if (isInstruction(line)) {
            line[ft_strlen(line) - 1] = '\0';
            if (isStart(line)) {
                char *nextLine = get_next_line(fd);
                simu->graph->startRoom = roomConstructor(nextLine, 'S');
                t_list *room = ft_lstnew(simu->graph->startRoom);
                ft_lstadd_back(&simu->graph->rooms, room);
                free(nextLine);
            } else if (isEnd(line)) {
                char *nextLine = get_next_line(fd);
                simu->graph->endRoom = roomConstructor(nextLine, 'E');
                t_list *room = ft_lstnew(simu->graph->endRoom);
                ft_lstadd_back(&simu->graph->rooms, room);
                free(nextLine);
            }
            free(line);
            continue ;
        } else if (isLink(line)) {
            line[ft_strlen(line) - 1] = '\0';
            connectLink(line, &simu->graph->rooms);
        } else {
            line[ft_strlen(line) - 1] = '\0';
            t_room *roomData = roomConstructor(line, 'N');
            t_list *room = ft_lstnew(roomData);
            free(roomData);
            ft_lstadd_back(&simu->graph->rooms, room);
            simu->graph->numRooms++;
        }
        //is room
        //is link
        free(line);
    }
    printSimu(simu);
    printRoom(simu->graph->startRoom);
    printRoom(simu->graph->endRoom);
    return simu;
}