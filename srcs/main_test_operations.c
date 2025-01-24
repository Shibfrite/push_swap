#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "push_swap.h"

typedef struct s_operation
{
	char *name;
	int	rotation_count;
} t_operation;

// Assuming you have these functions defined elsewhere
void free_operation(void *content);

// Define the linked list structure if not already defined

// Function to create a new operation
t_operation *create_operation(const char *name, int rotation_count) {
    t_operation *op = malloc(sizeof(t_operation));
    op->name = strdup(name);
    op->rotation_count = rotation_count;
    return op;
}

// Function to print the list of operations
void print_operations(t_dnode *head) {
    t_dnode *current = head;
    while (current) {
        t_operation *op = (t_operation*)current->data;
        printf("%s (%d)\n", op->name, op->rotation_count);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main() {
    t_dnode *head = NULL;

    // Create a list of operations (you can easily modify this)
    ft_dlstadd_back(&head, ft_dlstnew(create_operation("rra", 2)));
    ft_dlstadd_back(&head, ft_dlstnew(create_operation("rrb", 2)));

    printf("Original list of operations:\n");
    print_operations(head);

    // Optimize the operations
    optimize_operations(&head);

    printf("Optimized list of operations:\n");
    print_operations(head);

    // Free the memory (you should implement this function)
    // free_list(head);

    return 0;
}
