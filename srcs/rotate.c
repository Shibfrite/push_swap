#include "push_swap.h"

static void rotate_print(t_stacks *stacks, int rotation, char *op)
{
	if (!stacks || !rotation)
		return ;
	if (!strcmp(op, "ra"))
		ft_dlst_rotate(&stacks->a, rotation);
	else if (!strcmp(op, "rb"))
		ft_dlst_rotate(&stacks->b, rotation);
	else
	{
		ft_dlst_rotate(&stacks->a, rotation);
		ft_dlst_rotate(&stacks->b, rotation);
	}
}

void	ra(t_stacks *stacks, int rotate)
{
	rotate_print(stacks, rotate, "ra");
}

void	rb(t_stacks *stacks, int rotate)
{
	rotate_print(stacks, rotate, "rb");
}

void	rr(t_stacks *stacks, int rotate)
{
	rotate_print(stacks, rotate, "rr");
}
