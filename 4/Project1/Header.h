#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#include <Windows.h>
#include <wincon.h>
#define TIME_SIZE 80
#define MAX_SIZE 256
typedef struct node {
    char* data;
    struct node* yes;
    struct node* no;
} Node;

Node* createNode(char* data, Node* yes, Node* no);
void clearTree(Node* node);

void saveTree(Node* node, FILE* file);

Node* loadTree(FILE* file);
void toList(FILE* log, Node** node);
void createBranch(char* answer, char* question, char* guess, Node** node, Node** root);

void newBranch(FILE* log, Node** node, int* save, Node** root);
void isRight(FILE* log, Node** node, int* correct, int* save, Node** root);

void playAgain(FILE* log, int* correct, int* playAgain);
void logging(int fl, FILE* f, char* s, char* s2);