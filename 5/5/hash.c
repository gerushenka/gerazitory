#include "dot.h"
void inicialization_hash_table(hash_table_t* hash_table, cache_t* cache, char* s) {
    FILE* file = fopen("asd.txt", "r");
    char line[MAX_LINE_LENGTH];
    char key[MAX_LINE_LENGTH];
    char value[MAX_LINE_LENGTH];
    char* token;
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        token = strtok(line, " \n");
        strcpy(key, token);
        if (strcmp(s,key)== 0){
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
                // printf("%d\n", hash);

            }
            else {
                if (strcmp(token, "CNAME") == 0) {
                    token = strtok(NULL, " \n");
                    inicialization_hash_table(hash_table, cache, token);
                    char* IP = get_ip_address(hash_table, token);
                    hash_node_t* new_node = create_hash_node(key, IP);
                    int hash = hash_function(key);
                    new_node->next = hash_table->table[hash];
                    hash_table->table[hash] = new_node;
                    //    printf("%d\n", hash);

                }
            }
        }

    }
    fclose(file);
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
