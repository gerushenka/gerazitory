#pragma once

typedef struct {
	int top;
	char** word;
	int* freq;
}Stack;

typedef struct {
	char word[30];
	int amount;
} word_freq;


