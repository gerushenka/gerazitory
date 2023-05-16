#include "stack_actions.h"
extern int words_amount;

int is_empty(Stack* s) {
    return s->top == -1;
}

int is_full(Stack* s) {
    return s->top == words_amount - 1;
}

void push(Stack** s, char** word) {
    if (is_full(*s)) {
        printf("Стек полон\n");
    }
    else {
        (*s)->top++;
        strcpy_s((*s)->word[(*s)->top], 1024, word);
    }
}

void pop(Stack** s) {
    if (is_empty(*s)) {
        printf("Стек пуст\n");
        return;
    }
    else {
        strcpy_s((*s)->word[(*s)->top], 1024, "0");
        (*s)->top--;
    }
}

void transf(Stack* from, Stack* to) {
    if (is_empty(from)) {
        printf("Стек для переноса пуст\n");
    }
    else if (is_full(to)) {
        printf("Стек, в который нужно перенести элементы, полон\n");
    }
    else {
        push(to, from->word[from->top]);
        pop(from);
    }
}

void original_stack_inic(Stack* s1, Stack* s2, word_freq* words) {
    int up = words_amount - 1;
    int down = 0;
    while (up != 0 && down != words_amount) {
        if (wcslen(words[down].word) >= 5) {
            push(s1, words[down].word);
            s1->freq[s1->top] = words[down].amount;
        }
        if (wcslen(words[up].word) < 5) {
            push(s2, words[up].word);
            s2->freq[s2->top] = words[up].amount;
        }
        up--;
        down++;
    }
}