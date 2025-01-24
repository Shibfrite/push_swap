#include "push_swap.h"

static void	reverse_rotate_print(t_stacks *stacks, int rotation, char *op)
{
	if (!stacks || !rotation)
		return ;
	if (!strcmp(op, "rra"))
		ft_dlst_rotate(&stacks->a, -rotation);
	else if (!strcmp(op, "rrb"))
		ft_dlst_rotate(&stacks->b, -rotation);
	else
	{
		ft_dlst_rotate(&stacks->a, -rotation);
		ft_dlst_rotate(&stacks->b, -rotation);
	}
}

void	rra(t_stacks *stacks, int rotate)
{
	reverse_rotate_print(stacks, rotate, "rra");
}

void	rrb(t_stacks *stacks, int rotate)
{
	reverse_rotate_print(stacks, rotate, "rrb");
}

void	rrr(t_stacks *stacks, int rotate)
{
	reverse_rotate_print(stacks, rotate, "rrr");
}
