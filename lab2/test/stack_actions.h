#pragma once
#include "dot.h"
int is_empty(Stack* s);
int is_full(Stack* s);
void push(Stack** s, char** word);
void pop(Stack** s);
void transf(Stack* from, Stack* to);
void original_stack_inic(Stack* s1, Stack* s2, word_freq* words);