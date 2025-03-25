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

int	get_closest_index(t_dnode *first, t_dnode *second)
{
	t_dnode *current;
	int		target;
	int		closest_index;
	int		closest_data;
	int		index;
	int		current_data;

	current = first;
	target = *(int *)second->data;
	closest_index = -1;
	closest_data = INT_MIN;
	index = 0;
	while (current)
	{
		current_data = *(int *)current->data;
		if ((((current_data > closest_data) || (closest_data > target))
				&& current_data < target) || (current_data > target
				&& ((closest_data > target) || (closest_index == -1))
				&& current_data > closest_data))
		{
			closest_data = current_data;
			closest_index = index;
		}
		current = current->next;
		index++;
	}
	if (closest_index == -1)
		return (0);
	return (closest_index);
}

int find_target_position(t_dnode *node, t_dnode *target_head) {
    t_dnode *current = target_head;
    int target_pos = 0;
    int target_val = INT_MIN;
    int max_val = INT_MIN;
    int max_pos = 0;
    int pos = 0;
    int current_data;
    int node_data;

	if (!node || !target_head)
		return (ERROR);
    while (current)
	{
        current_data = *(int *)current->data;
        node_data = *(int *)node->data;
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

/*
 *int find_target_position(t_dnode *node, t_dnode *target_head) {
    t_dnode *current = target_head;
    int best_pos = 0, max_pos = 0, node_data = *(int *)node->data;
    int pos = 0;

    while (current) {
        int current_data = *(int *)current->data;

        // Track the largest value in stack A
        if (current_data > *(int *)(target_head + max_pos)->data)
            max_pos = pos;

        // Track the largest value smaller than node_data
        if (current_data < node_data && 
            (best_pos == 0 || current_data > *(int *)(target_head + best_pos)->data))
            best_pos = pos;

        current = current->next;
        pos++;
    }

    // If no valid "smaller" position was found, return the position of the largest value
    return (*(int *)(target_head + best_pos)->data < node_data) ? best_pos : max_pos;
}
 * */

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
