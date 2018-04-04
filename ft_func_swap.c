
#include "push_swap.h"

int ft_check_dubl(t_list_swap *a)
{
    t_list_swap *temp;

    temp = a;
    while (a)
    {
        temp = a->next;
        while (temp)
        {
            if (temp->num == a->num)
                return (-1);
            temp = temp->next;
        }
        a = a->next;
    }
    return (1);
}

int ft_check_error(char *s, t_list_swap **a, int i)
{
    long num;
    int n;

    n = 1;
    while ((s[i] >= '0' && s[i] <= '9') || s[i] == ' ' || s[i] == '-')
    {
        num = 0;
        if (s[i] == '-')
            n = -1;
        if (s[i] == '-')
            i++;
        while (s[i] >= '0' && s[i] <= '9')
        {
            num *= 10;
            num += ((s[i] - 48) * n);
            if (num > 2147483647 || num < -2147483648)
                return (-1);
            i++;
        }
        if (!(ft_newlist(a, num)))
            return (-1);
        while (s[i] == ' ')
            i++;
    }
    if (s[i] == '\0')
        return (1);
    return(-1);
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