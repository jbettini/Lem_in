/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemIn.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:22:29 by jbettini          #+#    #+#             */
/*   Updated: 2024/03/22 23:35:34 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN
    #define LEM_IN

#include "../libft/libft.h"
#include <stdio.h>

typedef struct  s_room
{
	t_list  *neigh;
    int     posX, posY;
    bool    isStart, isEnd;
    char    *name;
}				t_room;

typedef struct  s_graph
{
    t_list  *rooms;
    t_room  *startRoom;
    t_room  *endRoom;
    int     numRooms;
    
}               t_graph;

typedef struct  s_simulation
{
    t_graph *graph;
    int     ants;
    char    **roomsNames;
}               t_simulation;

//error.c
int             invalidNumOfArg(void);
int             badInputFile(char *badLine);

//parse.c
bool            isComment(char *str);
bool            onlyDigitStr(char *str);
t_simulation    *parseStdin(char *filename);
void            connectLink(char *str, t_list **head);

//init.c
t_simulation    *getEmptySimulation(void);
t_graph         *getEmptyGraph(void);
t_room          *roomConstructor(char *str, char state);

// Memory Manager
void            freeTab(char **tab);

// debuger
void            printSimu(t_simulation *simu);
void            printRoom(t_room *room);


#endif