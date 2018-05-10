
#include "push_swap.h"

static int ft_check_med(t_swap *a, int med)
{
    int grp;

    grp = a->grp;
    while (a && a->grp == grp)
    {
        if (a->num > med)
            return (1);
        a = a->next;
    }
    return (0);
}

int ft_check_qsortb(t_swap *b)
{
    t_swap *temp;
    int i;

    i = 1;
    if (b)
    {
        temp = b->next;
        while (temp && temp->grp == b->grp)
        {
            if (temp->num > b->num)
                return (i);
            temp = temp->next;
            b = b->next;
            i++;
        }
    }
    return (0);
}

static void ft_grp_elem_swap(t_swap **a, t_swap **b, int fd)
{
    t_swap *temp;
    int grp;

    temp = *b;
    grp = temp->grp;
    while (temp && temp->grp == grp)
    {
        temp->grp = 0;
        temp = temp->next;
        ft_swap_pa(a, b);
        write(fd, "pa\n", 3);
    }
}

static int ft_sort3b(t_swap **a, t_swap **b, int fd)
{
    int i;

    while ((i = ft_check_qsortb(*b)))
    {
        if (i == 1)
        {
            ft_swap_sa(b);
            write(fd, "sb\n", 3);
        }
        else if (ft_count_elem(*b) && i > 1)
        {
            ft_swap_rra(b);
            write(fd, "rrb\n", 4);
        }
        else if (i > 1)
        {
            ft_swap_ra(b);
            ft_swap_sa(b);
            ft_swap_rra(b);
            write(fd, "rb\nsb\nrrb\n", 10);
        }
    }
    ft_grp_elem_swap(a, b, fd);
    return (0);
}

void ft_qsort_comb(t_swap **a, t_swap **b, int fd)
{
    int med;
    int grp;
    int count_ra;
    grp = 0;//(*b)->grp;

    count_ra = 0;
    if (ft_check_grp(*b))
    {
        grp++;
        med = ft_median(*b);
        while (ft_check_med(*b, med))
        {
            if ((*b)->num >= med)
            {
                (*b)->grp += grp;
                ft_swap_pa(a, b);
                write(fd, "pa\n", 3);
            }
            else
            {
                ft_swap_ra(b);
                write(fd, "rb\n", 3);
                count_ra++;
            }
        }
        while (ft_count_grup(*b) &&count_ra--)
        {
            ft_swap_rra(b);
            write(fd, "rrb\n", 4);
        }
    }
    else
    {
        ft_sort3b(a, b, fd);
    }
}