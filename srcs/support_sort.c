#include "push_swap.h"

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
	hash_table_init(&ht);
	nbr_elements = 0;
	i = 1;
	while (i < argc)
	{
		result = parse_string(argv[i], &stacks->a, &ht);
		if (result == ERROR)
		{
			printf("Error: Invalid input in argument %d.\n", i);
			ft_dlstclear(&stacks->a, NULL);
			return (ERROR);
		}
		nbr_elements += result;
		i++;
	}
	return (nbr_elements);
}

int	is_sorted(t_dnode *stack)
{
	while (stack && stack->next)
	{
		if (*(int *)stack->data > *(int *)stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	get_closest_index(t_dnode *first, t_dnode *second)
{
	t_dnode *current;
	int		target;
	int		closest_index;
	int		closest_data;
	int		index;
	int		current_data;

	current = first;
	target = *(int *)second->data;
	closest_index = -1;
	closest_data = INT_MIN;
	index = 0;
	while (current)
	{
		current_data = *(int *)current->data;
		if ((((current_data > closest_data) || (closest_data > target))
				&& current_data < target) || (current_data > target
				&& ((closest_data > target) || (closest_index == -1))
				&& current_data > closest_data))
		{
			closest_data = current_data;
			closest_index = index;
		}
		current = current->next;
		index++;
	}
	if (closest_index == -1)
		return (0);
	else
		return (closest_index);
}

int find_target_position(t_dnode *node, t_dnode *target_head) {
    t_dnode *current = target_head;
    int target_pos = 0;
    int target_val = INT_MIN;
    int max_val = INT_MIN;
    int max_pos = 0;
    int pos = 0;

    while (current) {
        // Cast node->data to int* and dereference to get the integer value
        int current_data = *(int *)current->data;
        int node_data = *(int *)node->data;

        // Track largest smaller value
        if (current_data < node_data && current_data > target_val) {
            target_val = current_data;
            target_pos = pos;
        }
        // Track overall maximum
        if (current_data > max_val) {
            max_val = current_data;
            max_pos = pos;
        }
        current = current->next;
        pos++;
    }
    return (target_val == INT_MIN) ? max_pos : target_pos;
}

int	find_max_index(t_dnode *head)
{
	t_dnode	*current;
	int		max_data;
	int		max_index;
	int		current_index;
	int		current_data;

	if (!head)
		return (-1);
	current = head;
	max_data = *(int *)current->data;
	max_index = 0;
	current_index = 0;
	while (current)
	{
		current_data = *(int *)current->data;
		if (current_data > max_data)
		{
			max_data = current_data;
			max_index = current_index;
		}
		current = current->next;
		current_index++;
	}
	return (max_index);
}
