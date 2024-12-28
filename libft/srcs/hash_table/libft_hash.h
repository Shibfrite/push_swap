#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE (person*)(0xFFFFFFFFFFFUL)

typedef struct
{
        char    name[MAX_NAME];
        int             age;
} person;

person *hash_table[TABLE_SIZE];
void    init_hash_table();
unsigned int    hash(char *name);
void    print_table();
int     hash_table_insert(person *p);
person  *hash_table_lookup(char *name);
person  *hash_table_delete(char *name);
