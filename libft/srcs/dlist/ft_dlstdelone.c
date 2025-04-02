/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_dlstdelone.c                                     :+:    :+:           */
/*													+:+ +:+		 +:+	 */
/*   By: makurek <marvin@42lausanne.ch>			 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/07 17:40:51 by makurek		   #+#	#+#			 */
/*   Updated: 2025/03/31 14:44:59 by makurek        ########   odam.nl        */
/*																			*/
/* ************************************************************************** */

#include "libft_list.h"

void	ft_dlstdelone(t_dnode *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->data);
	free(lst);
}
