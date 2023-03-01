#include "sort.h"
extern int amount;
extern int sort_order;

int compare(const void* a, const void* b) {
    anim* pa = (anim*)a;
    anim* pb = (anim*)b;
    int name_cmp = 0;
    switch (sort_order) {
    case 1:
        name_cmp = strcmp(pa->title, pb->title);
        if (name_cmp != 0) {
            return name_cmp;
        }
        break;
    case 2:
        if (pa->year < pb->year) {
            return -1;
        }
        else if (pa->year > pb->year) {
            return 1;
        }
        break;
    case 3:
        if (pa->type < pb->type) {
            return -1;
        }
        else if (pa->type > pb->type) {
            return 1;
        }
        break;
    case 4:
        name_cmp = strcmp(pa->title, pb->title);
        if (name_cmp != 0) {
            return name_cmp;
        }
        if (pa->year < pb->year) {
            return -1;
        }
        else if (pa->year > pb->year) {
            return 1;
        }
        break;
    case 5:
        name_cmp = strcmp(pa->title, pb->title);
        if (name_cmp != 0) {
            return name_cmp;
        }
        if (pa->type < pb->type) {
            return -1;
        }
        else if (pa->type > pb->type) {
            return 1;
        }

    case 6:
        if (pa->year < pb->year) {
            return -1;
        }
        else if (pa->year > pb->year) {
            return 1;
        }
        if (pa->type < pb->type) {
            return -1;
        }
        else if (pa->type > pb->type) {
            return 1;
        }
        break;
    case 7:

        if (pa->year < pb->year) {
            return -1;
        }
        else if (pa->year > pb->year) {
            return 1;
        }
        int name_cmp = strcmp(pa->title, pb->title);
        if (name_cmp != 0) {
            return name_cmp;
        }
        if (pa->type < pb->type) {
            return -1;
        }
        else if (pa->type > pb->type) {
            return 1;
        }

        break;
    }
}
void sorts(anim* anime) {
    printf("choose fields to sort: ");
    printf("\n1.sort by title name");
    printf("\n2.sort by year of issue");
    printf("\n3.type of length");
    printf("\n4.sort by title name and year of issue");
    printf("\n5.sort by title name and type of length ");
    printf("\n6.sort by year of issue and type of length");
    printf("\n7.sort by all fields\n");
    sort_order = 0;
    scanf_s("%d", &sort_order);

    qsort(anime, amount, sizeof(anim), (int (*)(const void*, const void*)) compare);

}