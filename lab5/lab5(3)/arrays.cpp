#include "arrays.h"
#include <stdio.h>
#include <malloc.h>
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

int del(int* mas, int* mas2, int n, int m) {
    int l = n;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < l; i++) {
            if (mas2[j] == mas[i]) {
                l--;
                for (int k = i; k < l; k++) {
                    int a = mas[k];
                    mas[k] = mas[k + 1];
                    mas[k + 1] = a;
                }

            }
        }
    }
    return l;
}
void outputmas(int* mas, int n) {
    for (int i = 0; i < n; i++) printf("%d\t", mas[i]);
}
void outputmass(int** mas, int n, int* m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m[i]; j++)
            printf("%d\t", mas[i][j]);
        printf("\n");
    }
}
void delcolumn(int** mas, int numcol, int m, int n) {
    for (int j = 0; j < n; j++) {
        for (int k = numcol; k < m; k++) {
            int a = mas[j][k];
            mas[j][k] = mas[j][k + 1];
            mas[j][k + 1] = a;
        }
        mas[j] = (int*)realloc(mas[j], m * sizeof(int));
    }
}

void del_em(int** mas, int m, int str, int el) {
    for (int i = el; i < m - 1; i++) {
        int dp = mas[str][i];
        mas[str][i] = mas[str][i + 1];
        mas[str][i + 1] = dp;
    }
}
void same_el_del(int K, int** mas, int n, int* m) {
    int amount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m[i]; j++) {
            if (mas[i][j] == K ) {
                amount++;
                if (amount > 1) {
                    del_em(mas, m[i], i, j);
                    m[i]--;
                    
                }

            }

        }
        
     }
}