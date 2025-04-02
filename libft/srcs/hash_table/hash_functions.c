/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   hash_functions.c                                    :+:    :+:           */
/*                                                      +:+                   */
/*   By: makurek <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/31 14:19:05 by makurek        #+#    #+#                */
/*   Updated: 2025/03/31 16:11:26 by makurek        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "hash_table.h"

size_t	hash_multiplication(const void *key)
{
	const char		*str_key;
	size_t			len;
	size_t			i;
	unsigned int	hash_value;

	str_key = (const char *)key;
	len = ft_strlen(str_key);
	hash_value = 0;
	i = 0;
	while (i < len)
	{
		hash_value += str_key[i];
		hash_value *= str_key[i++];
		hash_value %= TABLE_SIZE;
	}
	return (hash_value);
}
