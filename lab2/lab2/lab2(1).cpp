#include <stdio.h>
#define scanf scanf_s
int main()
{
    double sum = 0, a = 0, i = 0, n = 0;
    printf("Enter an original number ");
    scanf("%lf", &a);
    while (sum < a) {
        i++;
        sum += 1 / i;
    }
    printf("The first number that bigger than a is %.6lf\n", sum);

}

