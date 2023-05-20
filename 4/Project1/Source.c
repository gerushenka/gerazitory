#include "Header.h"

Node* createNode(char* data, Node* yes, Node* no) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->yes = yes;
    node->no = no;
    return node;
}

void clearTree(Node* node) {
    if (node != NULL) {
        clearTree(node->yes);
        clearTree(node->no);
        free(node->data);
        free(node);
    }
}

void saveTree(Node* node, FILE* file) {
    if (node == NULL) {
        fprintf(file, "N\n");
    }
    else {
        fprintf(file, "%s\n", node->data);
        saveTree(node->yes, file);
        saveTree(node->no, file);
    }
}

Node* loadTree(FILE* file) {
    char buffer[MAX_SIZE];
    fgets(buffer, MAX_SIZE, file);
    if (buffer[0] == 'N') {
        return NULL;
    }
    else {
        char* data = (char*)malloc(strlen(buffer));
        strcpy(data, buffer);
        data[strlen(data) - 1] = '\0';
        Node* node = createNode(data, NULL, NULL);
        node->yes = loadTree(file);
        node->no = loadTree(file);
        return node;
    }
}
void toList(FILE* log, Node** node) {
    char buffer[MAX_SIZE];
    while ((*node)->yes != NULL && (*node)->no != NULL) {
        printf("%s\n", (*node)->data);
        while (1) {
            fgets(buffer, MAX_SIZE, stdin);
            buffer[strlen(buffer) - 1] = '\0';
            logging(2, log, buffer, (*node)->data);
            if (strcmp(buffer, "yes") == 0) {
                *node = (*node)->yes;
                break;
            }
            if (strcmp(buffer, "no") == 0) {
                *node = (*node)->no;
                break;
            }
            printf("Enter yes or no\n");
        }
    }
}

void createBranch(char* answer, char* question, char* guess, Node** node, Node** root) {
    Node* newAnswer = createNode(guess, NULL, NULL);
    Node* newQuestion = createNode(question, NULL, NULL);
    if (strcmp(answer, "yes") == 0) {
        newQuestion->yes = newAnswer;
        newQuestion->no = *node;
    }
    else {
        newQuestion->no = newAnswer;
        newQuestion->yes = *node;
    }
    if (*node == *root) {
        *root = newQuestion;
    }
    else {
        Node* parent = *root;
        if (parent->yes != (*node) && parent->no != (*node)) {
            if (parent->yes != NULL) {
                parent = parent->yes;
            }
            else {
                parent = parent->no;
            }
        }
        if (parent->yes == *node) {
            parent->yes = newQuestion;
        }
        else {
            parent->no = newQuestion;
        }
    }
}

void newBranch(FILE* log, Node** node, int* save, Node** root) {
    char* question = NULL;
    char* answer = NULL;
    char* guess = NULL;
    char buffer[MAX_SIZE];
    printf("What is it? ");
    fgets(buffer, MAX_SIZE, stdin);
    logging(4, log, (*node)->data, buffer);
    buffer[strlen(buffer) - 1] = '\0';
    guess = (char*)malloc(strlen(buffer) + 1);
    strcpy(guess, buffer);

    printf("Enter question how %s distinguish from %s: ", guess, (*node)->data);
    fgets(buffer, MAX_SIZE, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    question = (char*)malloc(strlen(buffer) + 1);
    strcpy(question, buffer);

    printf("What %s answer for this question yes or no? ", guess);
    fgets(buffer, MAX_SIZE, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    answer = (char*)malloc(strlen(buffer) + 1);
    strcpy(answer, buffer);

    createBranch(answer, question, guess, node, root);


    (*save) = 1;
}
void isRight(FILE* log, Node** node, int* correct, int* save, Node** root) {
    char buffer[MAX_SIZE];
    printf("This is %s?\n", (*node)->data);
    while (1) {
        fgets(buffer, MAX_SIZE, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        if (strcmp(buffer, "yes") == 0) {
            logging(3, log, buffer, (*node)->data);
            printf("I'm right\n");
            (*correct) = 1;
            break;
        }
        if (strcmp(buffer, "no") == 0) {
            newBranch(log, node, save, root);
            break;
        }
        printf("Enter yes or no\n");
    }
}


void playAgain(FILE* log, int* correct, int* playAgain) {
    char buffer[MAX_SIZE];
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
    printf("\n\nDo u want to play again?\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    fgets(buffer, MAX_SIZE, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    if (strcmp(buffer, "yes") == 0) {
        *playAgain = 1;
        *correct = 0;
        system("cls");
        logging(1, log, "", "");
    }
    else {
        logging(0, log, "", "");
        *playAgain = 0;
    }
}

void logging(int playagain, FILE* f, char* s, char* s1) {
    time_t now = time(NULL);
    struct tm *time_now;
    time(&now);
    time_now= localtime(&now);
    char* time_s[80];
    strftime(time_s, TIME_SIZE, "%Y-%m-%d %H:%M:%S", time_now);
    if (strcmp(s, "yes") == 0 || strcmp(s, "no") == 0) {
        fprintf(f, "%s Q: %s, A:%s\n",time_s, s1, s);
    }
        if (playagain == 3)
        fprintf(f, "%s Computer Right it is %s", time_s, s1);
        if (playagain == 4)
            fprintf(f, "%s\nComputer wasn't Right user guessed %s", time_s, s1);
    if (playagain == 1) {
        fprintf(f, "%s User continiue program", time_s);
    }
    if (playagain == 0){
        fprintf(f, "\n%s User end program", time_s);

    }
}