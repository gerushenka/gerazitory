#include <stdio.h>

int main()
{
	const double pi = 3.141;
	double R=0, l=0, h=0, V, Sp, Sb;  
	printf("Enter a radius = ");
	scanf_s("%lf", &R);
	printf("\nEnter a length = ");
	scanf_s("%lf", &l);
	printf("\nEnter a height = ");
	scanf_s("%lf", &h);

	Sb = pi * R * l;
	Sp = pi * R * (R + l);
	V = pi * R * R * h * 0.333;
	printf("\nLateral surface area = %.3lf\n", Sb);
	printf("Surface area = %.3lf\n", Sp);
	printf("Volume = %.3lf", V);


	return 0;

}

