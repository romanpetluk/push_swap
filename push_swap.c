
#include "push_swap.h"

t_list_swap *ft_sa(t_list_swap *a)
{
    t_list_swap *temp;

    temp = a;
    a = a->next;
    temp->next = a->next;
    a->next = temp;
    return (a);
}

void ft_pa(t_list_swap **a, t_list_swap **b)
{
    t_list_swap *temp;

    temp = *b;
    *b = (*b)->next;
    if (*a)
    {
        write(1, "123\n", 4);
        temp->next = *a;
    }
    else
    {
        temp->next = NULL;

//        write(1, "123\n", 4);
    }
    *a = temp;
}