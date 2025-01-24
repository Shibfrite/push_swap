#include "push_swap.h"


void delete_node(t_dnode **head, t_dnode *node_to_delete)
{
        if (!*head || !node_to_delete)
                return;
        if (*head == node_to_delete)
                *head = node_to_delete->next;
        if (node_to_delete->next)
                node_to_delete->next->prev = node_to_delete->prev;
        if (node_to_delete->prev)
                node_to_delete->prev->next = node_to_delete->next;
        ft_dlstdelone(node_to_delete, free_operation);
}

void update_node_content(t_dnode *node, const char *new_name, int new_rotation_count)
{
        if (!node || !node->data) return;

        t_operation *op = (t_operation *)node->data;
        free(op->name);  // Free the old name
        op->name = strdup(new_name);  // Allocate and copy the new name
        op->rotation_count = new_rotation_count;
}

int check_operation_pair(const char *op1, const char *op2, const char *val1, const char *val2)
{
    return (!strcmp(op1, val1) && !strcmp(op2, val2)) ||
           (!strcmp(op1, val2) && !strcmp(op2, val1));
}

int     optimize_swaps(t_dnode **head, t_dnode *current)
{
        if (!current || !current->next)
                return (0);
        t_operation *curr_op = (t_operation *)current->data;
        t_operation *next_op = (t_operation *)current->next->data;
        if (!strcmp(curr_op->name, next_op->name))
        {
                if (!strcmp(curr_op->name, "sa") || !strcmp(curr_op->name, "sb") || !strcmp(curr_op->name, "ss"))
                {
                        delete_node(head, current->next);
                        delete_node(head, current);
                        return (1);
                }
        }
        if (check_operation_pair(curr_op->name, next_op->name, "sa", "sb"))
        {
                update_node_content(current, "ss", 1);
                delete_node(head, current->next);
                return (1);
        }
        return (0);
}

void optimize_operations(t_dnode **head, int total)
{
        int changes_made = 1;  // Start with 1 to ensure the loop runs at least once

        while (changes_made)
        {
                changes_made = 0;
                t_dnode *current = *head;

                while (current && current->next)
                {
                        if (optimize_swaps(head, current))
                        {
                                changes_made = 1;
                                current = current->next;
                                continue ;
                        }
                        if (optimize_rotations(head, current, total))
                        {
                                changes_made = 1;
                                current = current->next;
                                continue ;
                        }
                        current = current->next;
                }
        }
}
