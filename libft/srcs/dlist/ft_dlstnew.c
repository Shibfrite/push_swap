/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_dlstnew.c                                        :+:    :+:           */
/*													+:+ +:+		 +:+	 */
/*   By: makurek <marvin@42lausanne.ch>			 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/07 17:41:07 by makurek		   #+#	#+#			 */
/*   Updated: 2025/03/31 14:47:02 by makurek        ########   odam.nl        */
/*																			*/
/* ************************************************************************** */

#include "libft_list.h"

t_dnode	*ft_dlstnew(void *data)
{
	t_dnode	*chain;

	chain = malloc(sizeof(*chain));
	if (!chain)
		return (NULL);
	chain->data = data;
	chain->prev = NULL;
	chain->next = NULL;
	return (chain);
}
