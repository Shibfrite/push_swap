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

//#################################################Need to check if the hash is proprely freed
// hash table uses printf

typedef struct s_stacks {
    t_dnode *a;
    t_dnode *b;
} t_stacks;

typedef struct s_operation {
        char *name;
        int rotation_count;
} t_operation;

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

//	======main.c======

//GLOBAL: leak checks missing

//Prototype:	int	main(int argc, char *argv[])
//Input:		argc, argv (arguments), stacks (A/B).
//Output:		0 (success) or ERROR.
//Purpose:		Entry point: Validates input, initializes stacks A/B, sorts, frees memory.

//-----------------------------------------------------------------------------------------------------------------------------------

//	======support_sort.c======

int     is_sorted(t_dnode *stack);
//Input:		Stack to check.
//Output:		`1` (sorted) or `0` (unsorted).
//Purpose:		Verifies if stack is in ascending order.
//#####
//Note:			No known issues.

//-----------------------------------------------------------------------------------------------------------------------------------

int     get_closest_index(t_dnode *first, t_dnode *second);
//Input:		`first` (stack A), `second` (node from B).  
//Output:		Index of closest smaller/larger value in A.  
//Purpose:		Finds optimal insertion position for B node in A.  
//#####  
//Note:			Complex logic – verify edge cases (e.g., all elements > target).  

//-----------------------------------------------------------------------------------------------------------------------------------

int		find_target_position(t_dnode *node, t_dnode *target_head);
//Input:		`node` (to insert), `target_head` (stack A).
//Output:		Position index in A for `node`.
//Purpose:		Determines where to place `node` in A for minimal rotations.
//#####
//Note:		Check logic if all elements in A are larger than `node`.

//-----------------------------------------------------------------------------------------------------------------------------------

int		lowest_cost_index(t_dnode *head, t_dnode *target_stack, int total);
//Input:		`head` (stack B), `target_stack` (A), `total` (elements).
//Output:		Index of B node with lowest rotation cost.
//Purpose:		Selects optimal B node to move to A first.
//#####
//Note:		Verify loop bounds (`i <= total - 1`).

//-----------------------------------------------------------------------------------------------------------------------------------

int     find_max_index(t_dnode *head);
//Input:		Stack to search.
//Output:		Index of maximum value.
//Purpose:		Finds position of largest element (for small-stack sorting).
//#####
//Note:		Returns `-1` if stack is empty (ensure handled).

//-----------------------------------------------------------------------------------------------------------------------------------

//	======optimize.c======

void	delete_node(t_dnode **head, t_dnode *node_to_delete);
//Input:		`head` (list head), `node_to_delete` (node to remove).  
//Output:		None. Fixes: Ensure `free_operation` properly frees `t_operation` data.  
//Purpose:		Removes a node from a doubly linked list and adjusts pointers.  
//#####  
//Note:		Check if `free_operation` handles `t_operation` fields (e.g., `name`).

//-----------------------------------------------------------------------------------------------------------------------------------

void	update_node_content(t_dnode *node, const char *new_name, int new_rotation_count);
//Input:		Node to update, new operation name/rotation count.
//Output:		None. Fixes: Check `strdup` success (NULL check).
//Purpose:		Modifies an operation node’s command name and rotation count.
//#####
//Note:		Potential crash if `strdup` fails (no NULL check).

//-----------------------------------------------------------------------------------------------------------------------------------

int		check_operation_pair(const char *op1, const char *op2, const char *val1, const char *val2);
//Input:		Two operation names, and a pair to compare (e.g., `"sa"`, `"sb"`).
//Output:		`1` (pair matches) or `0`.
//Purpose:		Checks if two operations form a specific pair (e.g., `sa` + `sb` → `ss`).
//#####
//Note:		No known issues.

//-----------------------------------------------------------------------------------------------------------------------------------

//Prototype:		int optimize_swaps(t_dnode **head, t_dnode *current)
//Input:		List head, current node to check.
//Output:		`1` (changes made) or `0`.
//Purpose:		Merges redundant swaps (e.g., `sa` + `sb` → `ss`) or cancels duplicates.
//#####
//Note:		Ensure `current` is valid after deletions (dangling pointer risk).

//-----------------------------------------------------------------------------------------------------------------------------------

void	optimize_operations(t_dnode **head, int total);
//Input:		List head, total elements (for rotation cost).  
//Output:		None.  
//Purpose:		Iteratively optimizes operations until no further changes.  
//#####  
//Note:		Potential infinite loop if `changes_made` is incorrectly tracked.  

//-----------------------------------------------------------------------------------------------------------------------------------

//	======operation.c=====

//Prototype:		void execute_single_operation(t_stacks *stacks, const char *op_name, int rotation_count)  
//Input:		Stacks, operation name, rotation count.  
//Output:		None.  
//Purpose:		Maps command names to stack operations (e.g., "sa" → `sa()`).  
//#####  
//Note:		Redundant for rotation commands (e.g., `ra` called `rotation_count` times instead of merging).  

//-----------------------------------------------------------------------------------------------------------------------------------

void	add_operation(t_dnode **head, t_stacks *stack, char *operation, int rotation_count);
//Input:		Operation list head, stacks, command name, rotation count.
//Output:		None. Fixes:		Memory leak if `ft_dlstnew` fails after `execute_single_operation`.
//Purpose:		Adds command to list and executes it immediately.
//#####
//Note:		Executes command **before** ensuring node creation success (risk of inconsistency).

//-----------------------------------------------------------------------------------------------------------------------------------

void	execute_operations(t_dnode *head);
//Input:		List of operations.
//Output:		Prints commands to stdout.
//Purpose:		Outputs optimized command sequence (with rotation counts).
//#####
//Note:		Could merge consecutive same commands (e.g., `ra` ×3 → `ra 3`).

//-----------------------------------------------------------------------------------------------------------------------------------

void	free_operation(void *content);
//Input:		Operation data (to free).
//Output:		None.
//Purpose:		Frees `t_operation` (name + struct).
//#####
//Note:		Correctly handles cleanup.

//-----------------------------------------------------------------------------------------------------------------------------------

//	======parse.c======

int     check_input(int argc, char *argv[], t_stacks *stacks);
//Prototype:	int check_input(int argc, char *argv[], t_stacks *stacks)
//Input:		argc, argv (arguments), stacks (to populate A).
//Output:		Number of elements or `ERROR`.
//Purpose:		Validates input, parses numbers, checks duplicates via hash table.
//#####
//Note:			Hash table (`ht`) not freed on early exit (leak). Error messages use `printf` (consider `stderr`). Maybe change file?

//-----------------------------------------------------------------------------------------------------------------------------------

//Prototype:	static int handle_sign(const char **str)  
//Input:		String pointer (modified in-place).  
//Output:		Sign (+1/-1).  
//Purpose:		Extracts sign from number string.  
//#####  
//Note:		Redundant `sign = 1` for '+' (already default).

//-----------------------------------------------------------------------------------------------------------------------------------

//Prototype:	static int parse_number(const char **str, int *num)  
//Input:		String pointer (modified in-place), output number.  
//Output:		SUCCESS/ERROR.  
//Purpose:		Converts string to integer, checks overflow.  
//#####  
//Note:		Allows invalid trailing characters (e.g., "123abc" → parsed as 123).

//-----------------------------------------------------------------------------------------------------------------------------------

//Prototype:	static int add_to_list(t_dnode **dlist, int num)  
//Input:		List head, number to add.  
//Output:		SUCCESS/ERROR.  
//Purpose:		Appends number to stack A.  
//#####  
//Note:		No known issues.

//-----------------------------------------------------------------------------------------------------------------------------------

int		parse_string(const char *str, t_dnode **dlist, hash_table *ht);
//Input:		Input string, stack A list, hash table for duplicates.  
//Output:		Element count or ERROR. Fixes:		Hash table key storage (use values, not addresses).  
//Purpose:		Parses numbers from string, adds to list, checks duplicates.  
//#####  
//Note:		Invalid inputs (e.g., "123-456") parsed as multiple numbers. Hash table key bug (stores &num → same address).  

//-----------------------------------------------------------------------------------------------------------------------------------

//	======push.c======

//Prototype:	static void push(t_dnode **first_stack, t_dnode **second_stack)  
//Input:		Source stack, destination stack.  
//Output:		None.  
//Purpose:		Moves first node from `first_stack` to `second_stack`.  
//#####  
//Note:		Missing `add_operation` call (push commands not tracked for optimization).  
//push_print

//-----------------------------------------------------------------------------------------------------------------------------------

//Prototype:	static void push_print(t_stacks *stacks, char *op)  
//Input:		Stacks, operation name (`"pa"`/`"pb"`).  
//Output:		None.  
//Purpose:		Executes and tracks push operations.  
//#####  
//Note:		Redundant `strcmp` (use direct function calls). Missing `add_operation` call.

//-----------------------------------------------------------------------------------------------------------------------------------

void	pa(t_stacks *stacks);
//Input:		Stacks.
//Output:		None.
//Purpose:		Pushes top of B to A.
//#####
//Note:		No known issues.  

//-----------------------------------------------------------------------------------------------------------------------------------

void	pb(t_stacks *stacks);
//Input:		Stacks.
//Output:		None.
//Purpose:		Pushes top of A to B.
//#####
//Note:		No known issues.

//-----------------------------------------------------------------------------------------------------------------------------------

//	======reverse_rotate.c======

//Prototype:	static void reverse_rotate_print(t_stacks *stacks, int rotation, char *op)  
//Input:		Stacks, rotation count, operation name.  
//Output:		None. Fixes:		Track operations via `add_operation`, remove rotation count (invalid per Push_swap rules).  
//Purpose:		Applies reverse rotations but does not track commands (breaks optimization).  
//#####  
//Note:		`rotation` parameter violates Push_swap rules (only single commands allowed).


//-----------------------------------------------------------------------------------------------------------------------------------

void    rra(t_stacks *stacks, int rotate);
//Input:		Stacks, rotation count.
//Output:		None.
//Purpose:		Reverse-rotates stack A.
//#####
//Note:		Invalid use of `rotate` parameter (multi-rotate not allowed). Missing `add_operation`.

//-----------------------------------------------------------------------------------------------------------------------------------

void    rrb(t_stacks *stacks, int rotate);
//Input:		Stacks, rotation count.
//Output:		None.
//Purpose:		Reverse-rotates stack B.
//#####
//Note:		Invalid use of `rotate` parameter. Missing `add_operation`.

//-----------------------------------------------------------------------------------------------------------------------------------

void    rrr(t_stacks *stacks, int rotate);
//Input:		Stacks, rotation count.
//Output:		None.
//Purpose:		Reverse-rotates both stacks.
//#####
//Note:		Invalid use of `rotate` parameter. Missing `add_operation`.

//-----------------------------------------------------------------------------------------------------------------------------------

//	======rotate.c======

//Prototype:	static void rotate_print(t_stacks *stacks, int rotation, char *op)
//Input:		Stacks, rotation count, operation name.
//Output:		None. Fixes:		Track operations via `add_operation`, remove rotation count (invalid per Push_swap rules).
//Purpose:		Applies rotations but does not track commands (breaks optimization).
//#####
//Note:		`rotation` parameter violates Push_swap rules (only single commands allowed).

//-----------------------------------------------------------------------------------------------------------------------------------

void    ra(t_stacks *stacks, int rotate);
//Input:		Stacks, rotation count.
//Output:		None.
//Purpose:		Rotates stack A.
//#####
//Note:		Invalid use of `rotate` parameter (multi-rotate not allowed). Missing `add_operation`.

//-----------------------------------------------------------------------------------------------------------------------------------

void    rb(t_stacks *stacks, int rotate);
//Input:		Stacks, rotation count.
//Output:		None.
//Purpose:		Rotates stack B.
//#####
//Note:		Invalid use of `rotate` parameter. Missing `add_operation`.

//-----------------------------------------------------------------------------------------------------------------------------------

void    rr(t_stacks *stacks, int rotate);
//File:		rotate.c
//Prototype:	void rr(t_stacks *stacks, int rotate)
//Input:		Stacks, rotation count.
//Output:		None.
//Purpose:		Rotates both stacks.
//#####
//Note:		Invalid use of `rotate` parameter. Missing `add_operation`.

//-----------------------------------------------------------------------------------------------------------------------------------

//	======rotations.c======

//handle_ra_rb
//Prototype:	static int handle_ra_rb(...)  
//Input:		Nodes/operations to merge.  
//Output:		`1` (merged) or `0`.  
//Purpose:		Merges `ra` + `rb` → `rr`.  
//#####  
//Note:		Incorrectly uses `rotation_count` (invalid per Push_swap rules).

//-----------------------------------------------------------------------------------------------------------------------------------

//Prototype:	static int handle_ra_rra(...)  
//Input:		Nodes/operations to cancel.  
//Output:		`1` (canceled) or `0`.  
//Purpose:		Cancels `ra` + `rra` pairs.  
//#####  
//Note:		Partially correct but relies on invalid `rotation_count`.  

//-----------------------------------------------------------------------------------------------------------------------------------

//Prototype:	static int handle_rot(...)  
//Input:		Current node/operation.  
//Output:		`1` (optimized) or `0`.  
//Purpose:		Replaces rotations with reverse if shorter (e.g., `ra` ×4 → `rra` ×1 for stack size 5).  
//#####  
//Note:		Uses `total` (stack size) incorrectly (should use current stack size dynamically).  

//-----------------------------------------------------------------------------------------------------------------------------------

//Prototype:	static int handle_rb_rrb(...)  
//Input:		Nodes/operations to cancel.  
//Output:		`1` (canceled) or `0`.  
//Purpose:		Cancels `rb` + `rrb` pairs.  
//#####  
//Note:		Same `rotation_count` issue as `handle_ra_rra`.  

//-----------------------------------------------------------------------------------------------------------------------------------

//Prototype:	static int handle_rr_rrr(...)  
//Input:		Nodes/operations to cancel.  
//Output:		`1` (canceled) or `0`.  
//Purpose:		Cancels `rr` + `rrr` pairs.  
//#####  
//Note:		Same `rotation_count` issue as other handlers.  

//-----------------------------------------------------------------------------------------------------------------------------------

int		optimize_rotations(t_dnode **head, t_dnode *current, int total);
//Input:		List head, current node, total elements.
//Output:		`1` (changes made) or `0`.
//Purpose:		Merges/cancels rotation commands (e.g., `ra` + `rb` → `rr`).
//#####
//Note:		Overly complex logic. `rotation_count` violates Push_swap rules (only single commands allowed).

//-----------------------------------------------------------------------------------------------------------------------------------

//	======sort.c======

void    sort_three(t_stacks *stack, t_dnode **operations_list);
//Input:		Stacks, list to track operations.
//Output:		None. Fixes: Remove `rotation_count` (invalid per Push_swap rules).
//Purpose:		Sorts 3-element stack with minimal swaps/rotations.
//#####
//Note:		Uses invalid `rotation_count=1` (should output individual commands).

//-----------------------------------------------------------------------------------------------------------------------------------

void    sort_turk(t_stacks *stacks, t_dnode **operations_list, int total);
//Input:		Stacks, operations list, total elements.
//Output:		None. Fixes: Replace rotation counts with individual commands.
//Purpose:		Sorts medium/large stacks by pushing to B and reinserting optimally.
//#####
//Note:		`rb`/`ra` with counts violates rules. `find_max_index` may not work for final rotation.

//-----------------------------------------------------------------------------------------------------------------------------------

void    sort_five(t_stacks *stacks, t_dnode **operations_list, int total);
//Input:		Stacks, operations list, total elements.
//Output:		None. Fixes: Uninitialized `closest` variable, remove rotation counts.
//Purpose:		Sorts 5-element stack by pushing 2 to B, sorting 3, then reinserting.
//#####
//Note:		Uses invalid `rotation_count`. `closest` used uninitialized (critical bug).

//-----------------------------------------------------------------------------------------------------------------------------------

void    sort_any(t_stacks *stacks, int total);
//Input:		Stacks, total elements.
//Output:		None.
//Purpose:		Dispatches sorting based on stack size (3/5/other).
//#####
//Note:		Relies on invalid rotation counts. `optimize_operations` may not fully simplify.

//-----------------------------------------------------------------------------------------------------------------------------------

void    sort(int nbr_elements, t_stacks *stacks);
//Input:		Element count, stacks.
//Output:		None.
//Purpose:		Handles 2-element case, delegates others to `sort_any`.
//#####
//Note:		Directly prints `sa` (bypasses `add_operation`, breaks optimization).

//-----------------------------------------------------------------------------------------------------------------------------------

//	======swap.c======

//Prototype:	static void swap(t_dnode **head)  
//Input:		Stack head.  
//Output:		None.  
//Purpose:		Swaps first two nodes in a stack.  
//#####  
//Note:		Correct implementation.  

//-----------------------------------------------------------------------------------------------------------------------------------

//Prototype:	static void swap_print(t_stacks *stacks, char *op)  
//Input:		Stacks, operation name (`"sa"`, `"sb"`, `"ss"`).  
//Output:		None. Fixes: Add `add_operation` call to track commands.  
//Purpose:		Executes swaps but does not record operations (breaks optimization).  
//#####  
//Note:		Missing `add_operation` → swaps not optimized (e.g., `sa` + `sb` → `ss`).  

//-----------------------------------------------------------------------------------------------------------------------------------

void	sa(t_stacks *stacks);
//Input:		Stacks.  
//Output:		None.  
//Purpose:		Swaps top two elements of stack A.  
//#####  
//Note:		No known issues.  

//-----------------------------------------------------------------------------------------------------------------------------------

void	sb(t_stacks *stacks);
//Input:		Stacks.  
//Output:		None.  
//Purpose:		Swaps top two elements of stack B.  
//#####  
//Note:		No known issues.  

//-----------------------------------------------------------------------------------------------------------------------------------

void	ss(t_stacks *stacks);
//Input:		Stacks.  
//Output:		None.  
//Purpose:		Swaps top two elements of both stacks.  
//#####  
//Note:		No known issues.  

//-----------------------------------------------------------------------------------------------------------------------------------

#endif
