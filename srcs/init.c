/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:18:31 by jbettini          #+#    #+#             */
/*   Updated: 2024/03/24 07:02:41 by jbettini         ###   ########.fr       */
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
    simu->roomsNames = NULL;
    return simu;
}

