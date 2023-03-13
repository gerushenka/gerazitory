#include <stdio.h>
#define scanf scanf_s
int main()
{
	int kolc = 0, kola = 0, kolb = 0, a = 0, A = 0, b = 0, B = 0, C = 0;
	printf("Enter a sides of the rectangle \nA = ");;
	scanf("%d", &A);
	printf("B = ");
	scanf("%d", &B);
	printf("Enter a side of the square\nC = ");
	scanf("%d", &C);
	a = A;
	while (a >= C) {
		a -= C;
		kola++;
	}
	b = B; 
	while (b >= C) {
		b -= C;
		kolb++;

	}
	for (int i = 1; i <= kolb; i++) {
		kolc += kola;
	}
	printf("There are %d squares can be placed in the rectangle\n", kolc);



}