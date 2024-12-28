#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE (person*)(0xFFFFFFFFFFFUL)

typedef struct {
    char name[MAX_NAME];
    int age;
} person;

typedef size_t (*hash_function)(const char *key);
typedef size_t (*collision_resolution)(size_t index, size_t attempt);

typedef struct {
    person *table[TABLE_SIZE];
    hash_function hash;
    collision_resolution resolve;
} hash_table;

size_t hash_multiplication(const char *key)
{
    size_t len;
    size_t i;
    unsigned int hash_value;
    len = strnlen(key, MAX_NAME);
    hash_value = 0;
    i = 0;
    while(i < len)
    {
        hash_value += key[i];
        hash_value *= key[i];
        hash_value %= TABLE_SIZE;
        i++;
    }
    return hash_value;
}

size_t linear_probing(size_t index, size_t attempt)
{
    return (index + attempt) % TABLE_SIZE;
}

void hash_table_init(hash_table *ht, hash_function hash, collision_resolution resolve)
{
    size_t i;
    ht->hash = hash;
    ht->resolve = resolve;
    i = 0;
    while(i < TABLE_SIZE)
    {
        ht->table[i] = NULL;
        i++;
    }
}

void hash_table_print(hash_table *ht)
{
    size_t i;
    if (!ht)
        return;
    i = 0;
    printf("Start\n");
    while(i < TABLE_SIZE)
    {
        if (ht->table[i] == DELETED_NODE)
            printf("\t%zu\t-<deleted>-\n", i);
        else if (ht->table[i])
            printf("\t%zu\t%s\n", i, ht->table[i]->name);
        else
            printf("\t%zu\t---\n", i);
        i++;
    }
    printf("End\n");
}

int hash_table_insert(hash_table *ht, person *p)
{
    size_t index;
    size_t attempt;
    size_t try;
    if (!ht || !p)
        return 0;
    index = ht->hash(p->name);
    attempt = 0;
    while (attempt < TABLE_SIZE)
    {
        try = ht->resolve(index, attempt);
        if (!ht->table[try] || ht->table[try] == DELETED_NODE)
        {
            ht->table[try] = p;
            return 1;
        }
        attempt++;
    }
    return 0;
}

person *hash_table_lookup(hash_table *ht, char *name)
{
    size_t index;
    size_t attempt;
    size_t try;
    if (!ht || !name)
        return NULL;
    index = ht->hash(name);
    attempt = 0;
    while (attempt < TABLE_SIZE)
    {
        try = ht->resolve(index, attempt);
        if (!ht->table[try])
            return NULL;
        if (ht->table[try] != DELETED_NODE && !strncmp(ht->table[try]->name, name, MAX_NAME))
            return ht->table[try];
        attempt++;
    }
    return NULL;
}

person *hash_table_delete(hash_table *ht, char *name)
{
    size_t index;
    size_t attempt;
    size_t try;
    person *tmp;
    if (!ht || !name)
        return NULL;
    index = ht->hash(name);
    attempt = 0;
    while (attempt < TABLE_SIZE)
    {
        try = ht->resolve(index, attempt);
        if (!ht->table[try])
            return NULL;
        if (ht->table[try] != DELETED_NODE && !strncmp(ht->table[try]->name, name, MAX_NAME))
        {
            tmp = ht->table[try];
            ht->table[try] = DELETED_NODE;
            return tmp;
        }
        attempt++;
    }
    return NULL;
}

int main()
{
    hash_table ht;
    person *tmp;
    hash_table_init(&ht, hash_multiplication, linear_probing);
    hash_table_print(&ht);
    person jacob = {.name="Jacob", .age=256};
    person kate = {.name="Kate", .age=27};
    person mpho = {.name="Mpho", .age=14};
    person sarah = {.name="Sarah", .age=256};
    person edna = {.name="Edna", .age=256};
    person maren = {.name="Maren", .age=256};
    person eliza = {.name="Eliza", .age=256};
    person robert = {.name="Robert", .age=256};
    person jane = {.name="Jane", .age=256};
    hash_table_insert(&ht, &jacob);
    hash_table_insert(&ht, &kate);
    hash_table_insert(&ht, &mpho);
    hash_table_insert(&ht, &sarah);
    hash_table_insert(&ht, &edna);
    hash_table_insert(&ht, &maren);
    hash_table_insert(&ht, &eliza);
    hash_table_insert(&ht, &robert);
    hash_table_insert(&ht, &jane);
    hash_table_print(&ht);
    tmp = hash_table_lookup(&ht, "Mpho");
    if (!tmp)
        printf("Not found.\n");
    else
        printf("Found %s.\n", tmp->name);
    tmp = hash_table_lookup(&ht, "George");
    if (!tmp)
        printf("Not found.\n");
    else
        printf("Found %s.\n", tmp->name);
    hash_table_delete(&ht, "Mpho");
    hash_table_print(&ht);
    return 0;
}
