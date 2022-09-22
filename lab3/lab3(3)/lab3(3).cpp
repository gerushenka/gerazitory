#include <stdio.h>
#define scanf scanf_s
int main()
{
    int mas[1000]{ 0 }, mas2[1000]{ 0 };
    int max = 0, n = 0, k = 0;
    printf("Enter the number of the first array elements\n");
    scanf("%d", &n);
    printf("Enter the first array elements\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &mas[i]);
    }
    printf("Enter the number of the second array elements\n");
    scanf("%d", &k);
    printf("Enter the second array elements\n");
    for (int i = 1; i <= k; i++) {
        scanf("%d", &mas2[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (mas[i] == mas2[j]) {
                mas[i] = 0;
                break;
            }

        }
    }
    for (int i = 1; i <= n; i++) {
        if (i == 1) { max = mas[i]; }
        if (max < mas[i]) {
            max = mas[i];
        }
    }
    printf("\nmaximum element from the first array which is not in the second array is %d", max);

    return 0;
}
