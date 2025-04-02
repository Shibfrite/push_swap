/* ************************************************************************** */
/*																			*/
/*														 ::::::::		   */
/*   optimize.c                                          :+:    :+:           */
/*													  +:+				   */
/*   By: makurek <marvin@42.fr>						+#+					*/
/*													+#+					 */
/*   Created: 2025/03/27 16:15:31 by makurek		#+#	#+#				*/
/*   Updated: 2025/03/31 16:52:47 by makurek        ########   odam.nl        */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

void	delete_node(t_dnode **head, t_dnode *node_to_delete)
{
	if (!*head || !node_to_delete)
		return ;
	if (*head == node_to_delete)
		*head = node_to_delete->next;
	if (node_to_delete->next)
		node_to_delete->next->prev = node_to_delete->prev;
	if (node_to_delete->prev)
		node_to_delete->prev->next = node_to_delete->next;
	ft_dlstdelone(node_to_delete, free_operation);
}

void	update_node_content(t_dnode *node,
			const char *new_name, int new_rotation_count)
{
	t_operation	*op;

	if (!node || !node->data)
		return ;
	op = (t_operation *)node->data;
	op->name = ft_strdup(new_name);
	if (!op->name)
		exit(1);
	op->rotation_count = new_rotation_count;
}

int	check_operation_pair(const char *op1,
			const char *op2, const char *val1, const char *val2)
{
	return ((!ft_strcmp(op1, val1) && !ft_strcmp(op2, val2))
		|| (!ft_strcmp(op1, val2) && !ft_strcmp(op2, val1)));
}

int	optimize_swaps(t_dnode **head, t_dnode *current)
{
	t_operation	*curr_op;
	t_operation	*next_op;

	if (!*head || !current || !current->next)
		return (0);
	curr_op = (t_operation *)current->data;
	next_op = (t_operation *)current->next->data;
	if (!ft_strcmp(curr_op->name, next_op->name))
	{
		if (!ft_strcmp(curr_op->name, "sa")
			|| !ft_strcmp(curr_op->name, "sb")
			|| !ft_strcmp(curr_op->name, "ss"))
		{
			delete_node(head, current->next);
			delete_node(head, current);
			return (1);
		}
	}
	if (check_operation_pair(curr_op->name, next_op->name, "sa", "sb"))
	{
		update_node_content(current, "ss", 1);
		delete_node(head, current->next);
		return (1);
	}
	return (0);
}

void	optimize_operations(t_dnode **head, int total)
{
	int		changes_made;
	t_dnode	*current;

	changes_made = 1;
	while (changes_made)
	{
		changes_made = 0;
		current = *head;
		while (current && current->next)
		{
			if (optimize_swaps(head, current)
				|| optimize_rotations(head, current, total))
				changes_made = 1;
			current = current->next;
		}
	}
}
