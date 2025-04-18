/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_dlstmap.c                                        :+:    :+:           */
/*													+:+ +:+		 +:+	 */
/*   By: makurek <marvin@42lausanne.ch>			 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/07 17:41:04 by makurek		   #+#	#+#			 */
/*   Updated: 2025/03/31 14:46:42 by makurek        ########   odam.nl        */
/*																			*/
/* ************************************************************************** */

#include "libft_list.h"

t_dnode	*ft_dlstmap(t_dnode *lst, void *(*f)(void*), void (*del)(void *))
{
	t_dnode	*new_list;
	t_dnode	*new_node;

	new_list = NULL;
	while (lst)
	{
		new_node = ft_dlstnew(f(lst->data));
		if (!new_node)
		{
			ft_dlstclear(&new_list, del);
			return (NULL);
		}
		ft_dlstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
