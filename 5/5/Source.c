#include "dot.h"

char* validation_IP() {
    char s[MAX_LINE_LENGTH];
    while (1) {
        rewind(stdin);
        fgets(s, MAX_LINE_LENGTH, stdin);
        s[strlen(s) - 1] = '\0';
        int i = 0;
        int sum = 0;
        int fl = 1;
        int point = 0;
        while (s[i] != '\0') {
            if ((s[i] < '0' || s[i] > '9') && s[i] != '.') {
                fl = 0;
                printf("Entered IP address contains invalid characters\n");
                break;
            }
            else {
                sum *= 10;
                sum += s[i] - 48;
                if (s[i + 1] == '.') {
                    if (sum > 255) {
                        printf("Numbers can be only up to 255\n");
                        fl = 0;
                        break;
                    }
                    point++;
                    if (point > 3) {
                        printf("IP address has only 4 sets of numbers\n");
                        fl = 0;
                        break;
                    }
                    sum = 0;
                }
            }
            i++;
        }
        if (point < 3 && fl != 0) {
            printf("IP address has 4 sets of numbers\n");
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

void find_domains(char* IP) {
    FILE* file = fopen("asd.txt", "r");
    char s[MAX_LINE_LENGTH];
    fseek(file, 0, SEEK_SET);
    int fl = 0;
    char domain[MAX_LINE_LENGTH];
    rewind(stdin);
    while (fgets(s, MAX_LINE_LENGTH, file)) {
        char* buf;
        buf = strtok(s, " \n");
        strcpy(domain, buf);
        buf = strtok(NULL, " \n");
        buf = strtok(NULL, " \n");
        if (strcmp(buf, "A") == 0) {
            buf = strtok(NULL, " \n");
            if (strcmp(buf, IP) == 0) {
                fl = 1;
                break;
            }
        }
    }
    if (fl == 0) {
        printf("This IP does not exist in file\n");
        return;
    }
    printf("domain: %s\n", domain);
    fseek(file, 0, SEEK_SET);
    rewind(stdin);
    while (fgets(s, MAX_LINE_LENGTH, file)) {
        char* buf;
        char canonical[MAX_LINE_LENGTH];
        buf = strtok(s, " \n");
        strcpy(canonical, buf);
        buf = strtok(NULL, " \n");
        buf = strtok(NULL, " \n");
        if (strcmp(buf, "CNAME") == 0) {
            buf = strtok(NULL, " \n");
            if (strcmp(buf, domain) == 0) {
                printf("Canonical name: %s\n", canonical);
            }
        }
    }



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