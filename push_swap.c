
#include "push_swap.h"

static int ft_find_op(t_list_swap *a)
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

static int ft_check_qsort(t_list_swap *a)
{
    t_list_swap *temp;

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

static int ft_count(t_list_swap *a)
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

static int ft_opcount(t_list_swap *a, int op)
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

void ft_qsort(t_list_swap *a, t_list_swap *b)
{
    int op;

    int i;

    i = 1;
    op = ft_find_op(a);
    while (ft_check_qsort(a) != 0)
    {
        if (op == a->num)
        {
            ft_pa(&b, &a);
            op = ft_find_op(a);
            ft_printf("pb\n");
            i++;
        }
        else if ((ft_opcount(a, op)* 2) > ft_count(a))
        {
            ft_rra(&a);
            ft_printf("rra\n");
            i++;
        }
        else
        {
            ft_ra(&a);
            ft_printf("ra\n");
            i++;
        }
    }
    while (b)
    {
        ft_pa(&a, &b);
        ft_printf("pa\n");
        i++;
    }
    //ft_comands_test(a, b);
}

int main(int argc, char **argv)
{
    t_list_swap *stack_a;
    t_list_swap *stack_b;
    int         i;

    stack_a = NULL;
    stack_b = NULL;
    i = 1;
    if (argc < 2)
        exit (0);
    while (argc > i)
    {
        if (ft_check_error(argv[i], &stack_a, 0) == -1)
        {
            write(1, "Error\n", 6);
            return (-1);
        }
        i++;
    }
    ft_check_dubl(stack_a);
    ft_qsort(stack_a, stack_b);
    ft_comands_test(stack_a, stack_b);
}