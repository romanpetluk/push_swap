
#include "push_swap.h"

int ft_check_grp(t_swap *a)
{
    int i;
    int grp;

    grp = a->grp;
    i = 0;
    while (a && a->grp == grp)
    {
        a = a->next;
        i++;
    }
    if (i > 3)
        return (1);
    return (0);
}

int ft_check_qsort(t_swap *a)
{
    t_swap *temp;
    int i;

    i = 1;
    if (a)
    {
        temp = a->next;
        while (temp)
        {
            if (temp->num < a->num)
                return (i);
            temp = temp->next;
            a = a->next;
            i++;
        }
        a = a->next;
    }
    return (0);
}

static int ft_check_med(t_swap *a, int med)
{
    int grp;

    grp = a->grp;
    while (a && a->grp == grp)
    {
        if (a->num < med)
            return (1);
        a = a->next;
    }
    return (0);
}

static int ft_sort3(t_swap **a, int fd)
{
    int i;
    t_swap *temp;
    int grp;

    grp = (*a)->grp;
    temp = (*a);
    while (temp && temp->grp == grp)
    {
        temp->grp = 0;
        temp = temp->next;
    }
    while ((i = ft_check_qsort(*a)))
    {
        if (i == 1)
        {
            ft_swap_sa(a);
            write(fd, "sa\n", 3);
        }
        else if (ft_count_elem(*a) && i > 1)
        {
//            if (ft_count_grup(*b) && )
//            {
//                ft_swap_rra(a);
//                ft_swap_rra(b);
//                write(fd, "rrr\n", 4);
//            }
//            else
//            {
                ft_swap_rra(a);
                write(fd, "rra\n", 4);
//            }
        }
        else if (i == 2)
        {
            ft_swap_ra(a);
            ft_swap_sa(a);
            ft_swap_rra(a);
            write(fd, "ra\nsa\nrra\n", 10);
        }
    }
    return (0);
}

void ft_qsort_com(t_swap **a, t_swap **b, int fd)
{
    int med;
    int grp;
    int count_ra;

    grp = 0;
    while (ft_check_grp(*a) && ft_check_qsort(*a))
    {
        count_ra = 0;
        grp++;
        med = ft_median(*a);
        while (ft_check_med(*a, med))
        {
            if ((*a)->num < med)
            {
                (*a)->grp += grp;
                ft_swap_pa(b, a);
                write(fd, "pb\n", 3);
            }
            else
            {
                ft_swap_ra(a);
                write(fd, "ra\n", 3);
                count_ra++;
            }
        }
        while (ft_count_grup(*a) && count_ra--)
        {
            ft_swap_rra(a);
            write(fd, "rra\n", 4);
        }
    }
    ft_sort3(a, fd);

    //ft_stack_print_test(*a, *b);
    if (*b || ft_check_qsort(*a))
        ft_qsort_comb(a, b, fd);
}