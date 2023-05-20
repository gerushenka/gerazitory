#pragma once

#include <stdio.h>
#include <Windows.h>
#include <wincon.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_LINE_LENGTH 256
#define CACHE_SIZE 3
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


cache_node_t* create_node(char* key, char* value);
void add_node_to_head(cache_t* cache, cache_node_t* node);
void remove_tail(cache_t* cache);
void add_to_cache(cache_t* cache, hash_table_t* hash_table, char* key, char* value);
char* get_from_cache(cache_t* cache, hash_table_t* hash_table, char* key);
void print_cache(cache_t* cache);

void inicialization_hash_table(hash_table_t* hash_table, cache_t* cache, char* s);
hash_node_t* create_hash_node(char* key, char* value);
int hash_function(char* key);

char* validation_IP();
void add_domain_to_file(char* domain);
void find_domains(char* IP);
void mem_free(cache_t* cache, hash_table_t* hash_table);
char* get_ip_address(hash_table_t* hash_table, char* key);