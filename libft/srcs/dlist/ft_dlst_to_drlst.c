/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_dlst_to_drlst.c                                  :+:    :+:           */
/*                                                      +:+                   */
/*   By: makurek <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/31 14:43:21 by makurek        #+#    #+#                */
/*   Updated: 2025/03/31 14:43:22 by makurek        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

int	ft_dlst_to_drlst(t_dnode **head)
{
	int		size;
	t_dnode	*current;

	size = 0;
	if (!head || !*head)
		return (0);
	current = *head;
	while (current)
	{
		size++;
		if (!current->next)
		{
			current->next = *head;
			(*head)->prev = current;
			break ;
		}
		current = current->next;
	}
	return (size);
}
