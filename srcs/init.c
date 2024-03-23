/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:18:31 by jbettini          #+#    #+#             */
/*   Updated: 2024/03/22 23:36:08 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemIn.h"

t_graph     *getEmptyGraph(void) {
    t_graph *graph = malloc(sizeof(t_graph) * 1);
    graph->rooms = NULL;
    graph->endRoom = NULL;
    graph->startRoom = NULL;
    graph->numRooms = 0;
    return graph;
}

t_simulation    *getEmptySimulation(void) {
    t_simulation    *simu = malloc(sizeof(t_simulation) * 1);
    simu->graph = getEmptyGraph();
    simu->ants = 0;
    return simu;
}

t_room *roomConstructor(char *str, char state) {
    char **splitArg = ft_split(str, ' ');
    t_room *newRoom = malloc(sizeof(t_simulation));

    newRoom->name = ft_strdup(splitArg[0]);
    newRoom->posX = ft_atoi(splitArg[1]);
    newRoom->posY = ft_atoi(splitArg[2]);
    newRoom->isEnd = false;
    newRoom->isStart = false;
    if (state == 'S')
        newRoom->isStart  = true;
    else if (state == 'E')
        newRoom->isEnd = true;
    newRoom->neigh = NULL;

    freeTab(splitArg);

    return newRoom;
}

void    connectLink(char *str, t_list **head) {
    char    **splitArg = ft_split(str, '-');
    t_list  *firstLink = NULL;
    t_list  *secondLink = NULL;
    t_list  *tmp = *head;
    t_room  *roomTmp = NULL;

    printf("%s\n", str);

    while (tmp->next != NULL) {
        roomTmp = (t_room *)tmp->content;
        if (ft_strcmp(roomTmp->name, splitArg[0]) == 0)
            firstLink = tmp;
        else if (ft_strcmp(roomTmp->name, splitArg[1]) == 0)
            secondLink = tmp;
        tmp = tmp->next;
    }

    roomTmp = (t_room *)firstLink->content;
    ft_lstadd_back(&roomTmp->neigh, secondLink);
    roomTmp = (t_room *)secondLink->content;
    ft_lstadd_back(&roomTmp->neigh, firstLink);
    freeTab(splitArg);
}