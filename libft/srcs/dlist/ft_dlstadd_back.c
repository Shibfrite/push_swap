/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_dlstadd_back.c                                   :+:    :+:           */
/*													+:+ +:+		 +:+	 */
/*   By: makurek <marvin@42lausanne.ch>			 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/07 17:40:42 by makurek		   #+#	#+#			 */
/*   Updated: 2025/03/31 14:43:44 by makurek        ########   odam.nl        */
/*																			*/
/* ************************************************************************** */

#include "libft_list.h"

void	ft_dlstadd_back(t_dnode **dlst, t_dnode *new)
{
	t_dnode	*last;

	if (dlst && *dlst)
	{
		last = ft_dlstlast(*dlst);
		last->next = new;
		new->prev = last;
	}
	else if (dlst)
		*dlst = new;
}
