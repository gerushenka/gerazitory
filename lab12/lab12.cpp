#include <stdio.h>

int main()
{
    double a = 0;
    double b = 0; 
    double c = 0;
    printf("Enter the first side ");
    scanf_s("%lf", &a);
    printf("Enter the second side ");
    scanf_s("%lf", &b);
    printf("Enter the third side ");
    scanf_s("%lf", &c);
    if (a == b) {
        printf("\nThe triangle is isosceles");
        return 0;
    }
    if (a == c) {
        printf("\nThe triangle is isosceles");
        return 0;
    }
    if (c == b) {
        printf("\nThe triangle is isosceles");
        return 0;
    }
    printf("\nthe triangle isn't isosceles");
    return 0;


}
