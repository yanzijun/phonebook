#include <stdlib.h>
#include <string.h>
#include "phonebook_hash.h"

hashTable *createHashTable(int tableSize)
{
    int i;
    hashTable *tb;
    tb = (hashTable*)malloc(sizeof(hashTable));
    tb->list = (entry **)malloc(sizeof(entry*)*tableSize);
    for(i = 0; i < tableSize; i++) {
        tb->list[i] = NULL;
    }
    return tb;
}

unsigned int hash(char *str)
{
    unsigned int hash_value = 0;
    unsigned int seed = 131;

    while(*str)
        hash_value = hash_value * seed + (*str++);
    return (hash_value % TABLE_SIZE);
}

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], hashTable *tb)
{
    entry *e;
    unsigned int index = hash(lastName);

    for(e = tb->list[index]; e != NULL; e = e->pNext) {
        if (strcasecmp(lastName, e->lastName) == 0)
            return e;

    }
    return NULL;
}

void append(char lastName[], hashTable *tb)
{
    /* allocate memory for the new entry and put lastName */
    unsigned int index = hash(lastName);
    entry *e;
    e = (entry*)malloc(sizeof(entry));
    strcpy(e->lastName, lastName);
    e->pNext = tb->list[index];
    tb->list[index] = e;
}
