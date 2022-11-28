#include <stdio.h>
#define scanf scanf_s
int main()
{
	int  n = 0, m = 0, sum = 0, Dm = 0, Dn = 0;
	printf("Enter n ");
	scanf("%d", &n);
	printf("Enter m ");
	scanf("%d", &m);
	for (int i = 1; i <= n; i++) {
		sum = 1;
		for (int j = 1; j <= i; j++) { sum *= j; }
		Dn += sum;
	}
	for (int i = 1; i <= m; i++) {
		sum = 1;
		for (int j = 1; j <= i; j++) { sum *= j; }
		Dm += sum;
	}
	printf("\nvalue D(n) = %d\nvalue D(m) = %d", Dn, Dm);


}

