#include "push_swap.h"
#include <limits.h>

#define SUCCESS 0
#define ERROR -1

// Support functions
int is_space(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r');
}

int is_sign(char c)
{
    return (c == '-' || c == '+');
}

int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

const char *skip_spaces(const char *str)
{
    while (is_space(*str))
        str++;
    return str;
}

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

    if (!is_digit(**str))
        return (ERROR);

    while (is_digit(**str))
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
    t_dnode *new_node = ft_dlstnew(&num);
    if (!new_node)
        return (ERROR); // Memory allocation failure

    ft_dlstadd_back(dlist, new_node);
    return (SUCCESS);
}

int parse_and_add(const char *str, t_dnode **dlist)
{
    int num;

    str = skip_spaces(str);
    if (parse_number(&str, &num) == ERROR)
        return (ERROR);

    str = skip_spaces(str);
    if (*str != '\0')
        return (ERROR);

    return add_to_list(dlist, num);
}

int parse_string(const char *str, t_dnode **dlist)
{
    int num;

    while (*str)
    {
        str = skip_spaces(str);
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

    // Here you can add code to print or process the list

    ft_dlstclear(&dlist, NULL);
    return (SUCCESS);
}
