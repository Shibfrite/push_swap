#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "libft_list.h"
# include "hash_table.h"
#include <limits.h>
//temporary includes
# include <stdio.h>

#define SUCCESS 0
#define ERROR -1

typedef struct s_stacks {
    t_dnode *a;
    t_dnode *b;
} t_stacks;

t_dnode	*create_list(int start, int end);
t_dnode	*create_node(int value);
void	ft_dlst_print(t_dnode *head);
void	print_list(t_dnode *head);
t_dnode	*remove_first_node(t_dnode **head);
int		parse_string(const char *str, t_dnode **dlist, hash_table *ht);
void	add_operation(t_list **head, t_stacks *stack, char *operation, int rotation_count);
void	optimize_operations(t_list **head);
void	execute_operations(t_list *head);
void	free_operation(void *content);
void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);
void    ra(t_stacks *stacks, int rotate);
void    rb(t_stacks *stacks, int rotate);
void    rr(t_stacks *stacks, int rotate);
void    rra(t_stacks *stacks, int rotate);
void    rrb(t_stacks *stacks, int rotate);
void    rrr(t_stacks *stacks, int rotate);
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);

#endif
