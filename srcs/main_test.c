#include "push_swap.h"

typedef struct s_rot_info
{
	int	rotation;
	int	is_sorted;
} t_rot_info;

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
		ra(stack, 1);
	}
	else if (a > b && b < c && a > c)
		rra(stack, 1);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		rra(stack, 1);
	}
	else if (a < b && b > c && a > c)
		ra(stack, 1);
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

t_rot_info get_rotations_to_sort(t_dnode *stack) {
	t_rot_info info = {0, 1};
	if (!stack || !stack->next)
		return info;

	t_dnode *current = stack;
	t_dnode *first = stack;
	int index = 0;
	int seen_breakpoint = 0;

	while (current->next) {
		if (*(int*)current->data > *(int*)current->next->data) {
			if (seen_breakpoint) {
				info.is_sorted = 0;
				return info;
			}
			seen_breakpoint = 1;
			info.rotations = index + 1;
		}
		index++;
		current = current->next;
	}

	if (*(int*)current->data > *(int*)first->data) {
		if (seen_breakpoint)
		{
			info.is_sorted = 0;
			return (info);
		}
		info.rotations = 0;
	}

	return info;
}

void sort_swap_recursive(t_stacks *stacks, t_list **operations_list) {
	t_rot_info rot_info = get_rotations_to_sort(stacks->a);
	printf("%d", rot_info.rotations);
	if (!rot_info.is_sorted)
	{
		if (rot_info.rotations)
			add_operation(operations_list, stacks, "rra", rot_info.rotations);
		add_operation(operations_list, stacks, "sa", 1);
		print_list(stacks->a);
		//sort_swap_recursive(stacks, operations_list);
	}
	else if (rot_info.rotations)
		add_operation(operations_list, stacks, "rra", rot_info.rotations);
}

void sort_three(t_stacks *stacks) {
	t_list *operations_list = NULL;
	sort_swap_recursive(stacks, &operations_list);
	execute_operations(operations_list);
	ft_lstclear(&operations_list, free_operation);
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
		sort_three(stacks);
	else if (nbr_elements == 4)
		sort_three(stacks);
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
