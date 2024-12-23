/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:06:47 by makurek           #+#    #+#             */
/*   Updated: 2024/12/23 14:45:22 by makurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dnode	*create_node(int value)
{
	int		*num;
	t_dnode	*new_node;

	num = malloc(sizeof(int));
	if (!num)
		return (NULL);
	*num = value;
	new_node = ft_dlstnew(num);
	if (!new_node)
	{
		free(num);
		return (NULL);
	}
	return (new_node);
}
