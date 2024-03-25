#include "lemIn.h"

void    printQueue(t_list *queue) {
    printf("=============QUEUE===========\nSize of queue : %d\n", ft_lstsize(queue));
    t_room  *prevRoom = NULL;
    while (queue) {
        if (queue->prev) {
            prevRoom = (t_room *)queue->prev->content;
            printDataStr("Previous room : ", prevRoom->name);
        }
        else printDataStr("Previous room : ", "NULL");

        printRoom(queue->content);

        queue = queue->next;
    }
    printf("=============================\n");
}

t_list  *ft_lstnew_prev(void *content, t_list *prev) {
    	t_list	*li;

	li = malloc(sizeof(t_list));
	if (!li)
		return (NULL);
	li->content = content;
	li->next = NULL;
    li->prev = prev;
	return (li);
}

bool enqueue(t_room *prevRoom, t_list **queue) {
    t_list  *neigh = prevRoom->neigh;
    t_room  *roomTmp = NULL;
    while (neigh) {
        roomTmp = (t_room *)neigh->content;
        if (roomTmp->isEnd == true) {
            roomTmp->isInqueue = true;
            ft_lstadd_front(queue, ft_lstnew_prev(roomTmp, ft_lstnew(prevRoom)));
            return true;
        } else if (roomTmp->isSeen == NOT_SEEN && roomTmp->isInqueue == false) {
            roomTmp->isInqueue = true;
            ft_lstadd_back(queue, ft_lstnew_prev(roomTmp, ft_lstnew(prevRoom)));
        }
        neigh = neigh->next;
    }
    return false;
}

int pathFinding(t_simulation *simu) {
    t_list *queue = NULL;
    t_room *current = NULL;

    simu->graph->startRoom->isSeen = true;
    enqueue(simu->graph->startRoom, &queue);
    printQueue(queue);

    while (ft_lstsize(queue) > 0) {
        current = (t_room *)queue->content;
        current->isSeen = SEEN;
        if (enqueue(current, &queue) == true) {
            printQueue(queue);
            break ;
        }
        ft_lst_pop(&queue);
        printQueue(queue);
    }
    return 1;
}