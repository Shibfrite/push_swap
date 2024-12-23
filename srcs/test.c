#include "push_swap.h"
#include <stdio.h>

int	main(void)
{
	t_dnode	*headA = create_list(1, 5);
	if (!headA)
		return (1);
	t_dnode	*headB = create_list(1, 5);
	if (!headB)
		return (1);
	ft_dlst_rotate(&headA, 3);
	swap_last_nodes(headA);
	push_on_other(&headB, &headB);
	print_list(headA);
	print_list(headB);
	return (0);
}
