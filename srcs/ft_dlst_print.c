/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:06:51 by makurek           #+#    #+#             */
/*   Updated: 2024/12/23 14:10:16 by makurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlst_print(t_dnode	*head)
{
	t_dnode	*current;

	if (!head)
	{
		printf("List is empty\n");
		return ;
	}
	current = head;
	while (current)
	{
		printf("%p ", current->data);
		current = current->next;
		if (current == head)
			break ;
	}
	printf("\n");
}
