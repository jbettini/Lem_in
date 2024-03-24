/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:17:50 by jbettini          #+#    #+#             */
/*   Updated: 2024/03/24 08:09:36 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemIn.h"


t_room *roomCopy(t_room *src) {
    t_room *newRoom = malloc(sizeof(t_room));

    newRoom->name = ft_strdup(src->name);
    newRoom->posX = src->posX;
    newRoom->posY = src->posY;
    newRoom->isEnd = src->isEnd;
    newRoom->isStart = src->isStart;
    t_list *tmp = src->neigh;
    while (tmp) {
        ft_lstadd_back(&newRoom->neigh, ft_lstnew(ft_strdup(tmp->content)));
        tmp = tmp->next;
    }
    return newRoom;
}

t_room *roomConstructor(char *str) {
    char **splitArg = ft_split(str, ' ');
    t_room *newRoom = malloc(sizeof(t_room));
    newRoom->name = ft_strdup(splitArg[0]);
    newRoom->posX = ft_atoi(splitArg[1]);
    newRoom->posY = ft_atoi(splitArg[2]);
    newRoom->isEnd = false;
    newRoom->isStart = false;
    newRoom->neigh = NULL;
    freeTab(splitArg);
    return newRoom;
}

void    handleLink(char *str, t_simulation **simu) {
    char    **args = ft_split(str, '-');
    t_simulation *s = *simu;
    if (!nameExist(args[0], s->roomsNames) || !nameExist(args[1], s->roomsNames)) {
        freeTab(args);
        handleErrorWithStr(str, badLinkSettings);
    }
    t_list  **rooms = &((*simu)->graph->rooms);
    t_room  *r1 = getRoomWithName(args[0], rooms);
    t_room  *r2 = getRoomWithName(args[1], rooms);
    if (r1 == NULL || r2 == NULL)
        handleErrorWithoutStr(fatalError);
    if (lstStrEqu(r1->neigh, r2->name) || lstStrEqu(r2->neigh, r1->name))
        handleErrorWithStr(str, linkAlreadyExists);
    ft_lstadd_back(&r1->neigh, ft_lstnew(ft_strdup(r2->name)));
    ft_lstadd_back(&r2->neigh, ft_lstnew(ft_strdup(r1->name)));
    freeTab(args);
}

t_simulation    *parseStdin() {
    t_simulation    *simu   = getEmptySimulation();
    char            *line;
    int             step = 0;

    while ((line = get_next_line(0))) {
        line = ft_strdup_except(line, '\n');
        ft_putendl(line);
        if (isNullOrEmpty(line))// Check if the current line is empty or null
            break ;
        if (isComment(line)) {        // skip comment 
            continue ;
        } else if (onlyDigitStr(line)) {
            if (step == 0) {
                simu->ants = ft_atoi(line);
                step = 1;
            }
            else
                handleErrorWithStr(line, badInputFile); //Need to clean ALL before exit                
        } else if (isInstruction(line)) {  
            if (step == 1) {
                char *nextLine = get_next_line(0);
                t_room  *r = roomConstructor(nextLine);
                bool    validName = nameIsValid(r->name, simu->roomsNames);
                bool    validPos = posIsValid(r, simu->graph->rooms);
                if (validName == false || validPos == false) {
                    free(line);
                    handleErrorWithStr(nextLine, badRoomSettings); //Need to clean ALL before exit
                } else {
                    if (isStart(line) && (!(simu->graph->startRoom))) {
                        r->isStart = true;  
                        simu->graph->startRoom = roomCopy(r); 
                    } else if (isEnd(line) && (!(simu->graph->endRoom))) {
                        r->isEnd = true;
                        simu->graph->endRoom = roomCopy(r);
                    } else {
                        free(nextLine);
                        handleErrorWithStr(line , badInstruction); //Need to clean ALL before exit
                    }
                    ft_lstadd_back(&simu->roomsNames, ft_lstnew(ft_strdup(r->name)));
                    ft_lstadd_back(&simu->graph->rooms, ft_lstnew(r));
                    simu->graph->numRooms++;
                    ft_putstr(nextLine);  
                    free(nextLine);
                }
            } else
                handleErrorWithStr(line, badInputFile); //Need to clean ALL before exit
        } 
        else if (isRoom(line)) {
            if (step == 1) {
                t_room *r = roomConstructor(line);
                bool    validName = nameIsValid(r->name, simu->roomsNames);
                bool    validPos = posIsValid(r, simu->graph->rooms);
                if (validName == false || validPos == false)
                    handleErrorWithStr(line, badRoomSettings); //Need to clean ALL before exit
                ft_lstadd_back(&simu->graph->rooms, ft_lstnew(r));
                ft_lstadd_back(&simu->roomsNames, ft_lstnew(ft_strdup(r->name)));
                simu->graph->numRooms++;
            } else 
                handleErrorWithStr(line, badInputFile); //Need to clean ALL before exit
        } 
        else if (isLink(line)) {
            step = 2;
            handleLink(line, &simu);
        } 
        else
            handleErrorWithStr(line, badInputFile); //Need to clean ALL before exit
        free(line);
    }
    // check if simu is enought to load
    printSimu(simu);
    return simu;
}