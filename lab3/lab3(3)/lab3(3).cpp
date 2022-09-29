#include <stdio.h>
#include <random>
#define scanf scanf_s
int main()
{
    bool boolean = 0;
    int mas[100]{ 0 }, mas2[100]{ 0 };
    int num = 0, n = 0, k = 0;
    long max = -500000;
    printf("Enter the number of the first array elements\n");
    boolean = scanf("%d", &n);
    while (boolean != 1) {
        printf("Pls try again\n");
        rewind(stdin);
        boolean = scanf("%d", &n);
    }
    printf("choose how to fill the first array \n1)random\n2)keyboard input\n");
    scanf("%d", &num);
    printf("\n");
    switch (num) {

    case 2:
        printf("Enter array elements\n");
        for (int i = 1; i <= n; i++) {
            printf("Enter the %dth element ", i);
            boolean = scanf("%d", &mas[i]);
            while (boolean != 1) {
                printf("Pls try again\n");
                rewind(stdin);
                boolean = scanf("%d", &mas[i]);
            }
        }
        break;
    case 1:
        for (int i = 1; i <= n; i++) {
            mas[i] = (rand() % n * 2) - n;
            printf("the %dth element of array is %d\n", i, mas[i]);
        }
        break;
    }


    printf("\nEnter the number of the second array elements\n");
    boolean = scanf("%d", &k);
    while (boolean != 1) {
        printf("Pls try again\n");
        rewind(stdin);
        boolean = scanf("%d", &k);
    }
    printf("choose how to fill the array \n1)random\n2)keyboard input\n");
    scanf("%d", &num);
    printf("\n");
    switch (num) {

    case 2:
        printf("Enter array elements\n");
        for (int i = 1; i <= n; i++) {
            printf("Enter the %dth element ", i);
            boolean = scanf("%d", &mas2[i]);
            while (boolean != 1) {
                printf("Pls try again\n");
                rewind(stdin);
                boolean = scanf("%d", &mas2[i]);
            }
        }
        break;
    case 1:
        for (int i = 1; i <= n; i++) {
            mas2[i] = (rand() % n * 2) - n;
            printf("the %dth element of array is %d\n", i, mas2[i]);
        }
        break;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (mas[i] == mas2[j]) {
                mas[i] = 0;
                break;
            }

        }
    }
    max = mas[1];
    for (int i = 1; i <= n; i++) {
        if (max < mas[i]) {
            max = mas[i];
        }
    }
    printf("\nmaximum element from the first array which is not in the second array is %d", max);

    return 0;
}
