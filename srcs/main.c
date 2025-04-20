/* ************************************************************************** */
/*																			*/
/*														 ::::::::		   */
/*   main.c											  :+:	:+:		   */
/*													  +:+				   */
/*   By: makurek <marvin@42.fr>						+#+					*/
/*													+#+					 */
/*   Created: 2025/03/28 16:39:55 by makurek		#+#	#+#				*/
/*   Updated: 2025/04/02 17:42:32 by makurek		########   odam.nl		*/
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

int	find_lowest_value_above_threshold(t_dnode *head, int threshold)
{
	int		min_value;
	t_dnode	*current;
	int		current_value;

	if (!head)
		return (INT_MAX);
	min_value = INT_MAX;
	current = head;
	while (current)
	{
		current_value = *(int *)(current->data);
		if (current_value > threshold && current_value < min_value)
			min_value = current_value;
		current = current->next;
	}
	return (min_value);
}

void	replace_values_in_dlist(t_dnode *head)
{
	int	threshold;
	int	replacement_value;

	if (!head)
		return ;
	threshold = INT_MIN;
	replacement_value = 0;
	while (1)
		if (!find_and_replace_next_value(head, &threshold, &replacement_value))
			break ;
}

int	find_and_replace_next_value(t_dnode *head,
			int *threshold, int *replacement_value)
{
	int		lowest_value;
	t_dnode	*current;

	lowest_value = find_lowest_value_above_threshold(head, *threshold);
	if (lowest_value == INT_MAX)
		return (0);
	current = head;
	while (current)
	{
		if (*(int *)(current->data) == lowest_value)
		{
			*(int *)(current->data) = *replacement_value;
			break ;
		}
		current = current->next;
	}
	*threshold = lowest_value;
	(*replacement_value)++;
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;
	int			nbr_elements;

	stacks.a = NULL;
	stacks.b = NULL;
	nbr_elements = check_input(argc, argv, &stacks);
	replace_values_in_dlist(stacks.a);
	if (nbr_elements != ERROR)
		sort(nbr_elements, &stacks);
	if (stacks.a)
		ft_dlstclear(&stacks.a, free);
	if (stacks.b)
		ft_dlstclear(&stacks.b, free);
	return (SUCCESS);
}
//print_list(stacks.a);
