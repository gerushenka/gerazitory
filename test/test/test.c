#include "dot.h"

int words_amount = 0;
int fl = 0;

int main() {
    setlocale(LC_ALL, "Rus");
    FILE* file;
    fopen_s(&file, "bpbp.txt", "r+");
    if (file == NULL) {
        printf("file cannot be read");
        exit(1);
    }
    word_freq* words;
    find_words(file,&words);
    Stack stack1 = { -1,0 };
    Stack stack2 = { -1,0 };
    Stack stack3 = { -1,0 };
    Stack stack4 = { -1,0 };
    alloc_memory(&stack1);
    alloc_memory(&stack2);
    alloc_memory(&stack3);
    alloc_memory(&stack4);
    sort_words(words);
    original_stack_inic(&stack1, &stack2, words);
    free(words);
    fseek(file, 0, SEEK_SET);
    compressing(file, &stack1, &stack2, &stack3, &stack4);
    free_mem(&stack1);
    free_mem(&stack2);
    free_mem(&stack3);
    free_mem(&stack4);
    fclose(file);

    return 0;
}