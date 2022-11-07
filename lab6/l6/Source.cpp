#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define scanf scanf_s


int checkinput(int a, int m, int z) {
	while (scanf("%d", &a) != 1 || getchar() != '\n' || a < m || a > z) {
		printf("Pls enter a correct number!\n");
		rewind(stdin);
	}
	return a;
}


void outputmas(int** mas, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d\t", mas[i][j]);
		}
		printf("\n");
	}
}


void swap(int& a, int& b) {
	int temp = b;
	b = a;
	a = temp;
}


void sum_st(int** sum_m, int** mas, int n, int m) {
	int k = 0;
	for (int i = 1; i < n; i += 2) {
		sum_m[k][1] = i;
		sum_m[k][2] = 0;
		for (int j = 0; j < m; j++) {
			sum_m[k][2] += mas[i][j];
		}
		k++;
	}
}

int separation(int** sum_m, int start, int end) {
	int piv = sum_m[end][2];
	int piv_ind = start;
	for (int i = start; i < end; i++) {
		if (sum_m[i][2] <= piv) {
			swap(sum_m[i][2], sum_m[piv_ind][2]);
			swap(sum_m[i][1], sum_m[piv_ind][1]);
			piv_ind++;
		}
	}
	swap(sum_m[piv_ind][2], sum_m[end][2]);
	swap(sum_m[piv_ind][1], sum_m[end][1]);

	return piv_ind;
}


void qs(int** sum_m, int start, int end) {
	if (start >= end) {
		return;
	}
	int piv_ind = separation(sum_m, start, end);
	qs(sum_m, start, piv_ind - 1);
	qs(sum_m, piv_ind + 1, end);
}


void swap_str(int** sum_m, int** mas, int n, int m) {
	int k = (n / 2) - 1;
	int** buff = NULL;
	buff = (int**)malloc((n / 2) * sizeof(int*));
	for (int i = 1; i < n; i += 2) {
		buff[i] = (int*)malloc(m * sizeof(int));
		for (int j = 0; j < m; j++) {
			buff[i][j] = mas[sum_m[k][1]][j];
		}
		k--;
	}
	if (n % 2 == 1) n--;
	for (int i = n - 1; i > 0; i -= 2) {
		for (int j = 0; j < m; j++) {
			mas[i][j] = buff[i][j];
		}
	}
}

int main()
{
	int n = 0, m = 0;
	printf("Enter number of strings in array ");
	n = checkinput(n, 0, INT_MAX);
	printf("Enter number of columns in array ");
	m = checkinput(m, 0, INT_MAX);
	int** mas = NULL;
	mas = (int**)malloc(n * sizeof(int*));
	int** sum_m;
	int n_sum = n / 2;
	sum_m = (int**)malloc(n_sum * sizeof(int*));
	for (int i = 0; i < n; i++) {
		mas[i] = (int*)malloc(m * sizeof(int));
		sum_m[i] = (int*)malloc(2 * sizeof(int));
		for (int j = 0; j < m; j++) {
			printf("mas[%d][%d] = ", i, j);
			mas[i][j] = checkinput(mas[i][j], INT_MIN, INT_MAX);
			//scanf("%d", &mas[i][j]);
		}
	}
	printf("\n\n\nYour array\n");
	outputmas(mas, n, m);


	sum_st(sum_m, mas, n, m);


	qs(sum_m, 0, n / 2 - 1);


	swap_str(sum_m, mas, n, m);

	printf("\n\n\nArray with sorted strings in descending order\n");
	outputmas(mas, n, m);
	int k = 0;
	for (int i = 0; i < n; i++) {
		free(mas[i]);
	}
	free(mas);
	getchar();
	return 0;
}
