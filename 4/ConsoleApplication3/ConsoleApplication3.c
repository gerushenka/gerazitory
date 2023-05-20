#include "Header.h"

int main() {
    setlocale(LC_ALL, "russian");
    FILE* log = fopen("logs.log", "w");
    Node* root = NULL;
    FILE* file = NULL;
    char buffer[MAX_SIZE];
    int correct = 0;
    int playAgain = 1;
    int save = 0;

    file = fopen("database.txt", "r");
    if (file != NULL) {
        root = loadTree(file);
        fclose(file);
    }
    else {
        root = createNode("It is cumputer game?", NULL, NULL);
        root->yes = createNode("counter strike?", NULL, NULL);
        root->no = createNode("clash of clans?", NULL, NULL);
    }
    while (playAgain) {
        Node* node = root;

        toList(log, &node);


        isRight(log, &node, &correct, &save, &root);


        playAgain(log, &correct, &playAgain);

    }
    if (save) {
        FILE* fp = fopen("database.txt", "w");
        if (fp == NULL) {
            printf("Eror : file cannot be open\n");
            exit(1);
        }
        saveTree(root, fp);
        fclose(fp);
        printf("Tree saved in database.txt\n");
    }
    fclose(log);
    return 0;
}