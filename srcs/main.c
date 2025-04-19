/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   main.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: makurek <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/28 16:39:55 by makurek        #+#    #+#                */
/*   Updated: 2025/04/02 17:42:32 by makurek        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_lowest_value_above_threshold(t_dnode *head, int threshold) {
    if (!head) return INT_MAX;
    int min_value = INT_MAX;
    t_dnode *current = head;

    while (current) {
        int current_value = *(int *)(current->data);
        if (current_value > threshold && current_value < min_value) {
            min_value = current_value; // Update min_value if a smaller valid value is found
        }
        current = current->next;
    }
    return min_value; // Return INT_MAX if no valid value was found
}

void replace_values_in_dlist(t_dnode *head) {
    if (!head) return; // Empty list

    int threshold = INT_MIN; // Start with the smallest possible integer
    int replacement_value = 0; // Replacement starts at 0

    while (1) {
        int lowest_value = find_lowest_value_above_threshold(head, threshold);
        if (lowest_value == INT_MAX) break;
        t_dnode *current = head;
        while (current) {
            if (*(int *)(current->data) == lowest_value) {
                *(int *)(current->data) = replacement_value;
                break;
            }
            current = current->next;
        }
        threshold = lowest_value;
        replacement_value++;
    }
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
//print_list(stacks.a); //DEBUG
