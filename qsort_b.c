
#include "push_swap.h"

static int ft_check_median_b(t_swap *a, int med)
{
    while (a)
    {
        if (a->num >= med)
            return (1);
        a = a->next;
    }
    return (0);
}

void ft_sort3_b(t_var_s *var)
{
    int ib;
    int grp;

    if (var->b)
    {
        grp = var->b->grp;
        while (var->b && var->b->grp == grp)
        {
            ib = ft_check_swap_b(var->b);
            var->i = ft_check_swap(var->a);
            if (var->i == 1)
            {
                ft_swap_sa(&(var->a));
                write(var->fd, "sa\n", 3);
            }
            else if (ib == 1)
            {
                ft_swap_sa(&(var->b));
                write(var->fd, "sb\n", 3);
            }
            else
            {
                ft_swap_pa(&(var->a), &(var->b));
                write(var->fd, "pa\n", 3);
            }
        }
    }
}

void ft_qsort_b(t_var_s *var)
{
    var->grp = 0;
    var->count_ra = 0;
    if (ft_count_elem_grup(var->b) > 3)
    {
        var->grp++;
        var->med_b = ft_median(var->b);
        while (ft_check_median_b(var->b, var->med_b))
        {
            if (var->b->num >= var->med_b)
            {
                var->b->grp += var->grp;
                ft_swap_pa(&(var->a), &(var->b));
                write(var->fd, "pa\n", 3);
            }
            else
            {
                ft_swap_ra(&(var->b));
                write(var->fd, "rb\n", 3);
                var->count_ra++;
            }
//            var->i = ft_check_swap(var->a);
//            if (var->i == 1 && ft_count_elem_grup(var->a) < 4)
//            {
//                ft_swap_sa(&(var->a));
//                write(var->fd, "sa\n", 3);
//            }
        }
        while (ft_count_grup(var->b) && var->count_ra--)
        {
            ft_swap_rra(&(var->b));
            write(var->fd, "rrb\n", 4);
        }
    }
    else
        ft_sort3_b(var);
}