#include "push_swap.h"

static int	handle_ra_rb(t_dnode **head, t_dnode *current,
			t_operation *curr_op, t_operation *next_op)
{
	int	min_rotations;

	if (!check_operation_pair(curr_op->name, next_op->name, "ra", "rb"))
		return (0);
	if (curr_op->rotation_count < next_op->rotation_count)
		min_rotations = curr_op->rotation_count;
	else
		min_rotations = next_op->rotation_count;
	update_node_content(current, "rr", min_rotations);
	curr_op->rotation_count -= min_rotations;
	next_op->rotation_count -= min_rotations;
	if (!next_op->rotation_count)
		delete_node(head, current->next);
	else
		update_node_content(current->next, next_op->name,
			next_op->rotation_count);
	if (!curr_op->rotation_count)
		delete_node(head, current);
	return (1);
}

static int	handle_ra_rra(t_dnode **head, t_dnode *current,
			t_operation *curr_op, t_operation *next_op)
{
	int	min_rotations;

	if (!check_operation_pair(curr_op->name, next_op->name, "ra", "rra"))
		return (0);
	if (curr_op->rotation_count < next_op->rotation_count)
		min_rotations = curr_op->rotation_count;
	else
		min_rotations = next_op->rotation_count;
	curr_op->rotation_count -= min_rotations;
	next_op->rotation_count -= min_rotations;
	if (!next_op->rotation_count)
		delete_node(head, current->next);
	if (!curr_op->rotation_count)
		delete_node(head, current);
	return (1);
}

static int	handle_rot(t_dnode *current, t_operation *curr_op, int total)
{
	char	*new_op;

	if (!strcmp(curr_op->name, "ra"))
		new_op = "rra";
	else if (!strcmp(curr_op->name, "rra"))
		new_op = "ra";
	else
		return (0);
	if (curr_op->rotation_count > total / 2)
	{
		update_node_content(current, new_op, total - curr_op->rotation_count);
		return (1);
	}
	return (0);
}

static int	handle_rb_rrb(t_dnode **head, t_dnode *current,
			t_operation *curr_op, t_operation *next_op)
{
	int	min_rotations;

	if (!check_operation_pair(curr_op->name, next_op->name, "rb", "rrb"))
		return (0);
	if (curr_op->rotation_count < next_op->rotation_count)
		min_rotations = curr_op->rotation_count;
	else
		min_rotations = next_op->rotation_count;
	curr_op->rotation_count -= min_rotations;
	next_op->rotation_count -= min_rotations;
	if (!next_op->rotation_count)
		delete_node(head, current->next);
	if (!curr_op->rotation_count)
		delete_node(head, current);
	return (1);
}

static int	handle_rr_rrr(t_dnode **head, t_dnode *current,
			t_operation *curr_op, t_operation *next_op)
{
	int	min_rotations;

	if (!check_operation_pair(curr_op->name, next_op->name, "rr", "rrr"))
		return (0);
	if (curr_op->rotation_count < next_op->rotation_count)
		min_rotations = curr_op->rotation_count;
	else
		min_rotations = next_op->rotation_count;
	curr_op->rotation_count -= min_rotations;
	next_op->rotation_count -= min_rotations;
	if (!next_op->rotation_count)
		delete_node(head, current->next);
	if (!curr_op->rotation_count)
		delete_node(head, current);
	return (1);
}

int	optimize_rotations(t_dnode **head, t_dnode *current, int total)
{
	t_operation	*curr_op;
	t_operation	*next_op;

	if (!current || !current->next)
		return (0);
	curr_op = (t_operation *)current->data;
	next_op = (t_operation *)current->next->data;
	if (handle_rot(current, curr_op, total))
		return (1);
	if (handle_ra_rb(head, current, curr_op, next_op))
		return (1);
	if (handle_ra_rra(head, current, curr_op, next_op))
		return (1);
	if (handle_rb_rrb(head, current, curr_op, next_op))
		return (1);
	if (handle_rr_rrr(head, current, curr_op, next_op))
		return (1);
	return (0);
} //rra rrb?
