/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   skip.c                                              :+:    :+:           */
/*													+:+ +:+		 +:+	 */
/*   By: makurek <marvin@42.fr>					 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/23 14:54:00 by makurek		   #+#	#+#			 */
/*   Updated: 2025/03/31 14:17:58 by makurek        ########   odam.nl        */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

char	*skip(const char *str, int is_something(const char))
{
	while (is_something(*str))
		str++;
	return ((char *)str);
}
