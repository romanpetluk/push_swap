
#include "push_swap.h"

static int ft_find_op(t_swap *a)
{
    long op;

    int i;

    i = 0;
    op = a->num;
    while(a->next)
    {
        a = a->next;
        if (op > a->num)
            op = a->num;

    }
    return (op);
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

//static int ft_find_nextop(t_list_swap *a)
//{
//    int op;
//    int nop;
//    int i;
//
//
//    i = 0;
//    op = a->num;
//    while(a->next)
//    {
//        a = a->next;
//        if (op > a->num)
//        {
//            nop = op;
//            op = a->num;
//        }
//
//    }
//    return (op);
//}

static int ft_count(t_swap *a)
{
    int i;

    i = 0;
    while (a)
    {
        a = a->next;
        i++;
    }
    return (i);
}

static int ft_opcount(t_swap *a, int op)
{
    int i;

    i = 0;
    while (a && a->num != op)
    {
        a = a->next;
        i++;
    }
    return (i);
}

void ft_qsort(t_swap *a, t_swap *b, int fd)
{
    int op;
    int i;

    i = 1;
    op = ft_find_op(a);
    while (ft_check_qsort(a) != 0)
    {
        if (op == a->num)
        {
            ft_swap_pa(&b, &a);
            op = ft_find_op(a);
            write(fd, "pb\n", 3);
        }
        else if ((ft_opcount(a, op)* 2) > ft_count(a))
        {
            ft_swap_rra(&a);
            write(fd, "rra\n", 4);
        }
        else
        {
            ft_swap_ra(&a);
            write(fd, "ra\n", 3);
        }
        i++;
    }
    while (b)
    {
        ft_swap_pa(&a, &b);
        write(fd, "pa\n", 3);
        i++;
    }
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
    ft_qsort(stack_a, stack_b, fd);
}