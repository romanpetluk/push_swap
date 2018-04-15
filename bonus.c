
#include "push_swap.h"

int ft_flag_fd_swap(char **av, int i)
{
    int fd;

    if (ft_strcmp(av[i], "-fd") == 0)
    {

        fd = open(av[i + 1], O_CREAT|O_RDWR|O_TRUNC, S_IWRITE|S_IREAD);
        return (fd);
    }
    return (0);
}

int ft_flag_fd(char **av, int i)
{
    int fd;

    if (ft_strcmp(av[i], "-fd") == 0)
    {

        fd = open(av[i + 1], O_RDONLY);
        return (fd);
    }
    return (0);
}

void ft_stack_print(t_list_swap *a, t_list_swap *b)
{
    if (a || b)
        ft_printf("stack_a      stack_b\n");
    while (a || b)
    {
        if (a && b)
        {
            ft_printf("%-12d% d", a->num, b->num);
            a = a->next;
            b = b->next;
        }
        else if (a)
        {
            ft_printf("%d", a->num);
            a = a->next;
        }
        else if (b)
        {
            ft_printf("%13c%d", ' ', b->num);
            b = b->next;
        }
        ft_printf("\n");
    }
    ft_printf("\n");
}