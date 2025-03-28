/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   rotate.c                                            :+:    :+:           */
/*                                                      +:+                   */
/*   By: makurek <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/28 13:25:41 by makurek        #+#    #+#                */
/*   Updated: 2025/03/28 13:25:43 by makurek        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_print(t_stacks *stacks, int rotation, char *op)
{
	if (!stacks || !rotation || op[0] != 'r')
		return ;
	if (op[1] == 'a' || op[1] == 'r')
		ft_dlst_rotate(&stacks->a, rotation);
	if (op[1] == 'b' || op[1] == 'r')
		ft_dlst_rotate(&stacks->b, rotation);
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
