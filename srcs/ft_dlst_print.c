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
