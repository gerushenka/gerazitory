#include "dot.h"



int main() {
    setlocale(LC_ALL, "Russian");
    hash_table_t hash_table = { 0, (hash_node_t**)calloc(TABLE_SIZE, sizeof(hash_node_t*)) };
    cache_t cache = { 0, CACHE_SIZE, NULL, NULL };

    int fl = 1;
    int choice = 0;
    while (1) {

        char s[MAX_LINE_LENGTH];
        printf("1 if u want to enter domain to get IP address\n2 If u want to enter IP address to get domain\n");

        if (fl == 1) {
            choice = 0;
            scanf("%d", &choice);
        }
        if (choice == 2) {


            printf("enter IP address: ");
            strcpy(s, validation_IP()); 
            find_domains(s);
        }
        if (choice == 1) {
            printf("enter domain: ");
            rewind(stdin);
            fgets(s, MAX_LINE_LENGTH, stdin);
            s[strlen(s) - 1] = '\0';
            char* value = get_from_cache(&cache, &hash_table, s);
            if (value != NULL) {
                printf("IP address: %s\n", value);
            }
            else {
                inicialization_hash_table(&hash_table, &cache, s);
                char* IP = get_ip_address(&hash_table, s);
                if (IP != NULL) {
                    add_to_cache(&cache, &hash_table, s, IP);
                    value = get_from_cache(&cache, &hash_table, s);
                    printf("IP address: %s\n", value);
                }
                if (value == NULL && IP == NULL) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                    printf("this domain does not exist in file\n\nif u want to add it press 1 \n\nif u want to rewrite domain press 2\n\nif u want to end programm press 0\n\nif u want to restart press 3\n\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
                    int option = 0;
                    scanf("%d", &option);
                    switch (option) {
                    case 1:
                        add_domain_to_file(s);
                        break;
                    case 2:
                        choice = 2;
                        fl = 0;
                        break;
                    case 0:
                        return 0;
                        break;
                    case 3:
                        fl = 1;
                        break;
                    }
                }
            }
        }
        int option = 0;
        printf("\n\nDo u want to continiue\nEnter 0 if yes 1 if no\n");
        scanf("%d", &option);
        if (option == 0) {
            fl = 1;
        }
        if (option == 1) {
            break;
        }
    }
    mem_free(&cache, &hash_table);

    return 0;
}