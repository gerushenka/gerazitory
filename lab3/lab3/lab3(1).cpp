#include <stdio.h>
#define scanf scanf_s
int main()
{
	double mas[1000]{ 0 };
	double mini = 0, min= 0, sum = 1, sum2 = 0;
	int fl = 0, n = 0;
	printf("Enter the number of array elements\n");
	scanf("%d", &n);
	printf("Enter array elements\n");
	for (int i = 1; i <= n; i++) {
		scanf("%lf", &mas[i]);
		if (i == 1) { min = mas[i]; mini = i; }
		if (mas[i] > 0) {
			fl++;
			sum *= mas[i];
		}
		if (min > mas[i]) {
			min = mas[i];
			mini = i;
		}
	}
	for (int i = 1; i <= mini; i++) {
		sum2 += mas[i];
	}
	if (fl > 0)
		printf("the product of the positive elements of the array is %lf\n", sum);
	else
		printf("there are no positive elements in this array\n");

		printf("sum of array elements from first to minimum element is % lf", sum2);

		return 0;
}