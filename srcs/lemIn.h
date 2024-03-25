/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemIn.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:22:29 by jbettini          #+#    #+#             */
/*   Updated: 2024/03/25 04:17:04 by jbettini         ###   ########.fr       */
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
    int     isSeen;
    bool    isInqueue;
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
    t_list  *roomsNames;
    t_list  **paths;
}               t_simulation;



# define NOT_SEEN   0
# define SEEN       1

//error.c
int             invalidNumOfArg(void);
int             badInputFile(char *badLine);
int             badInstruction(char *badLine);
void            handleErrorWithStr(char *line, int (*fun)(char *));
void            handleErrorWithoutStr(int (*fun)(void));
int             badRoomSettings(char *badLine);
int             badLinkSettings(char *badLine);
int             fatalError(void);
int             linkAlreadyExists(char *badLine);


//parse.c
t_simulation    *parseStdin();
void            handleLink(char *str, t_simulation **simu);
t_room          *roomConstructor(char *str);
t_room          *roomCopy(t_room *src);

// algo
int             pathFinding(t_simulation *simu);

//init.c
t_simulation    *getEmptySimulation(void);
t_graph         *getEmptyGraph(void);

// Memory Manager
void            freeTab(char **tab);
void            safeFree(void *ptr);

// print.c
void colorPrint(char *color, char *str);
void printDataStr(char *prefix, char *data);
void printDataInt(char *prefix, int data);
void printNeighbors(t_list *n);
void printRoom(t_room *room);
void printGraph(t_graph *g);
void printSimu(t_simulation *simu);

// utils
char    	    *ft_strdup_except(char *src, char exclude);
int             numOfOccurences(const char *str, char c);
char            *ft_strdup_except(char *src, char exclude);
int             numOfOccurences(const char *str, char c);
bool            onlyDigitStr(char *str);
bool            isComment(char *str);
bool            isStart(char *str);
bool            isEnd(char *str);
bool            isRoom(char *str);
bool            isLink(char *str);
bool            isInstruction(char *str);
bool            isNullOrEmpty(char *str);
bool            nameExist(char *str, t_list *allName);
bool            nameIsValid(char *str, t_list *allName);
bool            posIsValid(t_room *r, t_list *allRooms);
t_room          *getRoomWithName(char *str, t_list **rooms);
bool            lstStrEqu(t_list *lst, char *str);
t_room          *Cast(t_list *roomNode);
#endif