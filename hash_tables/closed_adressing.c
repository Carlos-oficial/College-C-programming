#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#define DEBUG_MODE 1
#define isNull(x) ((x) == 0)
#define strEquals(a, b) (!strcmp(a, b))
#define string const char *
#define uint unsigned int
#define putS(x) printf("%s\n", x)

typedef enum HashTableError_
{
    NoError = 0,
    KeyNotFound,
    OverwrittenValue
} HashTableError;

typedef struct HashNode_
{
    int ocorr;
    char *key;
    void *data;
    struct HashNode_ *next;
} HashNode;

typedef struct _HashTable_C
{
    HashNode **nodes;
    uint size;
    uint occupied;
} HashTable_C;

uint hash_function(string key)
{
    unsigned sum = 0;
    for (int i = 0; key[i]; i++)
    {
        sum += key[i];
    }
    return sum;
}

HashNode *_new_hash_node(string key, void *data, HashNode *next)
{
    HashNode *new = malloc(sizeof(HashNode));
    new->key = strdup(key);
    new->data = data;
    new->next = next;
    return new;
}

HashTableError insert(HashTable_C *table, string key, void *value)
{
    uint index = hash_function(key) % table->size;

    for (HashNode *aux = table->nodes[index]; aux; aux = aux->next)
    {
        if (strEquals(aux->key, key))
        {
            // free(aux->data);
            aux->data = value;
            return OverwrittenValue;
        }
    }
    table->nodes[index] = _new_hash_node(key, value, table->nodes[index]);
    return NoError;
}

#define lookupAs(Type, table, key) (Type) _lookup(table, key)
void *_lookup(HashTable_C *table, string key)
{
    uint index = hash_function(key) % table->size;
    if (DEBUG_MODE)
        printf("key:%s hash:%d ", key, index);
    for (HashNode *aux = table->nodes[index]; aux; aux = aux->next)
    {
        if (strEquals(aux->key, key))
        {
            if (DEBUG_MODE)
                printf("value: %s\n", (string)aux->data);
            // free(aux->data);
            return aux->data;
        }
    }
    if (DEBUG_MODE)
        printf("Not in the table\n");
    return NULL;
}

#define newTable(Type) _new_table(sizeof(Type))
HashTable_C *_new_table(uint elem_size)
{
    HashTable_C *table = malloc(sizeof(HashTable_C));
    table->size = 71;
    table->occupied = 0;
    table->nodes = malloc(table->size * elem_size);
    return table;
}

int main()
{
    HashTable_C *table = newTable(string);
    insert(table, "quem", "És tu?");
    insert(table, "quando", "É o Natal?");
    insert(table, "uqando", "É amanha");
    lookupAs(string, table, "quem");
    lookupAs(string, table, "uqando");
    lookupAs(string, table, "quando");
}