
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
