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
