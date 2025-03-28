/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   reverse_rotate.c                                    :+:    :+:           */
/*                                                      +:+                   */
/*   By: makurek <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/28 13:25:50 by makurek        #+#    #+#                */
/*   Updated: 2025/03/28 13:25:51 by makurek        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_print(t_stacks *stacks, int rotation, char *op)
{
	if (!stacks || !rotation || op[0] != 'r' || op[1] != 'r')
		return ;
	if (op[2] == 'a' || op[2] == 'r')
		ft_dlst_rotate(&stacks->a, -rotation);
	if (op[2] == 'b' || op[2] == 'r')
		ft_dlst_rotate(&stacks->b, -rotation);
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
