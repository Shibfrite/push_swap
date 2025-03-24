#include "push_swap.h"

void	sort_three(t_stacks *stacks, t_dnode **operations_list)
{
	int	a;
	int	b;
	int	c;

	a = *(int *)stacks->a->data;
	b = *(int *)stacks->a->next->data;
	c = *(int *)stacks->a->next->next->data;
	if (a > b && b < c && a < c)
		add_operation(operations_list, stacks, "sa", 1);
	else if (a > b && b > c)
	{
		add_operation(operations_list, stacks, "sa", 1);
		add_operation(operations_list, stacks, "rra", 1);
	}
	else if (a > b && b < c && a > c)
		add_operation(operations_list, stacks, "ra", 1);
	else if (a < b && b > c && a < c)
	{
		add_operation(operations_list, stacks, "sa", 1);
		add_operation(operations_list, stacks, "ra", 1);
	}
	else if (a < b && b > c && a > c)
		add_operation(operations_list, stacks, "rra", 1);
}

void	sort_turk(t_stacks *stacks, t_dnode **operations_list, int total)
{
	int	i;
	int	closest;

	i = total;
	while (stacks->a && i > 2)
	{
		if (stacks->b)
		{
			closest = get_closest_index(stacks->b, stacks->a);
			add_operation(operations_list, stacks, "rb", closest);
		}
		add_operation(operations_list, stacks, "pb", 1);
		i--;
	}
	while (stacks->b)
	{
		closest = get_closest_index(stacks->a, stacks->b);
		add_operation(operations_list, stacks, "ra", closest + 1);
		add_operation(operations_list, stacks, "pa", 1);
	}
	add_operation(operations_list, stacks, "ra", find_max_index(stacks->a) + 1);
}

void	sort_five(t_stacks *stacks, t_dnode **operations_list, int total)
{
	int	closest;

	printf("sort_five\n");
	add_operation(operations_list, stacks, "pb", 1);
	add_operation(operations_list, stacks, "pb", 1);
	sort_three(stacks, operations_list);
	add_operation(operations_list, stacks, "ra", closest);
	closest = lowest_cost_index(stacks->a, stacks->b, 3);
	add_operation(operations_list, stacks, "ra", closest);
	add_operation(operations_list, stacks, "pa", 1);
	closest = lowest_cost_index(stacks->a, stacks->b, 3);
	add_operation(operations_list, stacks, "ra", closest);
	add_operation(operations_list, stacks, "pa", 1);
	closest = find_max_index(stacks->a);
	add_operation(operations_list, stacks, "ra", closest);
	//ft_dlstclear(operations_list, free_operation);
}

void	sort_any(t_stacks *stacks, int total)
{
	t_dnode *operations_list;

	operations_list = NULL;
	if (total == 3)
		sort_three(stacks, &operations_list);
	else if (total == 5)
		sort_five(stacks, &operations_list, total);
	else
		sort_turk(stacks, &operations_list, total);
	optimize_operations(&operations_list, total);
	execute_operations(operations_list);
	ft_dlstclear(&operations_list, free_operation);
}

void	sort(int nbr_elements, t_stacks *stacks)
{
	if (nbr_elements == 2)
	{
		if (!is_sorted(stacks->a))
		{
			ft_putendl_fd("sa", 1);
			sa(stacks);
		}
	}
	sort_any(stacks, nbr_elements);
}
