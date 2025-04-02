/* ************************************************************************** */
/*																			*/
/*														 ::::::::		   */
/*   hash_remover.c                                      :+:    :+:           */
/*													  +:+				   */
/*   By: makurek <marvin@42.fr>						+#+					*/
/*													+#+					 */
/*   Created: 2025/03/31 14:29:22 by makurek		#+#	#+#				*/
/*   Updated: 2025/03/31 16:35:18 by makurek        ########   odam.nl        */
/*																			*/
/* ************************************************************************** */

#include "hash_table.h"

static void	*find_and_remove_node(t_node **head, const void *key,
			int (*compare)(const void *, const void *))
{
	t_node	*current;
	t_node	*prev;
	void	*data;

	while (current)
	{
		if (!compare(current->data, key))
		{
			data = current->data;
			if (prev)
				prev->next = current->next;
			else
				*head = current->next;
			free(current);
			return (data);
		}
		prev = current;
		current = current->next;
	}
	return (NULL);
}

void	*hash_table_delete(t_hash_table *ht, const void *key)
{
	int	index;

	if (!ht || !key)
		return (NULL);
	index = ht->hash(key);
	return (find_and_remove_node((t_node **)&ht->table[index],
			key, ht->compare));
}

void	hash_table_destroy(t_hash_table *ht)
{
	t_node	*current;
	t_node	*next;
	size_t	i;

	i = 0;
	if (!ht)
		return ;
	while (i < ht->size)
	{
		current = ht->table[i];
		while (current)
		{
			next = current->next;
			free(current->data);
			free(current);
			current = next;
		}
		i++;
	}
	free(ht->table);
}
