/* ************************************************************************** */
/*																			*/
/*														 ::::::::		   */
/*   support_sort.c                                      :+:    :+:           */
/*													  +:+				   */
/*   By: makurek <marvin@42.fr>						+#+					*/
/*													+#+					 */
/*   Created: 2025/03/27 15:59:14 by makurek		#+#	#+#				*/
/*   Updated: 2025/03/28 18:49:04 by makurek        ########   odam.nl        */
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

int	determin_closest_data(int target, t_dnode *current)
{
	int	closest_data;
	int	closest_index;
	int	index;
	int	current_data;

	index = 0;
	closest_data = INT_MIN;
	closest_index = -1;
	while (current)
	{
		current_data = *(int *)current->data;
		if ((current_data > closest_data && ((closest_data > target)
					|| (current_data < target) || (closest_index == -1)))
			|| ((closest_data > target) && current_data < target))
		{
			closest_data = current_data;
			closest_index = index;
		}
		current = current->next;
		index++;
	}
	return (closest_index);
}

int	get_closest_index(t_dnode *first, t_dnode *second)
{
	int	target;
	int	closest_index;

	closest_index = determin_closest_data(*(int *)second->data, first);
	if (closest_index == -1)
		return (0);
	return (closest_index);
}

void	temp_name()
{

}

int	find_target_position(t_dnode *node, t_dnode *target_head)
{
	t_dnode	*current;
	int		target_pos;
	int		target_val;
	int		max_val;
	int		max_pos;
	int		pos;
	int		current_data;
	int		node_data;

	if (!node || !target_head)
		return (ERROR);
	current = target_head;
	pos = 0;
	target_pos = 0;
	target_val = INT_MIN;
	max_val = INT_MIN;
	max_pos = 0;
	node_data = *(int *)node->data;
	while (current)
	{
		current_data = *(int *)current->data;
		if (current_data < node_data && current_data > target_val)
		{
			target_val = current_data;
			target_pos = pos;
		}
		if (current_data > max_val)
		{
			max_val = current_data;
			max_pos = pos;
		}
		current = current->next;
		pos++;
	}
	if (target_val == INT_MIN)
		return (max_pos);
	return (target_pos);
}

int	lowest_cost_index(t_dnode *head, t_dnode *target_stack, int total)
{
	int		i;
	int		lowest_cost;
	int		lowest_cost_index;
	int		current;
	t_dnode	*current_node;

	if (!head || !target_stack || total <= 0)
		return (0);
	i = 0;
	current_node = head;
	lowest_cost_index = 0;
	lowest_cost = find_target_position(current_node, target_stack);
	while (++i <= total - 1 && current_node)
	{
		current_node = current_node->next;
		current = find_target_position(current_node, target_stack) + i;
		if (current < lowest_cost)
		{
			lowest_cost = current;
			lowest_cost_index = i;
		}
	}
	return (lowest_cost_index);
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
