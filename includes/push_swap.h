/* ************************************************************************** */
/*																			*/
/*														 ::::::::
//   */
/*   push_swap.h										 :+:
//:+:		   */
/*													  +:+				   */
/*   By: makurek <marvin@42.fr>						+#+					*/
/*													+#+					 */
/*   Created: 2025/03/27 16:58:30 by makurek		#+#	#+#				*/
/*   Updated: 2025/03/31 13:34:24 by makurek		########   odam.nl		*/
/*																			*/
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "libft_list.h"
# include "hash_table.h"
# include <limits.h>
# define SUCCESS 0
# define ERROR -1

typedef struct s_stacks
{
	t_dnode	*a;
	t_dnode	*b;
}	t_stacks;

typedef struct s_operation
{
	char	*name;
	int		rotation_count;
}	t_operation;

//-- FILES AND FUNCTIONS --
//functions under comment are local

//ft_dlst_print.c
void	ft_dlst_print(t_dnode *head);

//create_list.c
t_dnode	*create_list(int start, int end);

//create_node.c
t_dnode	*create_node(int value);

//print_list.c
void	print_list(t_dnode *head);

//remove_last_node.c
t_dnode	*remove_first_node(t_dnode **head);

//-----------------------------------------------------------------

//======main.c======

//-----------------------------------------------------------------

//Prototype:
//int	main(int argc, char *argv[])
//Input:
//argc, argv (arguments), stacks (A/B).
//Output:
//0 (success) or ERROR.
//Purpose:
//Validates input, initializes stacks A/B, sorts, frees memory.

//-----------------------------------------------------------------

//  ======parse.c======

//-----------------------------------------------------------------

//Prototype:
//static int process_arguments(int argc, char *argv[],
//								t_stacks *stacks, t_hash_table *ht)
//Input:
//argc, argv (arguments), stacks (to populate A), hash table for duplicates.
//Output:
//Total number of elements parsed or ERROR.
//Purpose:
//Iterates through arguments, parses each string, and populates stack A.
//Note:
//Reports errors with argument index if parsing fails.

//-----------------------------------------------------------------

//Prototype:
int		check_input(int argc, char *argv[], t_stacks *stacks);
//Input:
//argc, argv (arguments), stacks (to populate A).
//Output:
//Number of elements or `ERROR`.
//Purpose:
//Validates input, initializes hash table, and processes arguments.
//Note:
//Hash table (`ht`) not freed on early exit (potential memory leak).

//-----------------------------------------------------------------

//  ======parse_utils.c======

//-----------------------------------------------------------------

//Prototype:
//static int handle_sign(const char **str)  
//Input:
//String pointer (modified in-place).  
//Output:
//Sign (+1/-1).
//Purpose:
//Extracts sign from number string.  
//Note:
//

//-----------------------------------------------------------------

//Prototype:
//static int parse_number(const char **str, int *num)  
//Input:
//String pointer (modified in-place), output number.  
//Output:
//SUCCESS/ERROR.  
//Purpose:
//Converts string to integer, checks overflow.  
//Note:

//-----------------------------------------------------------------

//Prototype:
//static int add_to_list(t_dnode **dlist, int num)  
//Input:
//List head, number to add.  
//Output:
//SUCCESS/ERROR.  
//Purpose:
//Appends number to stack A.  
//Note:
//

//-----------------------------------------------------------------

//Prototype:
//static int parse_and_validate_number(const char **str, int *num,
//										t_dnode **dlist, hash_table *ht)
//Input:
//String pointer (modified in-place), output number, list head,
//hash table for duplicates.
//Output:
//SUCCESS/ERROR.
//Purpose:
//Parses a number, validates it, adds to list, and inserts into hash table.
//Note:
//

//-----------------------------------------------------------------

//Prototype:
int		parse_string(const char *str, t_dnode **dlist, t_hash_table *ht);
//Input:
//Input string, stack A list, hash table for duplicates.  
//Output:
//Element count or ERROR.
//Purpose:
//Parses numbers from string, adds to list, checks duplicates.  
//Note:
//

//-----------------------------------------------------------------

//======operation.c=====

//-----------------------------------------------------------------

//Prototype:
//
//void execute_single_operation(t_stacks *stacks,
//						const char *op_name, int rotation_count)  
//Input:
//Stacks, operation name, rotation count.  
//Output:
//None.  
//Purpose:
//Maps command names to stack operations (e.g., "sa" → `sa()`).  
//Note:
//inefficient but concise.

//-----------------------------------------------------------------

void	add_operation(t_dnode **head, t_stacks *stack,
			char *operation, int rotation_count);
//Input:
//Operation list head, stacks, command name, rotation count.
//Output:
//None.
//Purpose:
//Adds command to list and executes it immediately.
//Note:
//Executes command **before** ensuring node creation success

//-----------------------------------------------------------------

void	execute_operations(t_dnode *head);
//Input:
//List of operations.
//Output:
//Prints commands to stdout.
//Purpose:
//Outputs optimized command sequence (with rotation counts).
//Note:
//

//-----------------------------------------------------------------

void	free_operation(void *content);
//Input:
//Operation data (to free).
//Output:
//None.
//Purpose:
//Frees `t_operation` (name + struct).
//Note:
//

//-----------------------------------------------------------------

//======push.c======

//-----------------------------------------------------------------

//Prototype:
//static void push(t_dnode **first_stack, t_dnode **second_stack)  
//Input:
//Source stack, destination stack.  
//Output:
//None.  
//Purpose:
//Moves first node from `first_stack` to `second_stack`.  
//Note:
//

//-----------------------------------------------------------------

//Prototype:
//static void push_print(t_stacks *stacks, char *op)  
//Input:
//Stacks, operation name (`"pa"`/`"pb"`).  
//Output:
//None.  
//Purpose:
//Executes and tracks push operations.  
//Note:

//-----------------------------------------------------------------

void	pa(t_stacks *stacks);
//Input:
//Stacks.
//Output:
//None.
//Purpose:
//Pushes top of B to A.
//Note:

//-----------------------------------------------------------------

void	pb(t_stacks *stacks);
//Input:
//Stacks.
//Output:
//None.
//Purpose:
//Pushes top of A to B.
//Note:

//-----------------------------------------------------------------

//======rotate.c======

//-----------------------------------------------------------------

//Prototype:
//static void rotate_print(t_stacks *stacks, int rotation, char *op)
//Input:
//Stacks, rotation count, operation name.
//Output:
//None.
//Purpose:
//Applies rotations.
//Note:

//-----------------------------------------------------------------

void	ra(t_stacks *stacks, int rotate);
//Input:
//Stacks, rotation count.
//Output:
//None.
//Purpose:
//Rotates stack A.
//Note:

//-----------------------------------------------------------------

void	rb(t_stacks *stacks, int rotate);
//Input:
//Stacks, rotation count.
//Output:
//None.
//Purpose:
//Rotates stack B.
//Note:

//-----------------------------------------------------------------

void	rr(t_stacks *stacks, int rotate);
//File:
//rotate.c
//Prototype:
//void rr(t_stacks *stacks, int rotate)
//Input:
//Stacks, rotation count.
//Output:
//None.
//Purpose:
//Rotates both stacks.
//Note:
//

//-----------------------------------------------------------------

//======reverse_rotate.c======

//-----------------------------------------------------------------

//Prototype:
//static void reverse_rotate_print(t_stacks *stacks, int rotation, char *op)  
//Input:
//Stacks, rotation count, operation name.  
//Output:
//None.
//Purpose:
//Applies reverse rotations.  
//Note:
//

//-----------------------------------------------------------------

void	rra(t_stacks *stacks, int rotate);
//Input:
//Stacks, rotation count.
//Output:
//None.
//Purpose:
//Reverse-rotates stack A.
//Note:

//-----------------------------------------------------------------

void	rrb(t_stacks *stacks, int rotate);
//Input:
//Stacks, rotation count.
//Output:
//None.
//Purpose:
//Reverse-rotates stack B.
//Note:

//-----------------------------------------------------------------

void	rrr(t_stacks *stacks, int rotate);
//Input:
//Stacks, rotation count.
//Output:
//None.
//Purpose:
//Reverse-rotates both stacks.
//Note:

//-----------------------------------------------------------------

//======rotations.c======

//-----------------------------------------------------------------

//NOT USED, DOESN'T WORK PROPERLY

//handle_ra_rb
//Prototype:
//static int handle_ra_rb(...)  
//Input:
//Nodes/operations to merge.  
//Output:
//`1` (merged) or `0`.  
//Purpose:
//Merges `ra` + `rb` → `rr`.  
//Note:
//

//-----------------------------------------------------------------

//Prototype:
//static int handle_ra_rra(...)  
//Input:
//Nodes/operations to cancel.  
//Output:
//`1` (canceled) or `0`.  
//Purpose:
//Cancels `ra` + `rra` pairs.  
//Note:
//

//-----------------------------------------------------------------

//NOT USED, DOESN'T WORK PROPERLY

//Prototype:
//static int handle_rot(...)  
//Input:
//Current node/operation.  
//Output:
//`1` (optimized) or `0`.  
//Purpose:
//Replaces rotations with reverse if shorter
//Note:
//Uses `total` (stack size) incorrectly
//(should use current stack size dynamically).  

//-----------------------------------------------------------------

//Prototype:
//static int handle_rb_rrb(...)  
//Input:
//Nodes/operations to cancel.  
//Output:
//`1` (canceled) or `0`.  
//Purpose:
//Cancels `rb` + `rrb` pairs.  
//Note:
//

//-----------------------------------------------------------------

//Prototype:
//static int handle_rr_rrr(...)  
//Input:
//Nodes/operations to cancel.  
//Output:
//`1` (canceled) or `0`.  
//Purpose:
//Cancels `rr` + `rrr` pairs.  
//Note:
//

//-----------------------------------------------------------------

int		optimize_rotations(t_dnode **head, t_dnode *current);
//Input:
//List head, current node, total elements.
//Output:
//`1` (changes made) or `0`.
//Purpose:
//Merges/cancels rotation commands (e.g., `ra` + `rb` → `rr`).
//Note:
//

//-----------------------------------------------------------------

//======swap.c======

//-----------------------------------------------------------------

//Prototype:
//static void swap(t_dnode **head)  
//Input:
//Stack head.  
//Output:
//None.  
//Purpose:
//Swaps first two nodes in a stack.  
//Note:
//

//-----------------------------------------------------------------

//Prototype:
//static void swap_print(t_stacks *stacks, char *op)  
//Input:
//Stacks, operation name (`"sa"`, `"sb"`, `"ss"`).  
//Output:
//None. 
//Purpose:
//Executes swaps but does not record operations (breaks optimization).  
//Note:
//

//-----------------------------------------------------------------

//Prototype:
void	sa(t_stacks *stacks);
//Input:
//Stacks.  
//Output:
//None.  
//Purpose:
//Swaps top two elements of stack A.  
//Note:
//

//-----------------------------------------------------------------

//Prototype:
void	sb(t_stacks *stacks);
//Input:
//Stacks.  
//Output:
//None.  
//Purpose:
//Swaps top two elements of stack B.  
//Note:
//

//-----------------------------------------------------------------

//Prototype:
void	ss(t_stacks *stacks);
//Input:
//Stacks.  
//Output:
//None.  
//Purpose:
//Swaps top two elements of both stacks.  
//Note:
//

//-----------------------------------------------------------------

//======sort.c======

//-----------------------------------------------------------------

void	sort_three(t_stacks *stack, t_dnode **operations_list);
//Input:
//Stacks, list to track operations.
//Output:
//None. 
//Purpose:
//Sorts 3-element stack with minimal swaps/rotations.
//Note:
//

//-----------------------------------------------------------------

void	sort_turk(t_stacks *stacks, t_dnode **operations_list, int total);
//Input:
//Stacks, operations list, total elements.
//Output:
//None. 
//Purpose:
//Sorts medium/large stacks by pushing to B and reinserting optimally.
//Note:
//`find_max_index` may not work for final rotation.

//-----------------------------------------------------------------

//Prototype:
void	sort_five(t_stacks *stacks, t_dnode **operations_list);
//Input:
//Stacks, operations list, total elements.
//Output:
//None. 
//Purpose:
//Sorts 5-element stack by pushing 2 to B, sorting 3, then reinserting.
//Note:

//-----------------------------------------------------------------

//Prototype:
void	sort_any(t_stacks *stacks, int total);
//Input:
//Stacks, total elements.
//Output:
//None.
//Purpose:
//Dispatches sorting based on stack size (3/5/other).
//Note:
//

//-----------------------------------------------------------------

//Prototype:
void	sort(int nbr_elements, t_stacks *stacks);
//Input:
//Element count, stacks.
//Output:
//None.
//Purpose:
//Handles 2-element case, delegates others to `sort_any`.
//Note:
//

//-----------------------------------------------------------------

//  ======sort_utils.c======

//-----------------------------------------------------------------

//Prototype:
int		is_sorted(t_dnode *stack);
//Input:
//A doubly linked list (stack).
//Output:
//1 if sorted in ascending order, 0 otherwise.
//Purpose:
//Checks whether the stack is sorted in ascending order.
//Note:
//Assumes that the stack contains integers.

//-----------------------------------------------------------------

//Prototype:
int		find_max_index(t_dnode *head);
//Input:
//Head of a doubly linked list (stack).
//Output:
//Index of the maximum value or -1 if the stack is empty.
//Purpose:
//Finds the index of the largest value in the stack.
//Note:
//

//-----------------------------------------------------------------

//  ======target_calculations.c======

//-----------------------------------------------------------------

//Prototype:
int		determin_closest_data(int target, t_dnode *current);
//Input:
//Target value and a doubly linked list (current stack).
//Output:
//Index of the closest data or -1 if no valid data is found.
//Purpose:
//Determines the index of the closest value to the target.
//Note:
//

//-----------------------------------------------------------------

//Prototype:
int		get_closest_index(t_dnode *first, t_dnode *second);
//Input:
//Two doubly linked lists (first and second stacks).
//Output:
//Closest index or 0 if no valid index is found.
//Purpose:
//Finds the closest index in the first stack relative 
//to the second stack's top value.
//Note:
//

//-----------------------------------------------------------------

//Prototype:
int		find_target_and_max_positions(t_dnode *current, int *target_pos,
			int *max_pos, int node_data);
//Input:
//Current stack, pointers to store target and max positions
//and a reference node data value.
//Output:
//The target value or `INT_MIN` if no valid target is found.
//Purpose:
//Finds both the target position and the maximum position in the stack.
//Note:
//

//-----------------------------------------------------------------

//Prototype:
int		find_target_position(t_dnode *node, t_dnode *target_head);
//Input:
//A node and the head of a target stack.
//Output:
//Target position or maximum position if no valid target is found.
//Purpose:
//Determines the optimal position for a node in the target stack.
//Note:
//

//-----------------------------------------------------------------

//Prototype:
int		lowest_cost_index(t_dnode *head, t_dnode *target_stack, int total);
//Input:
//Head of a source stack, head of a target stack
//and the total number of elements.
//Output:
//Index of the element with the lowest cost to move.
//Purpose:
//Calculates the index of the element in the source stack,
//which can be moved to the target stack with the lowest cost.
//Note:
//

//-----------------------------------------------------------------

//======optimize.c======

//-----------------------------------------------------------------

//Prototype:
void	delete_node(t_dnode **head, t_dnode *node_to_delete);
//Input:
//`head` (list head), `node_to_delete` (node to remove).  
//Output:
//None.
//Purpose:
//Removes a node from a doubly linked list and adjusts pointers.  
//Note:
//

//-----------------------------------------------------------------

//Prototype:
void	update_node_content(t_dnode *node,
			const char *new_name, int new_rotation_count);
//Input:
//Node to update, new operation name/rotation count.
//Output:
//None. 
//Purpose:
//Modifies an operation node’s command name and rotation count.
//Note:
//

//-----------------------------------------------------------------

//Prototype:
int		check_operation_pair(const char *op1, const char *op2,
			const char *val1, const char *val2);
//Input:
//Two operation names, and a pair to compare (e.g., `"sa"`, `"sb"`).
//Output:
//`1` (pair matches) or `0`.
//Purpose:
//Checks if two operations form a specific pair (e.g., `sa` + `sb` → `ss`).
//Note:
//

//-----------------------------------------------------------------

//Prototype:
//int optimize_swaps(t_dnode **head, t_dnode *current)
//Input:
//List head, current node to check.
//Output:
//`1` (changes made) or `0`.
//Purpose:
//Merges redundant swaps (e.g., `sa` + `sb` → `ss`) or cancels duplicates.
//Note:
//

//-----------------------------------------------------------------

void	optimize_operations(t_dnode **head);
//Input:
//List head, total elements (for rotation cost).  
//Output:
//None.  
//Purpose:
//Iteratively optimizes operations until no further changes.  
//Note:
//

//-----------------------------------------------------------------

#endif
