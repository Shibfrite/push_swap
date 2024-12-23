#include "push_swap.h"
#include <limits.h>

#define SUCCESS 0
#define ERROR -1

int handle_sign(const char **str)
{
    int sign = 1;
    if (is_sign(**str))
    {
        sign = (**str == '-') ? -1 : 1;
        (*str)++;
    }
    return sign;
}

int parse_number(const char **str, int *num)
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

int add_to_list(t_dnode **dlist, int num)
{
    t_dnode *new_node = create_node(num);
    if (!new_node)
        return (ERROR); // Memory allocation failure

    ft_dlstadd_back(dlist, new_node);
    return (SUCCESS);
}

int parse_and_add(const char *str, t_dnode **dlist)
{
    int num;

    str = skip(str, is_space);
    if (parse_number(&str, &num) == ERROR)
        return (ERROR);
    str = skip(str, is_space);
    if (*str != '\0')
        return (ERROR);
    return add_to_list(dlist, num);
}

int parse_string(const char *str, t_dnode **dlist)
{
    int num;

    while (*str)
    {
    	str = skip(str, is_space);
        if (*str == '\0')
            break;

        if (parse_number(&str, &num) == ERROR)
            return (ERROR);

        if (add_to_list(dlist, num) == ERROR)
            return (ERROR);
    }

    return (SUCCESS);
}

int main(int argc, char *argv[])
{
    t_dnode *dlist = NULL;
    int i, result;

    if (argc < 2)
    {
        printf("Error: Not enough arguments provided.\n");
        return (ERROR);
    }

    for (i = 1; i < argc; i++)
    {
        result = parse_string(argv[i], &dlist);

        if (result == ERROR)
        {
            printf("Error: Invalid input in argument %d.\n", i);
            ft_dlstclear(&dlist, NULL);
            return (ERROR);
        }
    }

	print_list(dlist);

    ft_dlstclear(&dlist, NULL);
    return (SUCCESS);
}
