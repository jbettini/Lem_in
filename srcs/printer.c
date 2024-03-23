#include "lemIn.h"

void printSimu(t_simulation *simu) {
    printf("%d\n", simu->ants);
}

void printRoom(t_room *room) {
    printf("Room : { name : %s, posX : %d, posY : %d, isEnd : %d, isStart : %d}\n", room->name, room->posX, room->posY, room->isEnd, room->isStart);
}