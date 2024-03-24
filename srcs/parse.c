/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:17:50 by jbettini          #+#    #+#             */
/*   Updated: 2024/03/24 04:58:57 by jbettini         ###   ########.fr       */
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
    if (numOfOccurences(str, ' ') == 2)
        return true;
    return false;
}


bool    isLink(char *str) {
    if (numOfOccurences(str, '-') == 1)
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

t_simulation    *parseStdin() {
    t_simulation    *simu   = getEmptySimulation();
    char            *line;
    int             step = 0;

    while ((line = get_next_line(0))) {
        line = ft_strdup_except(line, '\n');
        if (isNullOrEmpty(line))// Check if the current line is empty or null
            break ;
        if (isComment(line)) {        // skip comment 
            continue ;
        } else if (onlyDigitStr(line)) {
            if (step == 0) {
                simu->ants = ft_atoi(line);
                step = 1;
            }
            else {
                badInputFile(line);
                free(line);
                exit(1);
            }
        } else if (isInstruction(line)) {  
            if (step == 1) {
                t_list *room = NULL;
                char *nextLine = get_next_line(0);
                if (isStart(line) && (!(simu->graph->startRoom))) {
                    simu->graph->startRoom = roomConstructor(nextLine, 'S');
                    room = ft_lstnew(simu->graph->startRoom);
                    ft_lstadd_back(&simu->roomsNames, ft_lstnew(simu->graph->startRoom->name));
                } else if (isEnd(line) && (!(simu->graph->endRoom))) {
                    simu->graph->endRoom = roomConstructor(nextLine, 'E');
                    room = ft_lstnew(simu->graph->endRoom);
                    ft_lstadd_back(&simu->roomsNames, ft_lstnew(simu->graph->endRoom->name));
                } else {
                    badInstruction(line);
                    free(line);
                    free(nextLine);
                    exit(1); // Need to clean ALL before exit
                }
                ft_lstadd_back(&simu->graph->rooms, room);
                simu->graph->numRooms++;
                free(nextLine);
            } else {
                badInputFile(line);
                free(line);
                exit(1);// Need to clean ALL before exit
            }
        } 

        else if (isRoom(line)) {
            
        }







        
        // else if (isLink(line)) {                                  // Make Link
        //     connectLink(line, &simu->graph->rooms);
        // } 
        //else {
        //     t_room *roomData = roomConstructor(line, 'N');
        //     t_list *room = ft_lstnew(roomData);
        //     free(roomData);
        //     ft_lstadd_back(&simu->graph->rooms, room);
        //     simu->graph->numRooms++;
        // }
        free(line);
    }
    // check if simu is enought to load
    printSimu(simu);
    return simu;
}