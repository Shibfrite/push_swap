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
