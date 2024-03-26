#include "lemIn.h"

void    printQueue(t_list *queue) {
    printf("=============QUEUE===========\nSize of queue : %d\n", ft_lstsize(queue));
    t_room  *prevRoom = NULL;
    while (queue) {
        if (queue->prev) {
            prevRoom = (t_room *)queue->prev->content;
            printDataStr("Previous room : ", prevRoom->name);
        } else printDataStr("Previous room : ", "NULL");

        printRoom(queue->content);

        queue = queue->next;
    }
    printf("=============================\n");
}

void    printRQueue(t_list *queue) {
    printf("============= REVERSE QUEUE===========\nSize of queue : %d\n", ft_lstsize(queue));
    t_room  *prevRoom = NULL;
    while (queue) {
        if (queue->prev) {
            prevRoom = (t_room *)queue->prev->content;
            printDataStr("Previous room : ", prevRoom->name);
        } else printDataStr("Previous room : ", "NULL");

        printRoom(queue->content);

        queue = queue->prev;
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

void custom_pop(t_list **list, t_list **poped) {
    if (*list == NULL)
        return;

    t_list *first = *list;
    *list = first->next;
    first->next = NULL;
    ft_lstadd_back(poped, first);
}

bool enqueue(t_room *prevRoom, t_list **queue) {
    t_list  *neigh = prevRoom->neigh;
    t_room  *roomTmp = NULL;
    while (neigh) {
        roomTmp = (t_room *)neigh->content;
        if (roomTmp->isEnd == true) {
            roomTmp->isInqueue = true;
            ft_lstadd_front(queue, ft_lstnew_prev(roomTmp, *queue));
            return true;
        } else if (roomTmp->isSeen == NOT_SEEN && roomTmp->isInqueue == false) {
            roomTmp->isInqueue = true;
            ft_lstadd_back(queue, ft_lstnew_prev(roomTmp, *queue));
        }
        neigh = neigh->next;
    }
    return false;
}

char    **createPath(t_list *queue){
    char    **ret = NULL;
    size_t  size = ft_lstsize_prev(queue);
    ret = malloc(sizeof(char *) * (size + 1));
    ret[size--] = NULL;
    t_room *tmp = NULL;
    while (queue) {
        tmp = (t_room *)queue->content;
        ret[size--] = ft_strdup(tmp->name);
        queue = queue->prev;
    }
    return ret;
}


bool pathFinding(t_simulation *simu) {
    t_list *queue = NULL;
    t_room *current = NULL;
    t_list *poped = NULL;
    bool    ret = false;

    simu->graph->startRoom->isSeen = true;
    ft_lstadd_back(&queue, ft_lstnew(simu->graph->startRoom));

    while (ft_lstsize(queue) > 0) {
        current = (t_room *)queue->content;
        current->isSeen = SEEN;
        // printQueue(queue);
        if (current->isEnd == true || enqueue(current, &queue) == true ) {
            ret = true;
            ft_lstadd_back(&simu->paths, ft_lstnew(createPath(queue)));   // Echec avec sanitize, ne pas add les path issu d'une bifurcation
            custom_pop(&queue, &poped);
            // break when size de simu->paths = size de endRoom->neigh
        }
        // custom_pop(&queue, &poped);
    }
    ft_lstclear(&queue, noFree);
    ft_lstclear(&poped, noFree);
    return ret;
}