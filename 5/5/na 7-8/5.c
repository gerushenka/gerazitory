//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <locale.h>
//
//#define MAX_LINE_LENGTH 256
//#define CACHE_SIZE 2
//
//
//typedef struct hash_node {
//    char key[MAX_LINE_LENGTH];
//    char value[MAX_LINE_LENGTH];
//    struct hash_node* next;
//} hash_node_t;
//
//typedef struct hash_table {
//    int size;
//    hash_node_t** table;
//} hash_table_t;
//
//typedef struct cache_node {
//    char key[MAX_LINE_LENGTH];
//    char value[MAX_LINE_LENGTH];
//    struct cache_node* next;
//    struct cache_node* prev;
//} cache_node_t;
//
//typedef struct cache {
//    int size;
//    int capacity;
//    cache_node_t* head;
//    cache_node_t* tail;
//} cache_t;
//
//cache_node_t* create_node(char* key, char* value) {
//    cache_node_t* new_node = (cache_node_t*)malloc(sizeof(cache_node_t));
//    strcpy(new_node->key, key);
//    strcpy(new_node->value, value);
//    new_node->next = NULL;
//    new_node->prev = NULL;
//    return new_node;
//}
//
//void add_node_to_head(cache_t* cache, cache_node_t* node) {
//    node->next = cache->head;
//    node->prev = NULL;
//    if (cache->head != NULL) {
//        cache->head->prev = node;
//    }
//    else {
//        cache->tail = node;
//    }
//    cache->head = node;
//}
//
//void remove_tail(cache_t* cache) {
//    cache_node_t* temp = cache->tail;
//    cache->tail = cache->tail->prev;
//    if (cache->tail != NULL) {
//        cache->tail->next = NULL;
//    }
//    else {
//        cache->head = NULL;
//    }
//    free(temp);
//}
//
//void add_to_cache(cache_t* cache, char* key, char* value) {
//    cache_node_t* new_node = create_node(key, value);
//    add_node_to_head(cache, new_node);
//    cache->size++;
//    if (cache->size > cache->capacity) {
//        remove_tail(cache);
//        cache->size--;
//    }
//}
//
//cache_node_t* search_cache(cache_t* cache, char* key) {
//    cache_node_t* current_node = cache->head;
//    while (current_node != NULL) {
//        if (strcmp(current_node->key, key) == 0) {
//            return current_node;
//        }
//        current_node = current_node->next;
//    }
//    return NULL;
//}
//
//void print_cache(cache_t* cache) {
//    cache_node_t* current_node = cache->head;
//    while (current_node != NULL) {
//        printf("%s %s\n", current_node->key, current_node->value);
//        current_node = current_node->next;
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "russian");
//    cache_t cache;
//    cache.size = 0;
//    cache.capacity = CACHE_SIZE;
//    cache.head = NULL;
//    cache.tail = NULL;
//
//    FILE* file = fopen("asd.txt", "r");
//    if (file == NULL) {
//        printf("Ошибка открытия файла.\n");
//        return 1;
//    }
//
//    char line[MAX_LINE_LENGTH];
//    char key[MAX_LINE_LENGTH];
//    char value[MAX_LINE_LENGTH];
//    char* token;
//    while (fgets(line, MAX_LINE_LENGTH, file)) {
//        token = strtok(line, " \n");
//        if (token != NULL) {
//            strcpy(key, token);
//            token = strtok(NULL, " \n");
//            token = strtok(NULL, " \n");
//            if (strcmp(token,"A") == 0) {
//                token = strtok(NULL, " \n");
//                strcpy(value, token);
//                add_to_cache(&cache, key, value);
//            }
//            else {
//                if (strcmp(token, "CNAME") == 0) {
//                    token = strtok(NULL, " \n");
//                    cache_node_t* node = search_cache(&cache, token);
//                    add_to_cache(&cache, key, node->value);
//
//                }
//            }
//        }
//    }
//
//    fclose(file);
//
//    char input[MAX_LINE_LENGTH];
//    cache_node_t* node;
//    while (1) {
//        printf("Введите доменное имя: ");
//        fgets(input, MAX_LINE_LENGTH, stdin);
//        input[strcspn(input, "\n")] = '\0';
//        node = search_cache(&cache, input);
//if (node != NULL) {
//    printf("IP адрес: %s\n", node->value);
//}
//else {
//    printf("Доменное имя отсутствует в кэше.\n");
//    file = fopen("asd.txt", "r");
//    if (file == NULL) {
//        printf("Ошибка открытия файла.\n");
//        return 1;
//    }
//    while (fgets(line, MAX_LINE_LENGTH, file)) {
//        token = strtok(line, " \n");
//        if (token != NULL) {
//            if (strcmp(token, input) == 0) {
//                token = strtok(NULL, " \n");
//                if (token != NULL) {
//                    strcpy(value, token);
//                    add_to_cache(&cache, input, value);
//                    printf("IP адрес: %s\n", value);
//                }
//                break;
//            }
//        }
//    }
//    fclose(file);
//}
//printf("Текущий кэш:\n");
//print_cache(&cache);
//printf("\n");
//}
//
//return 0;
//}






























#include <stdio.h>
#include <Windows.h>
#include <wincon.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_LINE_LENGTH 256
#define CACHE_SIZE 2
#define TABLE_SIZE 16

typedef struct cache_node {
    char key[MAX_LINE_LENGTH];
    char value[MAX_LINE_LENGTH];
    struct cache_node* next;
    struct cache_node* prev;
} cache_node_t;

typedef struct cache {
    int size;
    int capacity;
    cache_node_t* head;
    cache_node_t* tail;
} cache_t;

typedef struct hash_node {
    char key[MAX_LINE_LENGTH];
    char value[MAX_LINE_LENGTH];
    struct hash_node* next;
} hash_node_t;

typedef struct hash_table {
    int size;
    hash_node_t** table;
} hash_table_t;

cache_node_t* create_node(char* key, char* value) {
    cache_node_t* new_node = (cache_node_t*)malloc(sizeof(cache_node_t));
    strcpy(new_node->key, key);
    strcpy(new_node->value, value);
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

hash_node_t* create_hash_node(char* key, char* value) {
    hash_node_t* new_node = (hash_node_t*)malloc(sizeof(hash_node_t));
    strcpy(new_node->key, key);
    strcpy(new_node->value, value);
    new_node->next = NULL;
    return new_node;
}

int hash_function(char* key) {
    int hash = 0;
    for (int i = 0; i < strlen(key); i++) {
        hash += key[i];
    }
    return hash % TABLE_SIZE;
}



void add_node_to_head(cache_t* cache, cache_node_t* node) {
    node->next = cache->head;
    node->prev = NULL;
    if (cache->head != NULL) {
        cache->head->prev = node;
    }
    else {
        cache->tail = node;
    }
    cache->head = node;
}

void remove_tail(cache_t* cache) {
    cache_node_t* temp = cache->tail;
    cache->tail = cache->tail->prev;
    if (cache->tail != NULL) {
        cache->tail->next = NULL;
    }
    else {
        cache->head = NULL;
    }
    free(temp);
}

void add_to_cache(cache_t* cache, hash_table_t* hash_table, char* key, char* value) {
    cache_node_t* new_node = create_node(key, value);
    add_node_to_head(cache, new_node);
    cache->size++;
    if (cache->size > cache->capacity) {
        hash_node_t* hash_node = hash_table->table[hash_function(cache->tail->key)];
        if (strcmp(hash_node->key, cache->tail->key) == 0) {
            hash_table->table[hash_function(cache->tail->key)] = hash_node->next;
        }
        else {
            while (hash_node->next != NULL && strcmp(hash_node->next->key, cache->tail->key) != 0) {
                hash_node = hash_node->next;
            }
            if (hash_node->next != NULL) {
                hash_node_t* temp = hash_node->next;
                hash_node->next = temp->next;
                free(temp);
            }
        }
        remove_tail(cache);
        cache->size--;
    }
    hash_node_t* hash_node = hash_table->table[hash_function(key)];
    while (hash_node->next != NULL && strcmp(hash_node->next->key, key) != 0) {
        hash_node = hash_node->next;
    }
if (hash_node->next != NULL) {
    free(hash_node->next);
}
hash_node->next = create_hash_node(key, value);
hash_table->size++;
}

char* get_from_cache(cache_t* cache, hash_table_t* hash_table, char* key) {
    hash_node_t* hash_node = hash_table->table[hash_function(key)];
    while (hash_node != NULL && strcmp(hash_node->key, key) != 0) {
        hash_node = hash_node->next;
    }
    if (hash_node == NULL) {
        return NULL;
    }
    cache_node_t* cache_node = cache->head;
    while (cache_node != NULL && strcmp(cache_node->key, key) != 0) {
        cache_node = cache_node->next;
    }
    if (cache_node == NULL) {
        return NULL;
    }
    if (cache_node != cache->head) {
        if (cache_node == cache->tail) {
            cache->tail = cache_node->prev;
            cache->tail->next = NULL;
        }
        else {
            cache_node->prev->next = cache_node->next;
            cache_node->next->prev = cache_node->prev;
        }
        add_node_to_head(cache, cache_node);
    }
    return cache_node->value;
}

void mem_free(cache_t* cache, hash_table_t* hash_table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_node_t* hash_node = hash_table->table[i];
        while (hash_node != NULL) {
            hash_node_t* temp = hash_node;
            hash_node = hash_node->next;
            free(temp);
        }
    }
    free(hash_table->table);

    cache_node_t* cache_node = cache->head;
    while (cache_node != NULL) {
        cache_node_t* temp = cache_node;
        cache_node = cache_node->next;
        free(temp);
    }
}

char* get_ip_address(hash_table_t* hash_table, char* key) {
    int index = hash_function(key);
    hash_node_t* hash_node = hash_table->table[index];
    while (hash_node != NULL) {
        if (strcmp(hash_node->key, key) == 0) {
            return hash_node->value;
        }
        hash_node = hash_node->next;
    }
    return NULL;
}
//hash_node_t* hash_node = hash_table.table[hash];
//printf("%s %s\n", hash_node->value, hash_node->key);
void inicialization_hash_table(hash_table_t* hash_table, cache_t *cache) {
    FILE* file = fopen("asd.txt", "r");
    char line[MAX_LINE_LENGTH];
    char key[MAX_LINE_LENGTH];
    char value[MAX_LINE_LENGTH];
    char* token;
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        token = strtok(line, " \n");
        strcpy(key, token);
        token = strtok(NULL, " \n");
        token = strtok(NULL, " \n");
        if (strcmp(token, "A") == 0) {
            token = strtok(NULL, " \n");
            strcpy(value, token);
            hash_node_t* new_node = create_hash_node(key, value);
            int hash = hash_function(key);
            new_node->next = hash_table->table[hash];
            hash_table->table[hash] = new_node;
            hash_table->size++;
            printf("%d\n", hash);

        }
        else {
            if (strcmp(token, "CNAME") == 0) {
                token = strtok(NULL, " \n");
                char* IP = get_ip_address(hash_table, token);
                hash_node_t* new_node = create_hash_node(key, IP);
                int hash = hash_function(key);
                new_node->next = hash_table->table[hash];
                hash_table->table[hash] = new_node;
                printf("%d\n", hash);

            }
        }

    }
    fclose(file);
}

char* validation_IP() {
    char s[MAX_LINE_LENGTH];
    while (1) {
        fgets(s, MAX_LINE_LENGTH, stdin);
        int i = 0;
        int sum = 0;
        int fl = 1;
        int point = 0;
        while (s[i] != '\0') {
            if (s[i] < '0' || s[i] > '9' && s[i] != '.') {
                fl = 0;
                printf("Entered IP address contains invalid characters");
                break;
            }
            else {
                sum *= 10;
                sum += s[i] - 48;
                if (s[i+1] == '.') {
                    if (sum > 255) {
                        printf("Numbers can be only up to 255");
                        fl = 0;
                        break;
                    }
                    point++;
                    if (point > 3) {
                        printf("IP address has only 4 sets of numbers");
                        fl = 0;
                        break;
                    }
                    sum = 0;
                }
            }
            i++;
        }
        if (point < 3 && fl != 0) {
            printf("IP address has 4 sets of numbers");
            fl = 0;
            break;
        }
        if (fl == 0) {
            printf("Enter IP adress: ");
            rewind(stdin);
        }
        else {
            break;
        }
    }
    return s;
}
void add_domain_to_file(char* domain) {
    FILE* file = fopen("asd.txt", "r+");
    char s[MAX_LINE_LENGTH];
    rewind(stdin);
    printf("it is pseudonim or domain: ");
    fgets(s, MAX_LINE_LENGTH, stdin);
    s[strlen(s) - 1] = '\0';
    if (strcmp(s, "domain") == 0) {
        strncat(domain, " IN A ", 7);
        rewind(stdin);
        printf("enter IP adress: ");
        strcpy(s, validation_IP());
        s[strlen(s) - 1] = '\0';
        strncat(domain, s, MAX_LINE_LENGTH);
    }
    else {
        strncat(domain, " IN CNAME ", 11);
        rewind(stdin);
        printf("enter domain: ");
        fgets(s, MAX_LINE_LENGTH, stdin);
        s[strlen(s) - 1] = '\0';
        strncat(domain, s, MAX_LINE_LENGTH);
    }
    fseek(file, 0, SEEK_END);
    fputs(domain, file);
    fclose(file);
}

int main() {
    setlocale(LC_ALL, "Russian");
hash_table_t hash_table = { 0, (hash_node_t**)calloc(TABLE_SIZE, sizeof(hash_node_t*)) };
cache_t cache = { 0, CACHE_SIZE, NULL, NULL };

inicialization_hash_table(&hash_table, &cache);

while (1) {
    char s[MAX_LINE_LENGTH];
    rewind(stdin);
    printf("enter domain: ");
    fgets(s, MAX_LINE_LENGTH, stdin);
    s[strlen(s) - 1] = '\0';
    char* value = get_from_cache(&cache, &hash_table, s);
    if (value != NULL) {
        printf("IP address: %s\n", value);
    }
    else {
        char* IP = get_ip_address(&hash_table, s);
        if (IP != NULL) {
            add_to_cache(&cache, &hash_table, s, IP);
            value = get_from_cache(&cache, &hash_table, s);
            printf("IP address: %s\n", value);
        }
        if (value == NULL && IP == NULL) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
            printf("this domain does not exist in file\n\nif u want to add it press 1 \n\nif u want to rewrite domain press 2\n\nif u want to end programm press 0\n\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
            int choice = 0;
            scanf("%d", &choice);
            switch (choice) {
            case 1:
                add_domain_to_file(s);
                break;
            case 2:
                break;
            case 0:
                return 0;
                break;
            }

        }
    }
    
}
mem_free(&cache, &hash_table);

return 0;
}