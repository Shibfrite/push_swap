#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "libft_list.h"

//temporary includes
# include <stdio.h>

t_dnode	*create_list(int start, int end);
t_dnode	*create_node(int value);
void	ft_dlst_print(t_dnode *head);
void	print_list(t_dnode *head);
void	push_on_other(t_dnode **first, t_dnode **second);
t_dnode	*remove_last_node(t_dnode **head);
void	swap_last_nodes(t_dnode	*head);

#endif
