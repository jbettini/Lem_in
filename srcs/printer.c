/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 02:44:47 by jbettini          #+#    #+#             */
/*   Updated: 2024/03/24 03:45:37 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemIn.h"

void	colorPrint(char *color, char *str){
	printf("%s%s%s", color, str, FANCY_RESET);
}

void	printDataStr(char *prefix, char *data){
	colorPrint(TXT_YELLOW, prefix);
	colorPrint(TXT_BLUE, data);
	printf("\n");
}

void	printDataInt(char *prefix, int data){
	colorPrint(TXT_YELLOW, prefix);
	printf("%s%d%s", TXT_BLUE, data, FANCY_RESET);
	printf("\n");
}

void	printNeighbors(t_list	*n){
	colorPrint(TXT_YELLOW, "Neighbors : ");
	while (n) {
		t_room *tmp = n->content;
		colorPrint(TXT_BLUE, tmp->name);
		n = n->next;
	}
	printf("\n");
}

void	printRoom(t_room *room) {
	colorPrint(TXT_MAGENTA, "\n---\nRoom : \n");
	printDataStr("Name : ", room->name);
	if (room->isStart)
		printDataStr("Start : ", "true");
	else
		printDataStr("Start : ", "false");
	if (room->isEnd)
		printDataStr("End : ", "true");
	else
		printDataStr("End : ", "false");
	colorPrint(TXT_YELLOW, "Position : ");
	printf("%s X = %d Y = %d%s\n", TXT_BLUE, room->posX, room->posY, FANCY_RESET);
	printNeighbors(room->neigh);
	printf("\n");
}

void	printGraph(t_graph *g) {
	colorPrint(TXT_MAGENTA, "\n-----\nGraph : \n");
	printDataInt("Number of Rooms : ", g->numRooms);
	t_list	*r = g->rooms;
	while (r) {
		printRoom(r->content);
		r = r->next;
	}
}

void	printSimu(t_simulation *simu) {
	colorPrint(TXT_MAGENTA, "Simulation\n----------\n\n");
	printDataInt("Number of Ants : ", simu->ants);
	printGraph(simu->graph);
}
