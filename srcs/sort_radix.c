#include "push_swap.h"

static int	count_stack_size(t_dnode *stack)
{
	int		count;
	t_dnode	*current;

	count = 0;
	current = stack;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

static void	radix_sort_stack_b(t_stacks *stacks,
		t_dnode **operations_list, int j)
{
	int	size;
	int	processed;

	size = count_stack_size(stacks->b);
	processed = 0;
	while (processed < size && stacks->b && is_sorted(stacks->a) == ERROR)
	{
		if (((*(int *)(stacks->b->data) >> j) & 1) == 0)
			add_operation(operations_list, stacks, "rb", 1);
		else
			add_operation(operations_list, stacks, "pa", 1);
		processed++;
	}
	while (stacks->b)
		add_operation(operations_list, stacks, "pa", 1);
}

static int	calculate_bit_size(int num)
{
	int	bit_size;

	bit_size = 0;
	while (num > 0)
	{
		num >>= 1;
		bit_size++;
	}
	return (bit_size);
}

static int	find_max_in_dlist(t_dnode *head)
{
	int		max_value;
	int		current_value;
	t_dnode	*current;

	if (!head)
		return (INT_MIN);
	max_value = *(int *)(head->data);
	current = head->next;
	while (current)
	{
		current_value = *(int *)(current->data);
		if (current_value > max_value)
			max_value = current_value;
		current = current->next;
	}
	return (max_value);
}

void	radix_sort(t_stacks *stacks, t_dnode **operations_list, int total)
{
	int	max_value;
	int	bit_size;
	int	j;
	int	size;

	max_value = find_max_in_dlist(stacks->a);
	if (max_value == INT_MIN)
		return ;
	bit_size = calculate_bit_size(max_value);
	j = -1;
	while (++j < bit_size)
	{
		size = total;
		while (size-- && stacks->a && is_sorted(stacks->a) == ERROR)
		{
			if (((*(int *)(stacks->a->data) >> j) & 1) == 0)
				add_operation(operations_list, stacks, "pb", 1);
			else
				add_operation(operations_list, stacks, "ra", 1);
		}
		radix_sort_stack_b(stacks, operations_list, j + 1);
	}
	while (stacks->b)
		add_operation(operations_list, stacks, "pa", 1);
}
