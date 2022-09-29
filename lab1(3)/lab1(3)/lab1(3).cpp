#include <stdio.h>
#include <math.h>
int main()
{
	const double pi = 3.1415, koren2 = 1.4142;
	double  k = 0, S1 = 0, S2 = 0;
	double 	a = 0, r = 0, d = 0;
	printf("Enter area of circle ");
	scanf_s("%lf", &S1);
	printf("Enter square area ");
	scanf_s("%lf", &S2);
	r = sqrt(S1 / pi);
	a = sqrt(S2);
	d = a * koren2;
	if (r * 2 == a) {
		printf("\na circle can be inscribed in a square");
		k++;
	}
	if (r * 2 == d) {
		printf("\na square can be inscribed in a circle");
		k++;
	}
	if (k == 0) {
		printf("\na square can't be inscribed in a circle and a circle can't be inscriibed in a square");

	}
	return 0;

}
