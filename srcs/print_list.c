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
