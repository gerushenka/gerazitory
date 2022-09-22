#include <stdio.h>
#define scanf scanf_s
int main()
{
    int max = 0, amount = 0, min = 0, n = 0;
    int mas[1000]{ 0 };
    printf("Enter the number of array elements\n");
    scanf("%d", &n);
    printf("Enter array elements\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &mas[i]);
        if (i == 1) { max = mas[i]; }
        if (max < mas[i]) {
            max = mas[i];
        }
    }
    min = max;
    for (int i = 1; i <= n; i++) {
        if (min > mas[i]) {
            amount++;
            min = mas[i];
        }
        if (amount < 4) {
            min = max;
        }
    }
    printf("the fourth minimal element is %d", min);
    return 0;
}