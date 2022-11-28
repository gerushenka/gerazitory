#include <stdio.h>
#include <random>
#define scanf scanf_s
int main()
{
	bool boolean = 0;
	double mas[100]{ 0 };
	double mini = 0, min = 0, prod = 1, sum = 0;
	int num = 0, fl = 0, n = 0;

	printf("Enter the number of array elements\n");
	boolean = scanf("%d", &n);
	while (boolean != 1) {
		printf("Pls try again\n");
		rewind(stdin);
		boolean = scanf("%d", &n);
	}
	printf("choose how to fill the array \n1)random\n2)keyboard input\n");
	scanf("%d", &num);
	printf("\n");
	switch (num) {

	case 2:
		printf("Enter array elements\n");
		for (int i = 1; i <= n; i++) {
			printf("Enter the %dth element ", i);
			boolean = scanf("%lf", &mas[i]);
			while (boolean != 1) {
				printf("Pls try again\n");
				rewind(stdin);
				boolean = scanf("%lf", &mas[i]);
			}
		}
		break;
	case 1:
		for (int i = 1; i <= n; i++) {
			mas[i] = (rand() % n * 2) - n;
			printf("the %dth element of array is %.2lf\n", i, mas[i]);
		}
		break;
	}
	min = mas[1];
	mini = 1;
	for (int i = 1; i <= n; i++) {
		if (i == 1) {}
		if (mas[i] > 0) {
			fl++;
			prod *= mas[i];
		}
		if (min > mas[i]) {
			min = mas[i];
			mini = i;
		}
	}
	for (int i = 1; i < mini; i++) {
		sum += mas[i];
	}
	if (fl > 0)
		printf("\nthe product of the positive elements of the array is %.2lf\n", prod);
	else
		printf("\nthere are no positive elements in this array\n");

	printf("sum of array elements from first to minimum element is %.2lf\n\n", sum);

	return 0;
}
