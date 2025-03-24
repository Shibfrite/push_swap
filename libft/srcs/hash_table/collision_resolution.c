#include "hash_table.h"

void* chaining_lookup(hash_table *ht, size_t index, const void *key)
{
	node	*current;

	if (!ht || index >= ht->size)
		return (NULL;
	current = ht->table[index];
	while (current)
	{
		if (!ht->compare(current->data, key))
			return (current->data);
		current = current->next;
	}
	return (NULL);
}

int chaining_resolution(hash_table *ht, size_t index, void *data)
{
	node *new_node;
	
	if (!ht || index >= ht->size)
		return (ERROR);
	if (chaining_lookup(ht, index, data))
		return (ERROR);
	new_node = malloc(sizeof(node));
	if (!new_node)
		return (ERROR);
	new_node->data = data;
	new_node->next = ht->table[index];
	ht->table[index] = new_node;
	return (1);
}
