#include "lemIn.h"

void    printQueue(t_list **queue) {
    t_list *tmp = *queue;
    t_room *roomTmp;
    printf("=============QUEUE===========\nSize of queue : %d\n", ft_lstsize(tmp));

    while (tmp) {
        roomTmp = (t_room *)tmp->content;
        // printf("Queue : %s\n", roomTmp->name);
        printRoom(roomTmp);
        if (tmp->prev) {
            t_room *prev = (t_room *)tmp->prev->content;
            //printf("Prev : %s\n", prev->name);
        }
        tmp = tmp->next;
    }
    printf("=============================\n");
}

t_list  *ft_lstnew_prev(void *content, void *prev) {
    	t_list	*li;

	li = malloc(sizeof(t_list));
	if (!li)
		return (NULL);
	li->content = content;
	li->next = NULL;
    li->prev = prev;
	return (li);
}

void enqueue(t_room *current, t_list **queue) {
    t_list *tmp = current->neigh;
    t_room *roomTmp = NULL;

    printf("Size of neighb : %d\n", ft_lstsize(tmp));

    while (tmp) {
        roomTmp = (t_room *)tmp->content;
        if (roomTmp->isSeen == NOT_SEEN && roomTmp->isInqueue == false) {
            roomTmp->isInqueue = true;
            ft_lstadd_back(queue, ft_lstnew_prev(tmp->content, *queue));
        }
        tmp = tmp->next;
    }
}

int pathFinding(t_simulation *simu) {
    t_list *queue = NULL;
    t_room *current = NULL;

    simu->graph->startRoom->isSeen = true;
    enqueue(simu->graph->startRoom, &queue);


    while (ft_lstsize(queue) > 0) {
        printQueue(&queue);
        current = (t_room *)queue->content;

        current->isSeen = SEEN;

        if (current == simu->graph->endRoom)
            break;
        if (current->isEnd == true) {
            break ;
        }
        

        ft_lst_pop(&queue);
        enqueue(current, &queue);
    }

    return 1;
}