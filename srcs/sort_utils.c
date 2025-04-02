/* ************************************************************************** */
/*																			*/
/*														 ::::::::		   */
/*   sort_utils.c                                        :+:    :+:           */
/*													  +:+				   */
/*   By: makurek <marvin@42.fr>						+#+					*/
/*													+#+					 */
/*   Created: 2025/03/27 15:59:14 by makurek		#+#	#+#				*/
/*   Updated: 2025/03/31 16:48:58 by makurek        ########   odam.nl        */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_dnode *stack)
{
	while (stack && stack->next)
	{
		if (*(int *)stack->data > *(int *)stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	find_max_index(t_dnode *head)
{
	t_dnode	*current;
	int		max_data;
	int		max_index;
	int		current_index;
	int		current_data;

	if (!head)
		return (-1);
	current = head;
	max_data = *(int *)current->data;
	max_index = 0;
	current_index = 0;
	while (current)
	{
		current_data = *(int *)current->data;
		if (current_data > max_data)
		{
			max_data = current_data;
			max_index = current_index;
		}
		current = current->next;
		current_index++;
	}
	return (max_index);
}
