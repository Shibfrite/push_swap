/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_on_other.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:07:37 by makurek           #+#    #+#             */
/*   Updated: 2024/12/23 14:10:28 by makurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_on_other(t_dnode **first, t_dnode **second)
{
	t_dnode	*last;

	if (!first || !*first || !second)
		return ;
	last = remove_last_node(first);
	if (last)
		ft_dlstadd_back(second, last);
}
