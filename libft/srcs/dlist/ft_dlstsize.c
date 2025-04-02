/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_dlstsize.c                                       :+:    :+:           */
/*													+:+ +:+		 +:+	 */
/*   By: makurek <marvin@42lausanne.ch>			 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/07 17:41:09 by makurek		   #+#	#+#			 */
/*   Updated: 2025/03/31 14:49:20 by makurek        ########   odam.nl        */
/*																			*/
/* ************************************************************************** */

#include "libft_list.h"

int	ft_dlstsize(t_dnode *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
