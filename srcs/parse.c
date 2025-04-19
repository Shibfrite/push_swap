/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   parse.c                                             :+:    :+:           */
/*                                                      +:+                   */
/*   By: makurek <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/31 12:33:36 by makurek        #+#    #+#                */
/*   Updated: 2025/04/02 17:42:46 by makurek        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	process_arguments(int argc, char *argv[],
			t_stacks *stacks, t_hash_table *ht)
{
	int	i;
	int	result;
	int	nbr_elements;

	nbr_elements = 0;
	i = 1;
	while (i < argc)
	{
		result = parse_string(argv[i], &stacks->a, ht);
		if (result == ERROR)
		{
			ft_putendl("Error: Invalid input");
			return (ERROR);
		}
		nbr_elements += result;
		i++;
	}
	return (nbr_elements);
}

int	check_input(int argc, char *argv[], t_stacks *stacks)
{
	t_hash_table	ht;
	int				result;

	if (argc < 2)
	{
		ft_putendl("Error: Not enough arguments provided.");
		return (ERROR);
	}
	if (hash_table_init(&ht) == ERROR)
		return (ERROR);
	result = process_arguments(argc, argv, stacks, &ht);
	hash_table_destroy(&ht);
	return (result);
}
