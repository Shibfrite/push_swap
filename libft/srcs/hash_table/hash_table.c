#include "hash_table.h"

void hash_table_init(hash_table *ht, size_t size, hash_function hash, 
					 compare_function compare, 
					 collision_resolution_function resolve_collision,
					 lookup_method_function lookup_method)
{
	ht->table = calloc(size, sizeof(void *));
	ht->size = size;
	ht->hash = hash;
	ht->compare = compare;
	ht->resolve_collision = resolve_collision;
	ht->lookup_method = lookup_method;
}

void	hash_table_print(hash_table *ht)
{
	size_t i;

	if (!ht)
		return ;
	printf("Start\n");
	i = 0;
	while (i < TABLE_SIZE)
	{
		printf("\t%zu\t", i);
		node *current = ht->table[i++];
		while (current)
		{
			printf("%s -> ", (char *)current->data);
			current = current->next;
		}
		printf("NULL\n");
	}
	printf("End\n");
}

int hash_table_insert(hash_table *ht, void *data, size_t data_size)
{
	size_t index;
	void *new_data;
	int result;

	if (!ht || !data)
		return (0);
	index = ht->hash(data) % ht->size;
	new_data = malloc(data_size);
	if (!new_data)
		return (0);
	memcpy(new_data, data, data_size);
	result = ht->resolve_collision(ht, index, new_data);
	if (!result)
		free(new_data);
	return (result);
}

void *hash_table_lookup(hash_table *ht, const void *key)
{
	size_t	index;

	if (!ht || !key)
		return NULL;
	index = ht->hash(key);
	return (ht->lookup_method(ht, index, key));
}

void *hash_table_delete(hash_table *ht, const void *key)
{
	size_t	index;
	node	*current;
	node	*prev;
	void	*data;

	if (!ht || !key)
		return (NULL);
	index = ht->hash(key);
	current = ht->table[index];
	prev = NULL;
	while (current)
	{
		if (!ht->compare(current->data, key))
		{
			data = current->data;
			if (prev)
				prev->next = current->next;
			else
				ht->table[index] = current->next;
			free(current);
			return (data);
		}
		prev = current;
		current = current->next;
	}
	return (NULL);
}
