/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:03:57 by makurek           #+#    #+#             */
/*   Updated: 2024/12/23 14:09:54 by makurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dnode	*create_list(int start, int end)
{
	t_dnode	*head;
	t_dnode	*new_node;
	int		i;

	head = NULL;
	i = start;
	while (i <= end)
	{
		new_node = create_node(i++);
		if (!new_node)
			return (NULL);
		ft_dlstadd_back(&head, new_node);
	}
	return (head);
}
