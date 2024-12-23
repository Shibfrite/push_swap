/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_last_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:07:42 by makurek           #+#    #+#             */
/*   Updated: 2024/12/23 14:10:32 by makurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dnode	*remove_last_node(t_dnode	**head)
{
	t_dnode	*last;

	last = ft_dlstlast(*head);
	if (!last)
		return (NULL);
	if (last->prev)
		last->prev->next = NULL;
	else
		*head = NULL;
	last->prev = NULL;
	last->next = NULL;
	return (last);
}
