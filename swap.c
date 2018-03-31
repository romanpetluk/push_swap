
#include "push_swap.h"

void ft_sa(t_list_swap **a)
{
    t_list_swap *temp;

    if (*a && (*a)->next)
    {
        temp = *a;
        *a = (*a)->next;
        temp->next = (*a)->next;
        (*a)->next = temp;
    }
}

void ft_pa(t_list_swap **a, t_list_swap **b)
{
    t_list_swap *temp;

    if (*b)
    {
        temp = *b;
        *b = (*b)->next;
        if (*a)
            temp->next = *a;
        else
            temp->next = NULL;
        *a = temp;
    }
}

void ft_ra(t_list_swap **a)
{
    t_list_swap *temp;

    if (*a && (*a)->next)
    {
        temp = *a;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = *a;
        temp = temp->next;
        *a = (*a)->next;
        temp->next = NULL;
    }
}
void ft_rra(t_list_swap **a)
{
    t_list_swap *temp;
    t_list_swap *temp2;

    if (*a && (*a)->next)
    {
        temp = *a;
        temp2 = *a;
        while (temp->next)
        {
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = NULL;
        temp->next = *a;
        *a = temp;
    }
}