#include "libft_list.h"

static void make_circular(t_dnode *head)
{
    if (!head)
        return;
    t_dnode *last = ft_dlstlast(head);
    last->next = head;
    head->prev = last;
}

static void break_circular(t_dnode *head)
{
    if (!head)
        return;
    t_dnode *last = head->prev;
    last->next = NULL;
    head->prev = NULL;
}

t_dnode *ft_dlst_rotate(t_dnode **head, int k)
{
    int size;
    t_dnode *new_head;

    if (!head || !*head || !(*head)->next || !k)
        return (*head);

    size = ft_dlstsize(*head);
    k %= size;
    if (!k)
        return (*head);

    make_circular(*head);

    new_head = *head;
    for (int i = 0; i < k; i++)
        new_head = new_head->next;

    break_circular(new_head);
    *head = new_head;

    return (*head);
}
