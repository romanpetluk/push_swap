
#include "push_swap.h"

static void ft_div_median(t_var_s *var)
{
    while (ft_check_median(var->a, var->med_a))
    {
        if (var->a->num < var->med_a)
        {
            var->a->grp += var->grp;
            ft_swap_pa(&(var->b), &(var->a));
            write(var->fd, "pb\n", 3);
        }
        else if (var->b && var->b->num < var->med_b && ft_count_grup(var->b) == 0)
        {
            ft_swap_ra(&(var->a));
            ft_swap_ra(&(var->b));
            write(var->fd, "rr\n", 3);
            var->count_ra++;
        }
        else
        {
            ft_swap_ra(&(var->a));
            write(var->fd, "ra\n", 3);
            var->count_ra++;
        }
    }
}

//static void ft_div_median_back(t_var_s *var)
//{
//
//}

void ft_qsort(t_var_s *var)
{
    while (var->b || ft_check_sort(var->a))
    {
        var->grp = 0;
        //var->med_a = ft_median(var->a);
        while (ft_count_elem_grup(var->a) > 3 && ft_check_sort(var->a))
        {
            var->count_ra = 0;
            var->grp++;
            var->med_a = ft_median(var->a);
            if (var->b)
                var->med_b = ft_median(var->b);
            ft_div_median(var);
            //var->med_a = ft_median(var->a);
            while (ft_count_grup(var->a) && var->count_ra--)
            {
                ft_swap_rra(&(var->a));
                write(var->fd, "rra\n", 4);
                if (var->a->num < var->med_a)
                {
                    var->a->grp += (var->grp + 1);
                    ft_swap_pa(&(var->b), &(var->a));
                    write(var->fd, "pb\n", 3);
                }
            }
        }
        ft_sort3(var);
        ft_qsort_b(var);
    }
}