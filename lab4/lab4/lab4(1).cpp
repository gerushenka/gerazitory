#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#define scanf scanf_s


int inputcheck(int a, int check) {
    while ((check != 1) || (a < 1) || (a > 100) || (getchar() != '\n')) {
        printf("Pls, try again!");
        rewind(stdin);
        check = scanf("%d", &a);
    }
    return a;
}

int inputcheck_inic(int a, int check)  {
    while ((check != 1) || (a < 0) || (a > 1) || (getchar() != '\n')) {
        printf("Pls, try again!");
        rewind(stdin);
        check = scanf("%d", &a);
    }
    return a;
}

int inputcheck_num(int a, int check) {
    while (check != 1 || (getchar() != '\n') ){
        printf("Pls, try again!");
        rewind(stdin);
        check = scanf("%d", &a);
    }
    return a;
}


void inputrandom(int n, int m, int mas[100][100], int masadd[100][100]) {
    printf("array created with random\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            mas[i][j] = rand() % 10 - 5;
            masadd[i][j] = mas[i][j];
            printf("%d ", mas[i][j]);
        }
        printf("\n");
    }
}


int inputmas(int n, int m, int mas[100][100], int masadd[100][100]) {
    int check = 0;
    printf("\nEnter array elements\n");
    for (int i = 1; i <= n; i++) {
        printf("\nEnter %d elements of the %dth string \n", m, i);
        for (int j = 1; j <= m; j++) {
            printf("mas[%d][%d] =", i, j);
            check = scanf("%d", &mas[i][j]);
            mas[i][j] = inputcheck_num(mas[i][j], check);

            masadd[i][j] = mas[i][j];
        }
    }
    return mas[100][100];
}


int sortstring(int n, int m, int masadd[100][100], int dp) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = j; k <= m; k++) {
                if (masadd[i][j] > masadd[i][k]) {
                    dp = masadd[i][j];
                    masadd[i][j] = masadd[i][k];
                    masadd[i][k] = dp;
                }
            }
        }
    }
    return dp;
    return masadd[100][100];
}


int sameamount(int n, int m, int dp, int masadd[100][100], int amountmas[100]) {
    for (int i = 1; i <= n; i++) {
        int amount = 1;
        int amountmax = 1;
        for (int j = 1; j <= m - 1; j++) {
            dp = masadd[i][j];
            if (dp == masadd[i][j + 1])
                amount++;
            else
                amount = 1;
            if (amountmax < amount)
                amountmax = amount;
        }
        amountmas[i] = amountmax;
    }
    return amountmas[100];
}


int negative_element(int n, int m, int mas[100][100]) {
    int ans = 0;
    int fl = 0;
    for (int i = 1; i <= n; i++) {
        fl = 0;
        for (int j = 1; j <= m; j++) {
            if (mas[j][i] < 0) {
                fl = 1;
            }
        }
        if (fl == 0) {
            ans = i;
            break;
        }

    }
    return ans;
}


int main()
{
    int masadd[100][100]{ 0 }, mas2[100][100]{ 0 }, mas[100][100]{ 0 }, amountmas[100]{ 0 }, dopmas[100]{ 0 };
    int check = 0, answer = 0, n = 0, m = 0, dp = 0;
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
        inputmas(n, m, mas, masadd);
    else
        inputrandom(n, m, mas, masadd);


    sortstring(n, m, masadd, dp);

    sameamount(n, m, dp, masadd, amountmas);


    int  min_i = 0;
    long min;
    printf("\nthe array is sorted in ascending order of the same elements in the string\n");
    for (int i = 1; i <= n; i++) {
        min = n + m;
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= m; k++) {
                if (min > amountmas[k]) {
                    min = amountmas[k];
                    min_i = k;
                }
            }
            for (int k = 0; k <= m; k++)
                dopmas[k] = mas[min_i][k];
            mas2[i][j] = dopmas[j];
            printf("%d ", mas2[i][j]);
        }
        amountmas[min_i] = n + m;
        printf("\n");
    }



    answer = negative_element(n, m, mas);


    if (answer == 0)
        printf("\nThere is no columns without negative element in this array\n\n");
    else
        printf("\nThe first column without a negative element has a number %d\n\n", answer);
    return 0;
}