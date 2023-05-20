#include "sort.h"

extern int words_amount;

int compare_word_freq(const void* a, const void* b) {
    const word_freq* pa = (const word_freq*)a;
    const word_freq* pb = (const word_freq*)b;

    if (pa->amount < pb->amount) {
        return -1;
    }
    else if (pa->amount > pb->amount) {
        return 1;
    }

    if (strnlen_S(pa->word, MAX_LEN) < strnlen_s(pb->word, MAX_LEN)) {
        return -1;
    }
    else if (strnlen_s(pa->word, MAX_LEN) > strnlen_s(pb->word, MAX_LEN)) {
        return 1;
    }

    return 0;
}

void sort_words(word_freq* words) {
    qsort(words, words_amount, sizeof(word_freq), compare_word_freq);
}