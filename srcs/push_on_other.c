static void	push_on_other(t_dnode **first, t_dnode **second)
{
	t_dnode	*last;

	if (!first || !*first || !second)
		return ;
	last = remove_last_node(first);
	if (last)
		ft_dlstadd_back(second, last);
}
