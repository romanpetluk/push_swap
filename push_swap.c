
#include "push_swap.h"

static void ft_stack_print_test(t_swap *a, t_swap *b)
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

static int ft_check_qsort(t_swap *a)
{
    t_swap *temp;

    if (a)
    {
        temp = a->next;
        while (temp)
        {
            if (temp->num < a->num)
                return (1);
            temp = temp->next;
            a = a->next;
        }
        a = a->next;
    }
    return (0);
}

static int ft_check_grp(t_swap *a)
{
    int i;

    i = 0;
    while (a)
    {
        a = a->next;
        i++;
    }
    if (i > 3)
        return (1);
    return (0);
}

static int ft_check_med(t_swap *a, int med)
{
    while (a)
    {
        if (a->num < med)
            return (1);
        a = a->next;
    }
    return (0);
}



static void ft_qsort_com(t_swap **a, t_swap **b, int fd)
{
    int med;
    int grb;
    int i;

    i = 0;
    grb = (*a)->grp;
    med = ft_median(*a);
    while (ft_check_med(*a, med))
    {
        if ((*a)->num < med)
        {
            (*a)->grp += i;
            ft_swap_pa(b, a);
            write(fd, "pb\n", 3);
            i++;
        }
        ft_swap_ra(a);
        write(fd, "ra\n", 3);
    }
    ft_stack_print_test(*a, *b);
//    while (*a)
//    {
//        ft_printf("%d\n", (*a)->grp);
//        *a = (*a)->next;
//    }
//    ft_printf("\n");
//    while (*b)
//    {
//        ft_printf("%d\n", (*b)->grp);
//        *b = (*b)->next;
//    }
}

void ft_qsort(t_swap *a, t_swap *b, int fd)
{
    int med;
    int i;

    i = 0;
    while (ft_check_qsort(a))//(b || ft_check_qsort(a))
    {
        med = ft_median(a);
        if (ft_check_grp(a))
            ft_qsort_com(&a, &b, fd);
    }
    ft_stack_print_test(a, b);
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
    ft_printf("%d\n", ft_median(stack_a));
    ft_swap_dubl(stack_a);
    ft_qsort(stack_a, stack_b, fd);
}