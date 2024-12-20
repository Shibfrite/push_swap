#include <stdio.h>

void	ft_dlst_print(t_dnode	*head)
{
	t_dnode	*current;

	if (!head)
	{
		printf("List is empty\n");
		return ;
	}
	current = head;
	while (current)
	{
		printf("%p ", current->data);
		current = current->next;
		if (current == head)
			break ;
	}
	printf("\n");
}

static t_dnode	*create_node(int value)
{
	int		*num;
	t_dnode	new_node;

	num = malloc(sizeof(int));
	if (!num)
		return (NULL);
	*num = value;
	new_node = ft_dlstnew(num);
	if (!new_node)
	{
		free(num);
		return (NULL);
	}
	return (new_node);
}

static t_dnode	*create_list(int start, int end)
{
	t_dnode	*head;
	t_dnode	*new_node;
	int		i;

	head = NULL;
	i = start;
	while (i <= end)
	{
		new_node = create_node(i++);
		if (!new_node)
			return (NULL);
		ft_dlstadd_back(&head, new_node);
	}
	return (head);
}

static void	print_list(t_dnode	*head)
{
	t_dnode	*current;

	current = head;
	printf("List contents: ");
	while (current)
	{
		printf("%d ", *(int *)current->data);
		current = current->next;
	}
	printf("\n");
}

// New helper functions
static t_dnode	*remove_last_node(t_dnode	**head)
{
	t_dnode	*last;

	last = ft_dlstlast(*head);
	if (!last)
		return (NULL);
	if (last->prev)
		last->prev->next = NULL;
	else
		*head = NULL;
	last->prev = NULL;
	last->next = NULL;
	return (last);
}

static void	swap_last_nodes(t_dnode	*head)
{
	t_dnode	*last;
	t_dnode	*before_last;

	if (!head || !head->next || !head->next->next)
		return ;
	last = ft_dlstlast(head);
	before_last = last->prev;
	before_last->prev->next = last;
	last->prev = before_last->prev;
	last->next = before_last;
	before_last->prev = last;
	before_last->next = NULL;
}

static void	push_on_other(t_dnode **first, t_dnode **second)
{
	t_dnode	*last;

	if (!first || !*first || !second)
		return ;
	last = remove_last_node(first);
	if (last)
		ft_dlstadd_back(second, last);
}

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
