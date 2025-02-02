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
	print_list(stacks.a);
	sort(nbr_elements, &stacks);
	print_list(stacks.a);
	ft_dlstclear(&stacks.a, NULL);
	return (SUCCESS);
}
