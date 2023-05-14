#include "memory.h"
extern int words_amount;
#define MAX_WORD_SIZE 30

void free_mem(Stack* s) {

    for (int i = 0; i < words_amount; i++) {
        free(s->word[i]);
    }
    free(s->word);
    free(s->freq);
}
void alloc_memory(Stack* s) {
    s->word = (char**)calloc(words_amount, sizeof(char*));
    s->freq = (int*)calloc(words_amount, sizeof(int));
    for (int i = 0; i < words_amount; i++) {
        s->word[i] = (char*)calloc(MAX_WORD_SIZE, sizeof(char));
    }
}
