
#include "push_swap.h"

void ft_stack_print_test(t_swap *a, t_swap *b)
{
        ft_printf("stack_a      stack_b\n");
    while (a || b)
    {
        if (a && b)
        {
            ft_printf("%d %-12d %d % d", a->grp, a->num,b->grp, b->num);
            a = a->next;
            b = b->next;
        }
        else if (a)
        {
            ft_printf("%d %d",a->grp , a->num);
            a = a->next;
        }
        else if (b)
        {
            ft_printf("%16d  %d", b->grp, b->num);
            b = b->next;
        }
        ft_printf("\n");
    }
    ft_printf("\n");
}

int main(int argc, char **argv)
{
    t_swap *stack_a;
    t_swap *stack_b;
    int         i;
    int         fd;

    if (argc < 2)
        exit (0);
    stack_a = NULL;
    stack_b = NULL;
    i = 1;
    fd = 1;
    if (argc > i + 2 && (fd = ft_flag_fd_swap(argv, i)))
        i += 2;
    if (fd < 1)
        fd = 1;
    while (argc > i)
    {
        if (ft_swap_error(argv[i], &stack_a, 0) == -1)
        {
            write(1, "Error\n", 6);
            return (-1);
        }
        i++;
    }
    ft_swap_dubl(stack_a);
    ft_qsort_com(&stack_a, &stack_b, fd);
    //ft_stack_print_test(stack_a, stack_b);
}

int main(int argc, char **argv)
{
    t_swap *stack_a;
    t_swap *stack_b;
    t_variables     a;

    if (argc < 2)
        exit (0);
    stack_a = NULL;
    stack_b = NULL;
    i = 1;
    fd = 1;
    if (argc > i + 2 && (fd = ft_flag_fd_swap(argv, i)))
        i += 2;
    if (fd < 1)
        fd = 1;
    while (argc > i)
    {
        if (ft_swap_error(argv[i], &stack_a, 0) == -1)
        {
            write(1, "Error\n", 6);
            return (-1);
        }
        i++;
    }
    ft_swap_dubl(stack_a);
    ft_qsort_com(&stack_a, &stack_b, fd);
}