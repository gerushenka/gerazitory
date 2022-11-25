#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


void check_input(int *n, int min, int max) {
    while (scanf_s("%d", &(*n)) != 1 || (*n) < min || (*n) > max || getchar() != '\n') {
        rewind(stdin);
        printf("Pls enter number between %d to %d", min, max);
    }
}


void str_length(char* str, int* length) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
        (*length)++;
    }
}


void count_even(char* str, int *amount_even, int length) {
    int amount = 1;
    for (int i = 0; i < length; i++) {
        amount++;
        if ((str[i + 1] == ' ') || (str[i + 1] == '\0')) {
            if ((amount - 1) % 2 == 0)
                (*amount_even)++;
            amount = 0;
        }
    }
}

void input_string(char** string)
{
    int char_;
    int i = 0;
    rewind(stdin);
    while ((char_ = getchar()) != EOF && char_ != '\n')
    {
        (*string)[i++] = char_;
        (*string) = (char*)realloc((*string), (i + 1) * sizeof(char));
    }
    (*string)[i] = '\0';
}

void include_substr(char* str, char* str_0, int length, int length_0, int* pos, int *y) {
    unsigned long long* hash1 = NULL;
    hash1 = (unsigned long long*)calloc(length+1, sizeof(unsigned long long));
    hash1[0] = 0;
    unsigned long long pp = 29, p = 1;
    unsigned long long MOD = ULLONG_MAX;
    for (int i = 1; i <= length; i++) {
        hash1[i] = hash1[i - 1] + p * str[i - 1] % MOD;
        p *= pp;
    }
    unsigned long long* hash2 = NULL;
    hash2 = (unsigned long long*)calloc(length_0+1, sizeof(unsigned long long));
    p = 1;
    hash2[0] = 0;
    for (int i = 1; i <= length_0; i++) {
        hash2[i] = hash2[i - 1] + p * str_0[i - 1] % MOD;
        p *= pp;
    }
    p = 1;
    for (int i = 0; i <= length - length_0; i++) {
        if (hash2[length_0]*p == hash1[i + length_0] - hash1[i]) {
            (*y)++;
            pos[*y] = i;
        }
        p *= pp;
        p %= MOD;
    }
    free(hash1);
    free(hash2);

}


void merge_sort(int* mas_i, int* mas, int l, int r) {
    int p1 = 0, p2 = 0, mid = (l + r) / 2, pos = 0;
    int* b = NULL;
    int* b_i = NULL;
    b_i = (int*)calloc((r+1), sizeof(int));
    b = (int*)malloc((r+1) * sizeof(int));
    int i = 0;
    while (p1 + l <= mid && mid + p2 + 1 <= r) {
        if (p1 > mid || mid + 1 + p2 > r) break;

        if (mas[p1 + l] < mas[mid + 1 + p2]) {
            b[i] = mas[p1 + l];
            b_i[i] = mas_i[p1 + l];
            i++;
            p1++;
        }
        else {
            b[i] = mas[mid + 1 + p2];
            b_i[i] = mas_i[mid + 1 + p2];
            i++;
            p2++;
        }

    }
    while (p1 + l <= mid) {
            b[i] = mas[p1 + l];
            b_i[i] = mas_i[p1 + l];
            i++;
            p1++;
    }
    while (mid + 1 + p2 <= r) {
            b[i] = mas[mid + 1 + p2];
            b_i[i] = mas_i[mid + 1 + p2];
            i++;
            p2++;
    }
    pos = 0;
    for (int i = l; i <= r; i++) {
            mas[i] = b[pos];
            mas_i[i] = b_i[pos];
            pos++;
    }
    free(b);
}
void merge(int* mas_i, int* mas, int left, int right) {
    if (left == right)return;
    int mid = (left + right) / 2;
    merge(mas_i, mas, left, mid);
    merge(mas_i, mas, mid + 1, right);
    merge_sort(mas_i, mas, left, right);
}


void shortest_words(char** str, int* length, int n, int* min) {
    for (int i = 0; i < n; i++) {
        int k = 0;
        min[i] = 999;

        for (int j = 0; j < length[i]; j++) {
            k++;
            if (str[i][j + 1] == ' ' || str[i][j + 1] == '\0' || str[i][j + 1] == '\n') {
                if (min[i] > k) {
                    min[i] = k;
                }
                k = -1;

            }
        }
    }
}


void even_words(void) {
    int length = 0;
    char* str = (char*)calloc(1, 1);

    printf("Enter string\n");
    input_string(&str);

    str_length(str, &length);

    int amount_even = 0;

    count_even(str, &amount_even, length);
 
    printf("\nThe amount of words with even number of letters is %d", amount_even);
    free(str);
}


void inc_substring(void) {
    int length = 0;
    int length_0 = 0;
    int y = 0;
    int* pos = NULL;
    char* str = NULL;
    char* str_0 = NULL;

    str = (char*)calloc(1, 1);
    printf("Enter string\n");
    input_string(&str);

    str_0 = (char*)calloc(1, 1);
    printf("\nEnter substring\n");
    input_string(&str_0);

    str_length(str, &length);
    str_length(str_0, &length_0);

    pos = (int*)malloc(length_0 * sizeof(int));

    
    if (length_0 > length) { inc_substring(); }

    include_substr(str, str_0, length, length_0, pos, &y);
    printf("Substring occurs in a string %dth times \n", y);
    for (int i = 1; i <= y; i++) {
        printf("from %dth position to %dth position\n", pos[i], pos[i] + length_0);
    }
    free(str);
    free(str_0);
}


void sort_string(int argc, char** argv) {
    int* length = NULL;
    int* min = NULL;
    int* min_ind = NULL;
    char** str = NULL;
    int n = 0;
    printf("Enter a number of strings\n");
    scanf_s("%d", &n);
    str = (char**)calloc(n, 1 * sizeof(char*));

    printf("\nEnter strings\n");
    min = (int*)calloc(n, sizeof(int));
    min_ind = (int*)calloc(n, sizeof(int));
    length = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        min_ind[i] = i;
        str[i] = (char*)calloc(1, 1);
        printf("%d. ", i + 1);
        input_string(&str[i]);
        length[i] = 0;
        str_length(str[i], &length[i]);
    }
    shortest_words(str, length, n, min);
    merge(min_ind, min, 0, n - 1);
    //for (int i = 0; i < n; i++) {
    //    printf("%d ", min[i]);
    //}
    //printf("\n");
    //for (int i = 0; i < n; i++) {
    //    printf("%d ", min_ind[i]);
    //}
    printf("\nSorted array of strings in ascending order of the length of the shortest word in each string\n");
    for (int i = 0; i < n; i++)
        printf("%s\n", str[min_ind[i]]);
    for (int i = 0; i < n; i++) {
        free(str[i]);
    }
    free(str);
    free(min);
    free(min_ind);
    free(length);
}


choose(int n) {
    printf("What task do you want to choose\nenter 1 if first task\nenter 2 if second task\n");
    void (*function[3])(void) = { even_words, inc_substring, sort_string };
    int num = 0;
    check_input (&num, 1, 2);
    function[num - 1]();
    printf("\n\n\n\Do u want to continue\n1. yes\n2. no\n");
    int y_n = 0;
    check_input(&y_n, 1, 2);
    if (y_n == 1) {  
        choose(n);
    }
    else {
        return 0;
    }
}

int main(int argc, char** argv)
{
    int n = 0;
    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
    system("pause");
    //choose(n);
       
}
