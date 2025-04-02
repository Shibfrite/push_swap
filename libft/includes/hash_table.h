/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   hash_table.h                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: makurek <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/31 14:16:14 by makurek        #+#    #+#                */
/*   Updated: 2025/03/31 14:16:16 by makurek        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_TABLE_H
# define HASH_TABLE_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdint.h>
# include "libft.h" 

# define MAX_NAME 256
# define TABLE_SIZE 10
# define SUCCESS 0
# define ERROR -1

// Forward declaration of t_hash_table
struct			s_hash_table;

// the modular functions used to change the algorithme without altering output
typedef size_t	(*t_hash_function)(const void *key);
typedef int		(*t_compare_function)(const void *a, const void *b);
typedef int		(*t_collision_resolution_function)(struct s_hash_table *ht,
				size_t index, void *data);
typedef void	*(*t_lookup_method_function)(struct s_hash_table *ht,
				size_t index, const void *key);

typedef struct s_hash_table
{
	t_collision_resolution_function	resolve_collision;
	t_lookup_method_function		lookup_method;
	t_compare_function				compare;
	t_hash_function					hash;
	size_t							size;
	void							**table;
}	t_hash_table;

// node used if collision_resolution needs linked list.
typedef struct node
{
	struct node	*next;
	void		*data;
}	t_node;

// Function prototypes
int		hash_table_init(t_hash_table *ht);
void	hash_table_print(t_hash_table *ht);
int		hash_table_insert(t_hash_table *ht, void *data, size_t data_size);
void	*hash_table_lookup(t_hash_table *ht, const void *key);
void	*hash_table_delete(t_hash_table *ht, const void *key);
void	hash_table_destroy(t_hash_table *ht);

// Utility functions
size_t	hash_multiplication(const void *key);
int		compare_strings(const void *a, const void *b);

// Collision resolution methods with lookup method 
int		chaining_resolution(t_hash_table *ht, size_t index, void *data);
void	*chaining_lookup(t_hash_table *ht, size_t index, const void *key);

#endif
