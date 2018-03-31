
#include "push_swap.h"

int		ft_atoi_swap(const char *str)
{
    int		i;
    long	re;
    int		n;

    re = 0;
    n = 1;
    i = 0;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
           str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
        i++;
    if (str[i] == '-')
        n = -1;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        re *= 10;
        re += ((str[i] - 48) * n);
        i++;
    }
    return ((int)(re));
}

int ft_newlist(t_list_swap **a, int num)
{
    t_list_swap	*new;
    t_list_swap *temp;

    if (!(new = (t_list_swap*)malloc(sizeof(t_list_swap))))
        return (0);

    temp = *a;
    new->next = NULL;
    new->num = num;
    if (*a)
    {
        while (temp->next)
            temp = temp->next;
        temp->next = new;
    }
    else
        *a = new;
    return (1);
}