#include "words_to_replace.h"
extern int words_amount;

void replacement_words(words** word, FILE* comp) {
	int amount = 0;
	int letter = 0;
	int max = 100;
	char* word_c = (char*)calloc(30, sizeof(char));
	char s[100];
	while (amount != 3) {
		fgets(s, 100, comp);
		amount = 0;
		for (int i = 0; i < strlen(s); i++) {
			word_c[letter] = s[i];
			letter++;
			if (s[i + 1] == ' ' || s[i + 1] == '\n') {
				amount++;
				letter = 0;
				if (amount == 1) {
					strcpy((*word)[words_amount].A, word_c);
				}
				if (amount == 2) {
					strcpy((*word)[words_amount].B, word_c);
					words_amount++;
				}
				word_c = (char*)calloc(30, sizeof(char));
				i++;
			}
		}

	}
	fseek(comp, (-1) * strlen(s) - 1, SEEK_CUR);
	words_amount--;
}