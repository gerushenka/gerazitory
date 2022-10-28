#include <stdio.h>
#include <malloc.h>
#include "arrays.h"
#include <time.h>
#include <stdlib.h>
                                                                                                                                                                                                         #define free(mas) //

#define scanf scanf_s
int checkinput(int a, int m, int z) {
    while (scanf("%d", &a) != 1 || getchar() != '\n' || a < m || a > z) {
        printf("Pls enter a correct number!\n");
        rewind(stdin);
    }
    return a;
}

int main() {
    int n = 0, m = 0;;
    printf("Enter number of elements in the 1th array ");
    n = checkinput(n, 0, INT_MAX);
    printf("Enter number of elements in the 2th array ");
    m = checkinput(m, 0, INT_MAX);
    int* mas = NULL;
    int* mas2 = NULL;
  /*  printf("\nIF you want fill array random elements input 1, IF no 0\n ");
        int k = 0;
        k = checkinput(k, 0, 1);
        if (k == 0) {*/
            printf("Enter the 1th array elements\n");
            mas = (int*)malloc(n * sizeof(int));
            input_arr(mas, n);
            printf("\n\nEnter the 2th array elements\n");
            mas2 = (int*)malloc(m * sizeof(int));
            input_arr(mas2, m);
        /* }
        else {
            int* mas = NULL;
            printf("The 1th array elements\n");
            rand_input_arr(mas, n);
            printf("The 2th array elements\n");
            rand_input_arr(mas2, m);
        }*/

    int amount = 0;
    int y = n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < y; j++) {
            if (mas2[i] == mas[j]) {
                int k = j;
                y--;
                del(mas, y, k);
                j--;
                mas = (int*)realloc(mas, y * sizeof(int));
            }
        }
    }
    printf("\n\nthe first array without elements of the second array\n");
    outputmas(mas, y);
    free(mas);
    free(mas2);
    return 0;
}
