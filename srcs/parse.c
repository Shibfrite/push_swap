/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   parse.c                                             :+:    :+:           */
/*                                                      +:+                   */
/*   By: makurek <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/28 13:23:15 by makurek        #+#    #+#                */
/*   Updated: 2025/03/28 16:38:59 by makurek        ########   odam.nl        */
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
		else
			sign = 1;
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

int	parse_string(const char *str, t_dnode **dlist, hash_table *ht)
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
		if (parse_number(&str, &num) == ERROR)
			return (ERROR);
		if (add_to_list(dlist, num) == ERROR)
		{
			ft_dlstclear(dlist, free);
			return (ERROR);
		}
		if (hash_table_insert(ht, &num, sizeof(num)) == ERROR)
		{
			ft_dlstclear(dlist, free);
			return (ERROR);
		}
		count++;
	}
	return (count);
}

int	check_input(int argc, char *argv[], t_stacks *stacks)
{
	int			i;
	int			result;
	int			nbr_elements;
	hash_table	ht;

	if (argc < 2)
	{
		printf("Error: Not enough arguments provided.\n");
		return (ERROR);
	}
	if (hash_table_init(&ht) == ERROR)
		return (ERROR);
	nbr_elements = 0;
	i = 1;
	while (i < argc)
	{
		result = parse_string(argv[i], &stacks->a, &ht);
		if (result == ERROR)
		{
			printf("Error: Invalid input in argument %d.\n", i);
			return (ERROR);
		}
		nbr_elements += result;
		i++;
	}
	return (nbr_elements);
}
