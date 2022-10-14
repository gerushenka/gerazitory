#include <stdio.h>
#include <stdlib.h>
#define scanf scanf_s


int inputcheck(int a, int check) {
    while ((check != 1) || (a < 1) || (a > 100) || (getchar() != '\n')) {
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


void inputrandom(int n, int mas[100][100]) {
    printf("\narray created with random\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            mas[i][j] = rand() % 200 - 100;
            printf("%d ", mas[i][j]);
        }
        printf("\n");
    }
}


void input(int n, int mas[100][100]) {
    int check = 0;
    printf("\nEnter array elements");
    for (int i = 1; i <= n; i++) {
        printf("\nEnter %d elements of the %dth string \n", n, i);
        for (int j = 1; j <= n; j++) {
            printf("mas[%d][%d] =", i, j);
            check = scanf("%d", &mas[i][j]);
            mas[i][j] = inputcheck_num(mas[i][j], check);
        }
    }
}


int summ(int n, int mas[100][100]) {
    int summ = 0;
    for (int i = n / 2 + 1; i <= n; i++) {
        for (int j = n / 2 + 1; j <= n; j++) {
            summ += mas[i][j];
        }
    }
    return summ;
}

int main() {
    int mas[100][100]{ 0 };
    int n = 0;
    int check = 0;
    printf("Enter a number of strings and columns in array ");
    check = scanf("%d", &n);
    n = inputcheck(n, check);



    int inic = 0;
    printf("choose how you want to fill the array\n0) by hand\n1) random\n");
    check = scanf("%d", &inic);
    inic = inputcheck_inic(inic, check);
    if (inic == 0)
        input(n, mas);
    else
        inputrandom(n, mas);


    int sum = 0;
    sum = summ(n, mas);


    printf("\nThe sum of the elements of the 4th area = %d\n\n", sum);
}