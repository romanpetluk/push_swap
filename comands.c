
#include "push_swap.h"

void ft_comands_test(t_list_swap *a, t_list_swap *b)
{
    while (a)
    {
        ft_printf("%d\n", a->num);
        a = a->next;
    }
    ft_printf("||\n||\n");
    while (b)
    {
        ft_printf("%d\n", b->num);
        b = b->next;
    }
}

static void ft_comn_cmp(char *s, t_list_swap **a, t_list_swap **b)
{
    if (ft_strcmp(s, "rra") == 0)
        ft_rra(a);
    else if (ft_strcmp(s, "rrb") == 0)
        ft_rra(b);
    else if (ft_strcmp(s, "rrr") == 0)
    {
        ft_rra(a);
        ft_rra(b);
    }
}

void ft_com_cmp(char *s, t_list_swap **a, t_list_swap **b)
{
    if (ft_strcmp(s, "sa") == 0)
        ft_sa(a);
    else if (ft_strcmp(s, "sb") == 0)
        ft_sa(b);
    else if (ft_strcmp(s, "ss") == 0)
    {
        ft_sa(a);
        ft_sa(b);
    }
    else if (ft_strcmp(s, "pa") == 0)
        ft_pa(a, b);
    else if (ft_strcmp(s, "pb") == 0)
        ft_pa(b, a);
    else if (ft_strcmp(s, "ra") == 0)
        ft_ra(a);
    else if (ft_strcmp(s, "rb") == 0)
        ft_ra(b);
    else if (ft_strcmp(s, "rr") == 0)
    {
        ft_ra(a);
        ft_ra(b);
    }
    else
        ft_comn_cmp(s, a, b);
}


