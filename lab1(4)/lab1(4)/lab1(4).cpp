#include <stdio.h>

int main()
{
    int number = 0;
    double decim = -1, m = -1, kilom = -1, santim = -1, milim = -1;
    printf("choose the unit of measure\n1.decimeter\n2.santimeter\n3.meter\n4.kilometer\n5.milimeter\n");
    scanf_s("%d", &number);
    switch (number) {
    case 1:
        printf("Enter the number of decimeters ");
        scanf_s("%d", &decim);
        m = decim / 10;
        printf("\n%.2lf decimeters is %.2lf meters", decim, m);
        break;
    case 2:
        printf("Enter the number of santimeters ");
        scanf_s("%lf", &santim);
        m = santim / 100;
        printf("\n%.2lf santimeters is %.2lf meters", santim, m);
        break;
    case 3:
        printf("Enter the number of meters ");
        scanf_s("%lf", &m);
        printf("\n%.2lf meters is %.2lf meters", m, m);
        break;
    case 4:
        printf("Enter the number of kilometers ");
        scanf_s("%lf", &kilom);
        m = kilom * 1000;
        printf("\n%.2lf kilometers is %.2lf meters", kilom, m);
        break;
    case 5:
        printf("Enter the number of milimeters ");
        scanf_s("%lf", &milim);
        m = milim / 1000;
        printf("\n%.2lf milimeters is %.2lf meters", milim, m);
        break;
    }





    return 0;

}

