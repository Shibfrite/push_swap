/* ************************************************************************** */
/*																			*/
/*														 ::::::::		   */
/*   sort.c											  :+:	:+:		   */
/*													  +:+				   */
/*   By: makurek <marvin@42.fr>						+#+					*/
/*													+#+					 */
/*   Created: 2025/03/27 15:58:39 by makurek		#+#	#+#				*/
/*   Updated: 2025/04/02 20:12:50 by makurek		########   odam.nl		*/
/*																			*/
/* ************************************************************************** */

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

void	sort_five(t_stacks *stacks, t_dnode **operations_list)
{
	int	closest;
	int	var;
	int	current_total;

	add_operation(operations_list, stacks, "pb", 1);
	add_operation(operations_list, stacks, "pb", 1);
	sort_three(stacks, operations_list);
	current_total = 3;
	while (stacks->b)
	{
		closest = lowest_cost_index(stacks->b, stacks->a, 2);
		add_operation(operations_list, stacks, "rb", closest);
		var = find_target_position(stacks->b, stacks->a) + 1;
		if (var <= current_total / 2)
			add_operation(operations_list, stacks, "ra", var);
		else
			add_operation(operations_list, stacks, "rra", current_total - var);
		add_operation(operations_list, stacks, "pa", 1);
		current_total++;
	}
	closest = (find_max_index(stacks->a) + 1) % current_total;
	if (closest <= current_total / 2)
		add_operation(operations_list, stacks, "ra", closest);
	else
		add_operation(operations_list, stacks, "rra", current_total - closest);
}

void	sort_any(t_stacks *stacks, int total)
{
	t_dnode	*operations_list;

	operations_list = NULL;
	if (total == 3)
		sort_three(stacks, &operations_list);
	else if (total == 5)
		sort_five(stacks, &operations_list);
	else
		radix_sort(stacks, &operations_list, total);
	optimize_operations(&operations_list);
	execute_operations(operations_list);
	ft_dlstclear(&operations_list, free_operation);
}

void	sort(int nbr_elements, t_stacks *stacks)
{
	if (is_sorted(stacks->a) == SUCCESS)
		return ;
	if (nbr_elements == 2)
	{
		ft_putendl("sa");
		sa(stacks);
		return ;
	}
	sort_any(stacks, nbr_elements);
}
