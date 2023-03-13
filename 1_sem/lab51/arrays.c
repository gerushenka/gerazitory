#include "arrays.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

#define scanf scanf_s

int checkinput_arr(int a, int m, int z) {
    while (scanf("%d", &a) != 1 || getchar() != '\n' || a < m || a > z) {
        printf("Pls enter a number!\n");
        rewind(stdin);
    }
    return a;
}


void rand_input_arr(int* mas, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        mas[i] = (rand() % 100) - 50;
    }
    outputmas(mas, n);
}


void input_arr(int* mas, int n) {

    for (int i = 0; i < n; i++) {
        printf("Enter the %dth element ", i );
        mas[i] = checkinput_arr(mas[i], INT_MIN, INT_MAX);
    }
    printf("\nYour array\n");
    outputmas(mas, n);

}


void sort_(int* mas, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mas[i] > mas[j]) {
                int a = mas[i];
                mas[i] = mas[j];
                mas[j] = a;
            }

        }
     }
}


void del(int* mas, int n, int numel) {
    for (int i = numel; i < n; i++) {
        int dp = mas[i];
        mas[i] = mas[i + 1];
        mas[i + 1] = dp;
     }
}


void outputmas(int* mas, int n) {
    for (int i = 0; i < n; i++) printf("%d\t", mas[i]);
}


void outputmass(int** mas, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", mas[i][j]);
        printf("\n");
    }
}