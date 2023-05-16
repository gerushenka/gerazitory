#include "compress_file.h"
extern int fl;
extern int words_amount;
void short_long_word(Stack* s1, Stack* s2, char** word, int s_len, int* end, char** s, int i, int num) {
    Stack s4 = {-1, 0};
    int flag = 0;
    Stack s3 = { -1,0 };
    alloc_memory(&s3);
    alloc_memory(&s4);
    int len = wcslen(*word);
    for (int j = 0; j < num; j++) {
        push(&s3, &(s1->word[s1->top]));
        push(&s4, &(s2->word[s2->top]));
        pop(&s1);
        pop(&s2);
        if (strcmp(*word, s3.word[s3.top]) == 0) {
            flag++;
            strcpy_s(*word, 1024, s4.word[s4.top]);
            int  len1 = wcslen(*word);
            for (int y = 0; y < len1; y++) {
                (*s)[i - len + y + 1] = (*word)[y];
            }
            s_len = s_len - len + len1;
            for (int y = i - (len - len1) + 1; y < s_len; y++) {
                (*s)[y] = (*s)[y + len - len1];
            }
            i = i - len + len1 + 1;
            *end = j + 1;
            *word = (char*)calloc(30, sizeof(char));
            break;
        }
        else
        {
            if (strcmp(*word, s4.word[s4.top]) == 0) {
                flag++;
                strcpy_s(*word, 1024, s3.word[s3.top]);
                int  len1 = wcslen(*word);
                s_len = s_len + len1 - len;
                (*s)[s_len] = '\0';
                for (int y = s_len - 1; y > i + len1 - len; y--) {
                    (*s)[y] = (*s)[y - len1 + len];
                }
                for (int y = 0; y < len1; y++) {
                    (*s)[i - len + y + 1] = (*word)[y];
                }
                i = i + len1 - len + 1;
                *end = j + 1;
                *word = (char*)calloc(30, sizeof(char));
                break;
            }
        }
        *end = j + 1;
    }
    for (int j = 0; j < end; j++) {
        push(&s1, s3.word[s3.top]);
        push(&s2, s4.word[s4.top]);
        pop(&s3);
        pop(&s4);
        // printf("%d\n", j);
    }
    if (flag == 0) {
        *word = (char*)calloc(30, sizeof(char));
        i++;
    }
    free_mem(&s3);
    free_mem(&s4);
}
void compressing(FILE* file, Stack* s1, Stack* s2) {
    char s[10000];
    FILE* comp;
    fopen_s(&comp, "compressed.txt", "wt+");
    int top_1 = s1->top;
    int top_2 = s2->top;
    while (s1->freq[top_1] > s2->freq[top_2]) {
        fprintf(comp, "%s", s1->word[top_1]);
        fprintf(comp, " %s\n", s2->word[top_2]);
        top_1--;
        top_2--;
    }
    int num = s1->top - top_1;

    while (!feof(file)) {
        fgets(s, 9999, file);
        int i = 0;
        char* word = (char*)calloc(30, sizeof(char));
        int s_len = wcslen(s);
        int letter = 0;
        int end = 0;
        while (s[i] != '\n' && s[i] != '\0') {
            word[letter] = s[i];
            if (s[i + 1] == ' ' || s[i + 1] == '\n') {

                letter = -1;
                fl = 0;
                clear_word(&word);
                if (fl >= 1) {
                    i -= fl;
                }
                short_long_word(s1,s2, &word, s_len, &end, &s, i, num);


            }

            letter++;
            i++;
        }
        s[s_len] = '\0';
        fputs(s, comp);
        free(word);
    }
    fclose(comp);
}