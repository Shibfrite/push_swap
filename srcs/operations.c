/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   operations.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: makurek <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/27 16:49:26 by makurek        #+#    #+#                */
/*   Updated: 2025/03/31 18:13:18 by makurek        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_single_operation(t_stacks *stacks,
			const char *op_name, int rotation_count)
{
	if (!ft_strcmp(op_name, "sa"))
		sa(stacks);
	else if (!ft_strcmp(op_name, "sb"))
		sb(stacks);
	else if (!ft_strcmp(op_name, "ss"))
		ss(stacks);
	else if (!ft_strcmp(op_name, "ra"))
		ra(stacks, rotation_count);
	else if (!ft_strcmp(op_name, "rb"))
		rb(stacks, rotation_count);
	else if (!ft_strcmp(op_name, "rr"))
		rr(stacks, rotation_count);
	else if (!ft_strcmp(op_name, "rra"))
		rra(stacks, rotation_count);
	else if (!ft_strcmp(op_name, "rrb"))
		rrb(stacks, rotation_count);
	else if (!ft_strcmp(op_name, "rrr"))
		rrr(stacks, rotation_count);
	else if (!ft_strcmp(op_name, "pa"))
		pa(stacks);
	else if (!ft_strcmp(op_name, "pb"))
		pb(stacks);
}

void	add_operation(t_dnode **head, t_stacks *stacks,
			char *operation, int rotation_count)
{
	t_operation	*op;
	t_dnode		*new_node;

	if (!rotation_count)
		return ;
	op = malloc(sizeof(t_operation));
	if (!op)
		exit(1);
	execute_single_operation(stacks, operation, rotation_count);
	op->name = ft_strdup(operation);
	if (!op->name)
		exit(1);
	op->rotation_count = rotation_count;
	new_node = ft_dlstnew(op);
	if (!new_node)
	{
		free(op->name);
		free(op);
		exit(1);
	}
	ft_dlstadd_back(head, new_node);
}

void	execute_operations(t_dnode *head)
{
	t_dnode		*current;
	t_operation	*op;

	current = head;
	while (current)
	{
		op = (t_operation *)current->data;
		while (op->rotation_count--)
			ft_putendl_fd(op->name, 1);
		current = current->next;
	}
}

void	free_operation(void *data)
{
	t_operation	*op;

	op = (t_operation *)data;
	free(op->name);
	free(op);
}
