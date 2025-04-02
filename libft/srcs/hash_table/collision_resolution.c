/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   collision_resolution.c                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: makurek <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/31 14:19:22 by makurek        #+#    #+#                */
/*   Updated: 2025/03/31 14:33:42 by makurek        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "hash_table.h"

void	*chaining_lookup(t_hash_table *ht, size_t index, const void *key)
{
	t_node	*current;

	if (!ht || index >= ht->size)
		return (NULL);
	current = ht->table[index];
	while (current)
	{
		if (!ht->compare(current->data, key))
			return (current->data);
		current = current->next;
	}
	return (NULL);
}

int	chaining_resolution(t_hash_table *ht, size_t index, void *data)
{
	t_node	*new_node;

	if (!ht || index >= ht->size)
		return (ERROR);
	if (chaining_lookup(ht, index, data))
		return (ERROR);
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (ERROR);
	new_node->data = data;
	new_node->next = ht->table[index];
	ht->table[index] = new_node;
	return (1);
}
