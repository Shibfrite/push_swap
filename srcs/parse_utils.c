/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   parse_utils.c                                       :+:    :+:           */
/*                                                      +:+                   */
/*   By: makurek <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/31 12:50:21 by makurek        #+#    #+#                */
/*   Updated: 2025/03/31 18:12:43 by makurek        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (is_sign(**str))
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

static int	parse_number(const char **str, int *num)
{
	long long	temp;
	int			sign;

	temp = 0;
	sign = handle_sign(str);
	if (!ft_isdigit(**str))
		return (ERROR);
	while (ft_isdigit(**str))
	{
		temp = temp * 10 + (**str - '0');
		if (temp * sign > INT_MAX || temp * sign < INT_MIN)
			return (ERROR);
		(*str)++;
	}
	*num = (int)(temp * sign);
	return (SUCCESS);
}

static int	add_to_list(t_dnode **dlist, int num)
{
	t_dnode	*new_node;

	new_node = create_node(num);
	if (!new_node)
		return (ERROR);
	ft_dlstadd_back(dlist, new_node);
	return (SUCCESS);
}

static int	parse_and_validate_number(const char **str, int *num,
			t_dnode **dlist, t_hash_table *ht)
{
	if (parse_number(str, num) == ERROR)
		return (ERROR);
	if (add_to_list(dlist, *num) == ERROR)
	{
		ft_dlstclear(dlist, free);
		return (ERROR);
	}
	if (hash_table_insert(ht, num, sizeof(*num)) == ERROR)
	{
		ft_dlstclear(dlist, free);
		return (ERROR);
	}
	return (SUCCESS);
}

int	parse_string(const char *str, t_dnode **dlist, t_hash_table *ht)
{
	int	num;
	int	count;

	if (!str || !dlist || !ht)
		return (ERROR);
	count = 0;
	while (*str)
	{
		str = skip(str, is_space);
		if (!*str)
			break ;
		if (parse_and_validate_number(&str, &num, dlist, ht) == ERROR)
			return (ERROR);
		count++;
	}
	return (count);
}
