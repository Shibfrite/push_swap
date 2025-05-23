/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_dlstclear.c                                      :+:    :+:           */
/*													+:+ +:+		 +:+	 */
/*   By: makurek <marvin@42lausanne.ch>			 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/07 17:40:49 by makurek		   #+#	#+#			 */
/*   Updated: 2025/03/31 14:44:29 by makurek        ########   odam.nl        */
/*																			*/
/* ************************************************************************** */

#include "libft_list.h"

void	ft_dlstclear(t_dnode **dlst, void (*del)(void*))
{
	t_dnode	*tmp;

	while (*dlst)
	{
		tmp = (*dlst)->next;
		ft_dlstdelone(*dlst, del);
		*dlst = tmp;
	}
}
