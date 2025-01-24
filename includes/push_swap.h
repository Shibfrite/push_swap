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

typedef struct s_operation {
        char *name;
        int rotation_count;
} t_operation;

t_dnode	*create_list(int start, int end);
t_dnode	*create_node(int value);
void	ft_dlst_print(t_dnode *head);
void	print_list(t_dnode *head);
t_dnode	*remove_first_node(t_dnode **head);
int		parse_string(const char *str, t_dnode **dlist, hash_table *ht);
int		optimize_rotations(t_dnode **head, t_dnode *current, int total);
void	add_operation(t_dnode **head, t_stacks *stack, char *operation, int rotation_count);
void	optimize_operations(t_dnode **head, int total);
void	execute_operations(t_dnode *head);
void	free_operation(void *content);
void delete_node(t_dnode **head, t_dnode *node_to_delete);
void update_node_content(t_dnode *node, const char *new_name, int new_rotation_count);
int check_operation_pair(const char *op1, const char *op2, const char *val1, const char *val2);
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
