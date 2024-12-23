/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:07:31 by makurek           #+#    #+#             */
/*   Updated: 2024/12/23 14:10:24 by makurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_dnode	*head)
{
	t_dnode	*current;

	current = head;
	printf("List contents: ");
	while (current)
	{
		printf("%d ", *(int *)current->data);
		current = current->next;
	}
	printf("\n");
}
