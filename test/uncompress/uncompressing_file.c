#include "uncompressig_file.h"
extern int words_amount;
extern int fl;

void uncompressing(words* word, FILE* comp) {
	char* word_c = (char*)calloc(30, sizeof(char));
	char s[10000];
	FILE* uncomp;
	fopen_s(&uncomp, "uncompressed.txt", "wt+");
	while (!feof(comp)) {
		fgets(s, 10000, comp);
		int i = 0;
		int end = 0;
		int letter = 0;
		int flag = 0;
		int str_len = strlen(s);
		while (s[i] != '\n' && s[i] != '\0') {
			word_c[letter] = s[i];

			flag = 0;
			if (s[i + 1] == ' ' || s[i + 1] == '\n') {
				letter = -1;
				fl = 0;
				clear_word(&word_c);
				if (fl >= 1) {
					i -= fl;
				}
				int len_c = strlen(word_c);
				for (int j = 0; j < words_amount; j++) {
					if (j == 485) {
						int a = 0;
					}
					if (strcmp(word_c, word[j].A) == 0) {
						strcpy(word_c, word[j].B);
						flag++;
						int  len1 = strlen(word_c);
						for (int y = 0; y < len1; y++) {
							s[i - len_c + y + 1] = word_c[y];
						}
						str_len = str_len - len_c + len1;
						for (int y = i - (len_c - len1) + 1; y < str_len; y++) {
							s[y] = s[y + len_c - len1];
						}
						i = i - len_c + len1 + 1;
						end = j + 1;
						word_c = (char*)calloc(30, sizeof(char));
						break;
					}
					else

						if (strcmp(word_c, word[j].B) == 0) {
							flag++;
							strcpy(word_c, word[j].A);
							int  len1 = strlen(word_c);
							str_len = str_len + len1 - len_c;
							s[str_len] = '\0';
							for (int y = str_len - 1; y > i + len1 - len_c; y--) {
								s[y] = s[y - len1 + len_c];
							}
							for (int y = 0; y < len1; y++) {
								s[i - len_c + y + 1] = word_c[y];
							}
							i = i + len1 - len_c + 1;
							end = j + 1;
							word_c = (char*)calloc(30, sizeof(char));
							break;
						}
					end = j + 1;
				}
				if (flag == 0) {
					word_c = (char*)calloc(30, sizeof(char));
					i++;
				}
			}
			i++;
			letter++;

		}
		s[str_len] = '\0';
		fputs(s, uncomp);
	}
	free(word_c);

}
