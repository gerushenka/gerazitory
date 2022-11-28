#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

#define scanf scanf_s


void merge_sort(int* mas, int l, int r) {
	int p1 = 0, p2 = 0, mid = (l + r) / 2, pos = 0;
	int* b = NULL;
	b = (int*)malloc(r * sizeof(int));
	int i = 0;
	while (p1 + l <= mid && mid + p2 + 1 <= r) {
		while (l + p1 <= mid && mas[l + p1] % 2 == 1) {
			p1++;
		}
		while (mid + 1 + p2 <= r && mas[mid + 1 + p2] % 2 == 1) {
			p2++;
		}
		if (p1 > mid || mid + 1 + p2 > r) break;
		
		if (mas[p1 + l] < mas[mid + 1 + p2]) {
			b[i] = (mas[p1 + l]);
			i++;
			p1++;
		}
		else {
			b[i] = (mas[mid + 1 + p2]);
			i++;
			p2++;
		}
	}
	while (p1 + l <= mid) {
		if (mas[p1 + l] % 2 == 0) {
			b[i] = (mas[p1 + l]);
			i++;
		}
		p1++;
	}
	while (mid + 1 + p2 <= r) {
		if (mas[mid + 1 + p2] % 2 == 0) {
			b[i] = (mas[mid + 1 + p2]);
			i++;
		}
		p2++;
	}
	pos = 0;
	for (int i = l; i <= r; i++) {
		if (mas[i] % 2 == 0) {
			mas[i] = b[pos];
			pos++;
		}
	}
	free(b);
}


void merge(int* mas, int left, int right) {
	if (left == right)return;
	int mid = (left + right) / 2;
	merge(mas, left, mid);
	merge(mas, mid + 1, right);
	merge_sort(mas, left, right);
}

int checkinput(int a, int m, int z) {
	while (scanf("%d", &a) != 1 || getchar() != '\n' || a < m || a > z) {
		printf("Pls enter a NUMBER between %d to %d\n", m, z);
		rewind(stdin);
	}
	return a;
}

void outputmas(int* mas, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d\t", mas[i]);
	}
}


void buble(int* mas, int n) {
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (mas[i] % 2 != 0) {
			i++;
		}
		for (int j = i + 1; j < n; j++) {
			while (mas[j] % 2 != 0) {
				j++;
			}
			if (mas[i] > mas[j]) {
				int temp = mas[i];
				mas[i] = mas[j];
				mas[j] = temp;
			}
		}
	}
}


int main() {

	
	int* mas = NULL;
	int n = 0;
	printf("Enter number of elements in array ");
	n = checkinput(n, 0, INT_MAX);
	mas = (int*)malloc(n * sizeof(int));
	//for (int i = 0; i < n; i++) {
		//printf("mas[%d] = ", i);
		//mas[i] = checkinput(mas[i], INT_MIN, INT_MAX);
	//}
	int k = 0;
	for (int i = n - 1; i >= 0; i--) {
		mas[k] = i;
		k++;
	}
	printf("\nYour array\n");
	//outputmas(mas, n);
	clock_t start = clock();;
	merge(mas, 0, n - 1);
	clock_t end = clock();
	printf("\n\n\n\nArray with sorted even elements\n");
	//outputmas(mas, n);
	float seconds = (float)(end - start) / CLOCKS_PER_SEC;
	printf("\n\n\nMerge sort sorts the given array by %f seconds", seconds);
	k = 0;
	for (int i = n - 1; i >= 0; i--) {
		mas[k] = i;
		k++;
	}
	clock_t start2 = clock();
	buble(mas,n);
	clock_t end2 = clock();
	float seconds2 = (float)(end2 - start2) / CLOCKS_PER_SEC;
	printf("\n\n\nBuble sort sorts the given array by %f seconds\n\n\n", seconds2);
	free(mas);
	return 0;
}

