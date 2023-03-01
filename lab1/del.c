#include "del.h"

extern int amount;

void delete_sctruct(anim** anime) {
    printf("choose what struct u want to delete ");
    int del_num = 0;
    scanf_s("%d", &del_num);
    for (int i = del_num; i < amount - 1; i++) {
        (*anime)[i].title = (*anime)[i + 1].title;
        (*anime)[i].year = (*anime)[i + 1].year;
        (*anime)[i].type = (*anime)[i + 1].type;
    }
    amount--;
    (*anime) = (anim*)realloc((*anime), amount * sizeof(anim));
    printf("\033[0d\033[2J");
}