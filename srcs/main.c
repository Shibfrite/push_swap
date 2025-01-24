#include "push_swap.h"

int	check_input(int argc, char *argv[], t_stacks *stacks)
{
	int i;
	int result;
	int nbr_elements;

	if (argc < 2)
	{
		printf("Error: Not enough arguments provided.\n");
		return (ERROR);
	}
	hash_table ht;
	hash_table_init(&ht);
	nbr_elements = 0;
	for (i = 1; i < argc; i++)
	{
		result = parse_string(argv[i], &stacks->a, &ht);

		if (result == ERROR)
		{
			printf("Error: Invalid input in argument %d.\n", i);
			ft_dlstclear(&stacks->a, NULL);
			return (ERROR);
		}
		nbr_elements += result;
	}
	return (nbr_elements);
}

void sort_three_hardcode(t_stacks *stack)
{
	int a = *(int*)stack->a->data;
	int b = *(int*)stack->a->next->data;
	int c = *(int*)stack->a->next->next->data;

	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack, 1);
	}
	else if (a > b && b < c && a > c)
		ra(stack, 1);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack, 1);
	}
	else if (a < b && b > c && a > c)
		rra(stack, 1);
}

int is_sorted(t_dnode *stack)
{
	while (stack && stack->next)
	{
		if (*(int*)stack->data > *(int*)stack->next->data)
			return 0;
		stack = stack->next;
	}
	return 1;
}

int get_closest_index(t_dnode *first, t_dnode *second)
{
	t_dnode *current = first;
	int target = *(int*)second->data;
	int closest_index = -1;
	int closest_value = INT_MIN;
	int index = 0;

	while (current) {
		int current_value = *(int*)current->data;
		if ((((current_value > closest_value) || (closest_value > target)) && current_value < target) || (current_value > target && ((closest_value > target) || (closest_index == -1)) && current_value > closest_value))
		{
			closest_value = current_value;
			closest_index = index;
		}
		current = current->next;
		index++;
	}
	return (closest_index == -1) ? 0 : closest_index;
}

int find_max_index(t_dnode *head)
{
	if (!head)
		return -1;

	t_dnode *current = head;
	int max_value = *(int*)current->data;
	int max_index = 0;
	int current_index = 0;

	while (current)
	{
		int current_value = *(int*)current->data;
		if (current_value > max_value)
		{
			max_value = current_value;
			max_index = current_index;
		}
		current = current->next;
		current_index++;
	}

	return max_index;
}

void sort_turk(t_stacks *stacks, t_dnode **operations_list, int total)
{
	int i;
	int closest;	

	i = total;
	while (stacks->a && i > 2)
	{
		if (stacks->b) {
			closest = get_closest_index(stacks->b, stacks->a);
			add_operation(operations_list, stacks, "rb", closest);
		}
		add_operation(operations_list, stacks, "pb", 1);
		i--;
	}
	while (stacks->b)
	{
		closest = get_closest_index(stacks->a, stacks->b);
		add_operation(operations_list, stacks, "ra", closest + 1);
		add_operation(operations_list, stacks, "pa", 1);
	}
	add_operation(operations_list, stacks, "ra", find_max_index(stacks->a) + 1);
}

void sort_three(t_stacks *stacks, int total)
{
	t_dnode *operations_list = NULL;
	sort_turk(stacks, &operations_list, total);
	optimize_operations(&operations_list, total);
	execute_operations(operations_list);
	ft_dlstclear(&operations_list, free_operation);
}

void	sort(int nbr_elements, t_stacks *stacks)
{
	if (nbr_elements == 2)
		if (!is_sorted(stacks->a))
		{
			ft_putendl_fd("sa", 1);
			sa(stacks);
		}
	if (nbr_elements == 3)
		sort_three_hardcode(stacks);
	else if (nbr_elements > 3)
		sort_three(stacks, nbr_elements);
}

int main(int argc, char *argv[])
{
	t_stacks	stacks;
	int			nbr_elements;

	stacks.a = NULL;
	stacks.b = NULL;
	nbr_elements = check_input(argc, argv, &stacks);
	if (nbr_elements == ERROR)
		return (0);
	print_list(stacks.a);
	sort(nbr_elements, &stacks);
	print_list(stacks.a);

	ft_dlstclear(&stacks.a, NULL);
	return (SUCCESS);
}
