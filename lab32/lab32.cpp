#include <stdio.h>
#include <random>
#define scanf scanf_s
int main()
{
    bool boolean = 0;
    int num = 0, mini = 0, max = 0, amount = 0, min = 0, n = 0;
    int mas[100]{ 0 };
    printf("Enter the number of array elements\n");
    boolean = scanf("%d", &n);
    while (boolean != 1 || n < 4) {
        printf("Pls try again\n");
        rewind(stdin);
        boolean = scanf("%d", &n);
    }
    printf("choose how to fill the array \n1)random\n2)keyboard input\n");
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
    max = mas[1];
    for (int i = 1; i <= n; i++) {
        if (max < mas[i]) {
            max = mas[i];
        }
    }
    while (amount != 4) {
        amount++;
        min = max;
        for (int i = 1; i <= n; i++) {
            if (min > mas[i]) {
                min = mas[i];
                mini = i;
            }
        }
        mas[mini] = max;

    }

    printf("\nthe fourth minimal element is %d", min);
    return 0;
}
