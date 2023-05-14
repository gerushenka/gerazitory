#include "clear_word.h"
extern int fl;

void clear_word(char** word) {
    int j = 0;
    for (int i = 0; (*word)[i] != '\0'; i++) {
        int a = ispunct((*word)[i]);
        if (a == 0 && ((*word)[i] != -85 && (*word)[i] != -69 && (*word)[i] != -123 && (*word)[i] != -124 && (*word)[i] != -109)) {
            (*word)[j] = (*word)[i];
            j++;
        }
        else {
            fl++;
        }
    }
    (*word)[j] = '\0';

}