/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   main.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: makurek <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/28 16:39:55 by makurek        #+#    #+#                */
/*   Updated: 2025/03/28 16:40:25 by makurek        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stacks	stacks;
	int			nbr_elements;

	stacks.a = NULL;
	stacks.b = NULL;
	nbr_elements = check_input(argc, argv, &stacks);
	if (nbr_elements == ERROR)
		return (0);
	sort(nbr_elements, &stacks);
	ft_dlstclear(&stacks.a, NULL);
	ft_dlstclear(&stacks.b, NULL);
	return (SUCCESS);
}
//print_list(stacks.a); //DEBUG
