#include "sort.h"
extern int words_amount;
int compare(const void* a, const void* b) {
    word_freq* pa = (word_freq*)a;
    word_freq* pb = (word_freq*)b;
    if (pa->amount < pb->amount) {
        return -1;
    }
    else if (pa->amount > pb->amount) {
        return 1;
    }
    if (strlen(pa->word) < strlen(pb->word)) {
        return -1;
    }
    else if (strlen(pa->word) > strlen(pb->word)) {
        return 1;
    }
}

void sort_words(word_freq* words) {

    qsort(words, words_amount, sizeof(word_freq), (int (*)(const void*, const void*)) compare);

}