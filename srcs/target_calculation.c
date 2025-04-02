/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   target_calculation.c                                :+:    :+:           */
/*                                                      +:+                   */
/*   By: makurek <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/31 13:12:17 by makurek        #+#    #+#                */
/*   Updated: 2025/04/02 20:14:39 by makurek        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int	closest_index;

	closest_index = determin_closest_data(*(int *)second->data, first);
	if (closest_index == -1)
		return (0);
	return (closest_index);
}

int	find_position(t_dnode *current, int *target_pos,
			int *max_pos, int node_data)
{
	int		target_val;
	int		max_val;
	int		pos;
	int		current_data;

	pos = 0;
	target_val = INT_MIN;
	max_val = INT_MIN;
	while (current)
	{
		current_data = *(int *)current->data;
		if (current_data < node_data && current_data > target_val)
		{
			target_val = current_data;
			*target_pos = pos;
		}
		if (current_data > max_val)
		{
			max_val = current_data;
			*max_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (target_val);
}

int	find_target_position(t_dnode *node, t_dnode *target_head)
{
	int	max_pos;
	int	target_pos;

	if (!node || !target_head)
		return (ERROR);
	if (find_position(target_head, &target_pos, &max_pos,
			*(int *)node->data) == INT_MIN)
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
