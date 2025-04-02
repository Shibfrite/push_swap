/* ************************************************************************** */
/*																			*/
/*														 ::::::::		   */
/*   hash_table.c                                        :+:    :+:           */
/*													  +:+				   */
/*   By: makurek <marvin@42.fr>						+#+					*/
/*													+#+					 */
/*   Created: 2025/03/31 14:21:51 by makurek		#+#	#+#				*/
/*   Updated: 2025/03/31 15:53:03 by makurek        ########   odam.nl        */
/*																			*/
/* ************************************************************************** */

#include "hash_table.h"

int	hash_table_init(t_hash_table *ht)
{
	ht->size = TABLE_SIZE;
	ht->hash = hash_multiplication;
	ht->compare = compare_strings;
	ht->resolve_collision = chaining_resolution;
	ht->lookup_method = chaining_lookup;
	ht->table = ft_calloc(ht->size, sizeof(void *));
	if (!ht->table)
		return (ERROR);
	return (SUCCESS);
}

void	hash_table_print(t_hash_table *ht)
{
	size_t	i;
	t_node	*current;

	if (!ht)
		return ;
	ft_putendl("Start");
	i = 0;
	while (i < TABLE_SIZE)
	{
		ft_putstr("\t");
		ft_putnbr(i);
		ft_putstr("\t");
		current = ht->table[i++];
		while (current)
		{
			ft_putstr((char *)current->data);
			ft_putstr(" -> ");
			current = current->next;
		}
		ft_putendl("NULL");
	}
	ft_putendl("End");
}

int	hash_table_insert(t_hash_table *ht, void *data, size_t data_size)
{
	void	*new_data;
	int		result;

	if (!ht || !data)
		return (ERROR);
	new_data = malloc(data_size);
	if (!new_data)
		return (ERROR);
	ft_memcpy(new_data, data, data_size);
	result = ht->resolve_collision(ht, ht->hash(new_data), new_data);
	if (result == ERROR)
		free(new_data);
	return (result);
}

void	*hash_table_lookup(t_hash_table *ht, const void *key)
{
	size_t	index;

	if (!ht || !key)
		return (NULL);
	index = ht->hash(key);
	return (ht->lookup_method(ht, index, key));
}
