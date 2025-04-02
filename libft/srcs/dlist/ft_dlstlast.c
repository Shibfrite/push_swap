/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_dlstlast.c                                       :+:    :+:           */
/*													+:+ +:+		 +:+	 */
/*   By: makurek <marvin@42lausanne.ch>			 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/07 17:41:01 by makurek		   #+#	#+#			 */
/*   Updated: 2025/03/31 14:45:42 by makurek        ########   odam.nl        */
/*																			*/
/* ************************************************************************** */

#include "libft_list.h"

t_dnode	*ft_dlstlast(t_dnode *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
