#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "arrays.h"

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
	
	int n = 0, m = 0;
	printf("Enter number of strings in array ");
	n = checkinput(n, 0, INT_MAX);
	printf("Enter number of columns in array ");
	m = checkinput(m, 0, INT_MAX);


	int** mas;
	mas = (int**)malloc(n * sizeof(int*));
	printf("Enter array elements\n");
	for (int i = 0; i < n; i++) {
		mas[i] = (int*)malloc(m * sizeof(int));
	}

	for(int i = 0; i < n; i++){
		for (int j = 0; j < m; j++) {
			printf("mas[% d][% d] = ", i, j);
			mas[i][j] = checkinput(mas[i][j], INT_MIN, INT_MAX);
		}
	}
	printf("\nYour array\n");
	outputmass(mas, n ,m);

	int amount = 0; 
	for (int i = 0; i < m; i++) { 
		for (int j = 0; j < n-1; j++) {
			if ((mas[j][i] == 0) && (mas[j+1][i] == 0)) {
				m--;
				delcolumn(mas, i, m, n);
				i--;
				break;

			}

		}
	}
	printf("\n\nNew array without columns that have 2 or more consecutive zeros\n");
	outputmass(mas, n, m);
	for (int i = 0; i < n; i++)
	{
		free(mas[i]);
	}
	free(mas);
		return 0;
}
