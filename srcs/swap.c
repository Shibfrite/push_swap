/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   swap_first_node_nodes.c								  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: makurek <marvin@42.fr>					 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/23 14:07:48 by makurek		   #+#	#+#			 */
/*   Updated: 2024/12/23 14:10:35 by makurek		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_dnode **head)
{
	t_dnode	*second;
	t_dnode	*first;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	if (first->next)
		first->next->prev = first;
	*head = second;
}

static void	swap_print(t_stacks *stacks, char *op)
{
	if (!stacks)
		return ;
	if (!strcmp(op, "sa"))
		swap(&stacks->a);
	else if (!strcmp(op, "sb"))
		swap(&stacks->b);
	else
	{
		swap(&stacks->a);
		swap(&stacks->b);
	}
}

void	sa(t_stacks *stacks)
{
	swap_print(stacks, "sa");
}

void	sb(t_stacks *stacks)
{
	swap_print(stacks, "sb");
}

void	ss(t_stacks *stacks)
{
	swap_print(stacks, "ss");
}
