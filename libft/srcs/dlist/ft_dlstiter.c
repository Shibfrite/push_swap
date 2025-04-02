/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_dlstiter.c                                       :+:    :+:           */
/*													+:+ +:+		 +:+	 */
/*   By: makurek <marvin@42lausanne.ch>			 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/07 17:40:59 by makurek		   #+#	#+#			 */
/*   Updated: 2025/03/31 14:49:04 by makurek        ########   odam.nl        */
/*																			*/
/* ************************************************************************** */

#include "libft_list.h"

void	ft_dlstiter(t_dnode *lst, void (*f)(void*))
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst->data);
		lst = lst->next;
	}
}
