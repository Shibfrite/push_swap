#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define MAX_NAME 256
#define TABLE_SIZE 10 
#define DELETED_NODE (person*)(0xFFFFFFFFFFFUL) 

typedef struct
{
	char	name[MAX_NAME];
	int		age;
} person;

person *hash_table[TABLE_SIZE];

void	init_hash_table()
{
	int	i;

	i = 0;
	while(i < TABLE_SIZE)
		hash_table[i++] = NULL;
}

unsigned int	hash(char *name)
{
	int				len;
	int				i;
	unsigned int	hash_value;
	
	len = strnlen(name, MAX_NAME);	
	hash_value = 0;
	i = 0;
	while(i < len)
	{
		hash_value += name[i];
		hash_value = (hash_value * name[i++]) % TABLE_SIZE;
	}
	return (hash_value);
}

void	print_table()
{
	int i;

	i = 0;
	printf("Start\n");
	while(i < TABLE_SIZE)
	{
		if (!hash_table[i])
			printf("\t%i\t---\n", i);
		else if (hash_table[i] == DELETED_NODE)
			printf("\t%i\t-<deleted>-\n", i);
		else
			printf("\t%i\t%s\n", i, hash_table[i]->name);
		i++;
	}
	printf("End\n");
}

int	hash_table_insert(person *p)
{
	int	index;
	int	i;
	int	try;

	if (!p)
		return (0);
	index = hash(p->name);
	while (i < TABLE_SIZE)
	{
		try = (i + index) % TABLE_SIZE;
		if (!hash_table[try] || hash_table[try] == DELETED_NODE)
		{
			hash_table[try] = p;
			return (1);
		}
		i++;
	}
	if (hash_table[index])
		return (0);
	hash_table[index] = p;
	return (1);
}

person	*hash_table_lookup(char *name)
{
	int index;
	int	i;
	int	try;

	index = hash(name);
	while (i < TABLE_SIZE)
	{
		try = (index + i) & TABLE_SIZE;
		if (!hash_table[try])
			return (NULL);
		if (hash_table[try] == DELETED_NODE)
			continue ;
		if (!strncmp(hash_table[try]->name, name, TABLE_SIZE))
			return (hash_table[try]);
		i++;
	}
	return (NULL);
}

person	*hash_table_delete(char *name)
{
	person	*tmp;
	int		index;

	tmp = hash_table_lookup(name);
	if (!tmp)
		return (NULL);
	index = hash(name);
	hash_table[index] = DELETED_NODE;
	return (tmp);
}

int	main()
{
	init_hash_table();
	print_table();

	person jacob = {.name="Jacob", .age=256};
	person kate = {.name="Kate", .age=27};
	person mpho = {.name="Mpho", .age=14};
	person sarah = {.name="Sarah", .age=256};
	person edna = {.name="Edna", .age=256};
	person maren = {.name="Maren", .age=256};
	person eliza = {.name="Eliza", .age=256};
	person robert = {.name="Robert", .age=256};
	person jane = {.name="Jane", .age=256};

	hash_table_insert(&jacob);
	hash_table_insert(&kate);
	hash_table_insert(&mpho);
	hash_table_insert(&sarah);
	hash_table_insert(&edna);
	hash_table_insert(&maren);
	hash_table_insert(&eliza);
	hash_table_insert(&robert);
	hash_table_insert(&jane);
	print_table();

	person *tmp = hash_table_lookup("Mpho");

	if (!tmp)
		printf("Not found.\n");
	else	
		printf("Found %s.\n", tmp->name);


	tmp = hash_table_lookup("George");

	if (!tmp)
		printf("Not found.\n");
	else	
		printf("Found %s.\n", tmp->name);

	hash_table_delete("Mpho");
	print_table();


	/*printf("Jacob	=> %u\n", hash("Jacob"));
	printf("Nathalie	=> %u\n", hash("Nathalie"));
	printf("Sara	=> %u\n", hash("Sara"));
	printf("Mpho	=> %u\n", hash("Mpho"));
	printf("Tebogo	=> %u\n", hash("Tebogo"));
	printf("Ron	=> %u\n", hash("Ron"));
	printf("Jane	=> %u\n", hash("Jane"));
	printf("Maren	=> %u\n", hash("Maren"));
	printf("Bill	=> %u\n", hash("Bill"));*/
	return (0);
}
