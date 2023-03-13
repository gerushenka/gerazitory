#include <stdio.h>
#include <stdlib.h>
#define scanf scanf_s

int inputcheck(int a, int check) {
    while ((check != 1) || (a < 1) || (a > 100) ||(getchar() != '\n')) {
        printf("Pls, try again!");
        rewind(stdin);
        check = scanf("%d", &a);
    }
    return a;
}


int inputcheck_inic(int a, int check) {
    while ((check != 1) || (a < 0) || (a > 1) || (getchar() != '\n')) {
        printf("Pls, try again!");
        rewind(stdin);
        check = scanf("%d", &a);
    }
    return a;
}


int inputcheck_num(int a, int check) {
    while (check != 1 || (getchar() != '\n')) {
        printf("Pls, try again!");
        rewind(stdin);
        check = scanf("%d", &a);
    }
    return a;
}


void inputrandom(int n, int m, int mas[100][100]) {
    printf("\narray created with random\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            mas[i][j] = rand() % 200 - 100;
            printf("%d ", mas[i][j]);
        }
        printf("\n");
    }
}


int inputmas(int n, int m, int mas[100][100]) {
    int check = 0;
    printf("\nEnter array elements\n");
    for (int i = 1; i <= n; i++) {
        printf("\nEnter %d elements of the %dth string \n", m, i);
        for (int j = 1; j <= m; j++) {
            printf("mas[%d][%d] =", i, j);
            check = scanf("%d", &mas[i][j]);
            mas[i][j] = inputcheck_num(mas[i][j], check);
        }
    }
    return mas[100][100];
}


void output(int n, int m, int mas[100][100]) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mas[i][j] < 0)
                mas[i][j] = 0;
            printf("%d ", mas[i][j]);
        }
        printf("\n");
    }
}


int main() {
    int mas[100][100]{ 0 };
    int check = 0;
    int fl = 0, n = 0, m = 0, null = 0;
    printf("Enter a number of strings in array ");
    check = scanf("%d", &n);
    n = inputcheck(n, check);


    printf("\nEnter a number of columns in array ");
    check = scanf("%d", &m);
    m = inputcheck(m, check);



    int inic = 0;
    printf("choose how you want to fill the array\n0) by hand\n1) random\n");
    check = scanf("%d", &inic);
    inic = inputcheck_inic(inic, check);
    if (inic == 0)
        inputmas(n, m, mas);
    else
        inputrandom(n, m, mas);


    for (int i = 1; i <= n; i++) {
        null = 0;
        for (int j = 1; j <= m; j++) {
            if (mas[i][j] == 0)
                null++;
        }
        if (null == 0)
            fl = 1;
    }


    if (fl == 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (mas[i][j] < 0)
                    mas[i][j] = 0;
            }
        }
        printf("\nArray with nulls instead of negative elements\n");
        output(n, m, mas);


    }
    else
        printf("\nAll strings in array contain null element\n\n");
}