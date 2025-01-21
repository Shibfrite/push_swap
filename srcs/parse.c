#include "push_swap.h"

static int handle_sign(const char **str)
{
	int sign = 1;
	if (is_sign(**str))
	{
		sign = (**str == '-') ? -1 : 1;
		(*str)++;
	}
	return sign;
}

static int parse_number(const char **str, int *num)
{
	long long temp = 0;
	int sign = handle_sign(str);

	if (!ft_isdigit(**str))
		return (ERROR);

	while (ft_isdigit(**str))
	{
		temp = temp * 10 + (**str - '0');
		if (temp * sign > INT_MAX || temp * sign < INT_MIN)
			return (ERROR); // Integer overflow
		(*str)++;
	}

	*num = (int)(temp * sign);
	return (SUCCESS);
}

static int add_to_list(t_dnode **dlist, int num)
{
	t_dnode *new_node = create_node(num);
	if (!new_node)
		return (ERROR); // Memory allocation failure

	ft_dlstadd_back(dlist, new_node);
	return (SUCCESS);
}

int parse_string(const char *str, t_dnode **dlist, hash_table *ht)
{
	int num;
	int count;

		count = 0;
	while (*str)
	{
		str = skip(str, is_space);
		if (*str == '\0')
			break;
		if (parse_number(&str, &num) == ERROR)
			return (ERROR);
		if (add_to_list(dlist, num) == ERROR)
			return (ERROR);
		if (hash_table_insert(ht, &num, sizeof(num)) == ERROR)
			return (ERROR);
		count++;
	}
	return (count);
}
