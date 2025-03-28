/* ************************************************************************** */
/*										*/
/*							:::	  ::::::::   */
/*   push.c                                              :+:    :+:           */
/*							+:+ +:+	 +:+	 */
/*   By: makurek <marvin@42.fr>			 +#+  +:+	   +#+	*/
/*						+#+#+#+#+#+   +#+	   */
/*   Created: 2024/12/23 14:07:37 by makurek	   #+#	#+#		 */
/*   Updated: 2025/03/27 18:04:50 by makurek        ########   odam.nl        */
/*										*/
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_dnode **first_stack, t_dnode **second_stack)
{
	t_dnode	*first_node;

	if (!first_stack || !*first_stack || !second_stack)
		return ;
	first_node = remove_first_node(first_stack);
	if (first_node)
		ft_dlstadd_front(second_stack, first_node);
}

static void	push_print(t_stacks *stacks, char *op)
{
	if (!stacks || op[0] != 'p')
		return ;
	if (op[1] == 'a')
		push(&stacks->b, &stacks->a);
	else if (op[1] == 'b')
		push(&stacks->a, &stacks->b);
}

void	pa(t_stacks *stacks)
{
	push_print(stacks, "pa");
}

void	pb(t_stacks *stacks)
{
	push_print(stacks, "pb");
}
