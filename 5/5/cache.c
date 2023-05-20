#include "dot.h"




cache_node_t* create_node(char* key, char* value) {
    cache_node_t* new_node = (cache_node_t*)malloc(sizeof(cache_node_t));
    strcpy(new_node->key, key);
    strcpy(new_node->value, value);
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
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

void print_cache(cache_t* cache) {
    cache_node_t* current_node = cache->head;
    printf("Cache:\n");
    while (current_node != NULL) {
        printf("%s %s\n", current_node->key, current_node->value);
        current_node = current_node->next;
    }
}
