#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stacks	stacks;
	int			nbr_elements;

	stacks.a = NULL;
	stacks.b = NULL;
	nbr_elements = check_input(argc, argv, &stacks);
	if (nbr_elements == ERROR)
	{
        ft_dlstclear(&stacks.a, NULL);
        ft_dlstclear(&stacks.b, NULL);
		return (0);
	}
	print_list(stacks.a); //DEBUG
	sort(nbr_elements, &stacks);
	print_list(stacks.a); //DEBUG
	ft_dlstclear(&stacks.a, NULL);
	ft_dlstclear(&stacks.b, NULL);
	return (SUCCESS);
}
