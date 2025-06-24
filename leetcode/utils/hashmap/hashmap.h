#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Macro to define a generic HashMap
#define DEFINE_HASHMAP(key_type, val_type, name, hash_func, key_equals, NOT_FOUND) \
    \
    typedef struct name##_Node { \
        key_type key; \
        val_type val; \
        struct name##_Node *next; \
    } name##_Node; \
    \
    typedef struct { \
        name##_Node *head; \
    } name##_Chain; \
    \
    static name##_Node *name##_create_node(key_type key, val_type val) { \
        name##_Node *n = (name##_Node *)malloc(sizeof(name##_Node)); \
        n->key = key; \
        n->val = val; \
        n->next = NULL; \
        return n; \
    } \
    \
    static void name##_append_to_chain(name##_Chain *chain, key_type key, val_type val) { \
        name##_Node *new_node = name##_create_node(key, val); \
        new_node->next = chain->head; \
        chain->head = new_node; \
    } \
    \
    static void name##_free_chain(name##_Chain *chain) { \
        while (chain->head) { \
            name##_Node *next = chain->head->next; \
            free(chain->head); \
            chain->head = next; \
        } \
    } \
    \
    typedef struct { \
        name##_Chain *chains; \
        int size; \
        int cardinality; \
    } HashMap; \
    \
    HashMap *name##_create(int cardinality) { \
        HashMap *map = (HashMap *)malloc(sizeof(HashMap)); \
        map->cardinality = cardinality; \
        map->size = 0; \
        map->chains = (name##_Chain *)malloc(sizeof(name##_Chain) * cardinality); \
        for (int i = 0; i < cardinality; i++) { \
            map->chains[i].head = NULL; \
        } \
        return map; \
    } \
    \
    void name##_free(HashMap *map) { \
        for (int i = 0; i < map->cardinality; i++) { \
            name##_free_chain(&map->chains[i]); \
        } \
        free(map->chains); \
        free(map); \
    } \
    \
    int name##_haskey(HashMap *map, key_type key) { \
        size_t hash_val = hash_func(key); \
        int idx = (int)(hash_val % (size_t)map->cardinality); \
        name##_Chain *chain = &map->chains[idx]; \
        name##_Node *current = chain->head; \
        while (current) { \
            if (key_equals(current->key, key)) { \
                return 1; \
            } \
            current = current->next; \
        } \
        return 0; \
    } \
    \
    val_type name##_get(HashMap *map, key_type key) { \
        size_t hash_val = hash_func(key); \
        int idx = (int)(hash_val % (size_t)map->cardinality); \
        name##_Chain *chain = &map->chains[idx]; \
        name##_Node *current = chain->head; \
        while (current) { \
            if (key_equals(current->key, key)) { \
                return current->val; \
            } \
            current = current->next; \
        } \
        return NOT_FOUND; \
    } \
    \
    void name##_set(HashMap *map, key_type key, val_type val) { \
        size_t hash_val = hash_func(key); \
        int idx = (int)(hash_val % (size_t)map->cardinality); \
        name##_Chain *chain = &map->chains[idx]; \
        name##_Node *current = chain->head; \
        while (current) { \
            if (key_equals(current->key, key)) { \
                current->val = val; \
                return; \
            } \
            current = current->next; \
        } \
        name##_append_to_chain(chain, key, val); \
        map->size++; \
    } \
    \
    void name##_remove(HashMap *map, key_type key) { \
        size_t hash_val = hash_func(key); \
        int idx = (int)(hash_val % (size_t)map->cardinality); \
        name##_Chain *chain = &map->chains[idx]; \
        name##_Node *current = chain->head; \
        if (!current) return; \
        \
        if (key_equals(current->key, key)) { \
            chain->head = current->next; \
            free(current); \
            map->size--; \
            return; \
        } \
        \
        while (current->next) { \
            if (key_equals(current->next->key, key)) { \
                name##_Node *to_remove = current->next; \
                current->next = to_remove->next; \
                free(to_remove); \
                map->size--; \
                return; \
            } \
            current = current->next; \
        } \
    }

// Hash function for integers or chars
size_t int_hash(int key) {
    return (size_t)(key * 31);
}

// Equality function for integers or chars
bool int_equals(int a, int b) {
    return a == b;
}

// Hash function for strings (djb2 algorithm)
size_t str_hash(char *key) {
    size_t hash = 5381;
    int c;
    while ((c = *key++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash;
}

// Equality function for strings
bool str_equals(char *a, char *b) {
    if (a == b) return true;
    if (!a || !b) return false;
    return strcmp(a, b) == 0;
}
