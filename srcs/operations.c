#include "push_swap.h"

void execute_single_operation(t_stacks *stacks, const char *op_name, int rotation_count)
{
	if (!strcmp(op_name, "sa")) sa(stacks);
	else if (!strcmp(op_name, "sb")) sb(stacks);
	else if (!strcmp(op_name, "ss")) ss(stacks);
	else if (!strcmp(op_name, "ra")) ra(stacks, rotation_count);
	else if (!strcmp(op_name, "rb")) rb(stacks, rotation_count);
	else if (!strcmp(op_name, "rr")) rr(stacks, rotation_count);
	else if (!strcmp(op_name, "rra")) rra(stacks, rotation_count);
	else if (!strcmp(op_name, "rrb")) rrb(stacks, rotation_count);
	else if (!strcmp(op_name, "rrr")) rrr(stacks, rotation_count);
	else if (!strcmp(op_name, "pa")) pa(stacks);
	else if (!strcmp(op_name, "pb")) pb(stacks);
}

void add_operation(t_dnode **head, t_stacks *stacks, char *operation, int rotation_count)
{
	t_operation *op = malloc(sizeof(t_operation));
	if (!op)
		return;
	execute_single_operation(stacks, operation, rotation_count);
	op->name = strdup(operation);
	op->rotation_count = rotation_count;

	t_dnode *new_node = ft_dlstnew(op);
	if (!new_node)
	{
		free(op->name);
		free(op);
		return;
	}
	ft_dlstadd_back(head, new_node);
}

void execute_operations(t_dnode *head)
{
	t_dnode *current = head;
	while (current)
	{
		t_operation *op = (t_operation*)current->data;
		while (op->rotation_count--)
			ft_putendl_fd(op->name, 1);
		
		current = current->next;
	}
}

void free_operation(void *data)
{
	t_operation *op = (t_operation*)data;
	free(op->name);
	free(op);
}
