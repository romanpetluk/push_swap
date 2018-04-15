
#include "push_swap.h"

int ft_flag(char *s)
{
    if (ft_strcmp(s, "-v") == 0)
    {
        return (1);
    }
    if (ft_strcmp(s, "-c") == 0)
    {
        return (1);
    }
    return (0);
}

int ft_check_sort(t_list_swap *a, t_list_swap *b)
{
    t_list_swap *temp;

    if (a)
    {
        temp = a->next;
        while (temp)
        {
            if (temp->num < a->num)
            {
                write(1, "KO\n", 3);
                exit (0);
            }
            temp = temp->next;
            a = a->next;
        }
        if (b)
        {
            write(1, "KO\n", 3);
            exit (0);
        }
        write(1, "OK\n", 3);
        return (1);
    }
    return (0);
}

static void checker(t_list_swap *stack_a, t_list_swap *stack_b, int f, int fd)
{
    if (!stack_a)
        exit (0);
    ft_check_dubl(stack_a);
    char        *s;
    while (get_next_line(fd, &s) > 0)
    {
        ft_com_cmp(s, &stack_a, &stack_b);
        if (f == 1)
            ft_stack_print(stack_a, stack_b);
    }
    ft_check_sort(stack_a, stack_b);
}

int main(int argc, char **argv)
{
    t_list_swap *stack_a;
    t_list_swap *stack_b;
    int         i;
    int         f;
    int         fd;

    if (argc < 2)
        exit (0);
    i = 1;
    fd = 0;
    if ((f = ft_flag(argv[i])))
        i++;
    if (argc > i + 2 && (fd = ft_flag_fd(argv, i)))
        i += 2;
    if (fd < 0)
        fd = 0;
    stack_a = NULL;
    stack_b = NULL;
    while (argc > i)
        if (ft_check_error(argv[i++], &stack_a, 0) == -1)
        {
            write(1, "Error\n", 6);
            exit (0);
        }
    checker(stack_a, stack_b, f, fd);
}