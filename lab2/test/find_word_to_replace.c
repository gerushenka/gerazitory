#include "find_word_to_replace.h"
extern int words_amount;

void find_words(FILE* file, word_freq** words) {
    int max = 1000;
    (*words) = (word_freq*)calloc(max, sizeof(word_freq));
    char* word;
    word = (char*)calloc(30, sizeof(char));
    while ((fscanf_s(file, "%s", word) == 1) && (!feof(file))) {
        clear_word(&word);
        int flag = 0;
        for (int i = 0; i < words_amount; i++) {
            if (!(strcmp(word, (*words)[i].word))) {
                flag = 1;
                (*words)[i].amount++;
                break;
            }
        }
        if (!flag) {
            strcpy_s((*words)[words_amount].word,1024, word);
            (*words)[words_amount].amount = 1;
            words_amount++;
        }
        if (words_amount % max == 0) {
            max += 1000;
            (*words) = (word_freq*)realloc((*words), max * sizeof(word_freq));
        }
    }
}

