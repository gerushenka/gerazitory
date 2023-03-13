#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "arrays.h"
#include <time.h>


#define scanf scanf_s


int checkinput(int a, int m, int z) {
	while (scanf("%d", &a) != 1 || getchar() != '\n' || a < m || a > z) {
		printf("Pls enter a correct number!\n");
		rewind(stdin);
	}
	return a;
}

int main()
{
	int** mas = NULL;
	int  n = 0;
	int* mstring = NULL;
	printf("Enter number of strings in array ");
	n = checkinput(n, 0, INT_MAX);
	mstring = (int*)malloc( n * sizeof(int));
	mas = (int**)malloc(n * sizeof(int*));
	printf("\nEnter array elements\n");

	for (int i = 0; i < n; i++) {
		int a = 1, j = 1;
		mas[i] = (int*)malloc(j*sizeof(int));
		while (a != 0) {
			mas[i] = (int*)realloc(mas[i],j*sizeof(int));
			printf("mas[%d][%d] = ", i, j);
			mas[i][j-1] = checkinput(mas[i][j-1], INT_MIN, INT_MAX);
			a = mas[i][j - 1];
			j++;
		}
		j--;
		mstring[i] = j;
	}

	printf("\nYour array\n");
	outputmass(mas, n, mstring);
	printf("\nEnter K\n");
	int K = 0;
	K = checkinput(K, INT_MIN, INT_MAX);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < mstring[i]; j++) {
			if (mas[i][j] > K) {
				same_el_del(mas[i][j], mas, n, mstring);
			}
		}
		mas[i] = (int*)realloc(mas[i], mstring[i] * sizeof(int));
	}

	printf("\n\nNew array without same elements\n\n");
	outputmass(mas, n, mstring);
	for (int i = 0; i < n; i++) {
		free(mas[i]);
	}
	free(mas);
	free(mstring);
	return 0;
}