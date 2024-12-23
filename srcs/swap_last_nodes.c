/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_last_nodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:07:48 by makurek           #+#    #+#             */
/*   Updated: 2024/12/23 14:10:35 by makurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_last_nodes(t_dnode	*head)
{
	t_dnode	*last;
	t_dnode	*before_last;

	if (!head || !head->next || !head->next->next)
		return ;
	last = ft_dlstlast(head);
	before_last = last->prev;
	before_last->prev->next = last;
	last->prev = before_last->prev;
	last->next = before_last;
	before_last->prev = last;
	before_last->next = NULL;
}
