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

t_dnode *remove_first_node(t_dnode **head)
{
    t_dnode *first;

    if (!(head && *head))
        return (NULL);
    first = *head;
    *head = first->next;
    if (*head)
        (*head)->prev = NULL;
    first->prev = NULL;
    first->next = NULL;
    return (first);
}
