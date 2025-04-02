/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   utility.c                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: makurek <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/31 14:33:20 by makurek        #+#    #+#                */
/*   Updated: 2025/03/31 16:14:58 by makurek        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "hash_table.h"

int	compare_strings(const void *a, const void *b)
{
	return (ft_strncmp((const char *)a, (const char *)b, MAX_NAME));
}
