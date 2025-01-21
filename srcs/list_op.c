#include "push_swap.h"

typedef struct s_operation {
	char *name;
	int rotation_count;
} t_operation;

void optimize_swaps(t_operation *curr_op, t_operation *next_op, t_list *next, t_list *current)
{
	if (!strcmp(curr_op->name, next_op->name))
	{
		if (!strcmp(curr_op->name, "sa") || !strcmp(curr_op->name, "sb") || strcmp(curr_op->name, "ss"))
		{
			current->next = next->next;
			ft_lstdelone(next, free_operation);
		}
	}
}

void optimize_operations(t_list **head)
{
	t_list *current = *head;
	t_list *next;
	while (current && current->next)
	{
		next = current->next;
		t_operation *curr_op = (t_operation*)current->content;
		t_operation *next_op = (t_operation*)next->content;
		optimize_swaps(curr_op, next_op, next, current);
		current = current->next;
	}
}
/*
void optimize_rotations(t_list **head)
{
}
*/
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

void add_operation(t_list **head, t_stacks *stacks, char *operation, int rotation_count)
{
	t_operation *op = malloc(sizeof(t_operation));
	if (!op)
		return;
	execute_single_operation(stacks, operation, rotation_count);
	op->name = strdup(operation);
	op->rotation_count = rotation_count;

	t_list *new_node = ft_lstnew(op);
	if (!new_node)
	{
		free(op->name);
		free(op);
		return;
	}
	ft_lstadd_back(head, new_node);
}

void execute_operations(t_list *head)
{
	t_list *current = head;
	while (current)
	{
		t_operation *op = (t_operation*)current->content;
		while (op->rotation_count--)
			ft_putendl_fd(op->name, 1);
		
		current = current->next;
	}
}


void free_operation(void *content)
{
	t_operation *op = (t_operation*)content;
	free(op->name);
	free(op);
}
