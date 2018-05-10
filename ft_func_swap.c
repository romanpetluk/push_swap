
#include "push_swap.h"

int ft_count_elem(t_swap *a)
{
    int i;

    i = 0;
    if (a)
    {
        while (a)
        {
            if (i > 3)
                return (0);
            a = a->next;
            i++;
        }
    }
    return (i);
}
int ft_count_grup(t_swap *a)
{
    t_swap *temp;
    int i;
    int grp;

    i = 0;
    if (a)
    {
        grp = a->grp;
        temp = a->next;
        while (temp)
        {
            if (temp->grp != a->grp)// || i > 3)
                i++;
            temp = temp->next;
            a = a->next;
        }
    }
    return (i);
}

int ft_swap_dubl(t_swap *a)
{
    t_swap *temp;

    temp = a;
    while (a)
    {
        temp = a->next;
        while (temp)
        {
            if (temp->num == a->num)
            {
                write(1, "Error\n", 6);
                exit (0);
            }
            temp = temp->next;
        }
        a = a->next;
    }
    return (1);
}

int ft_swap_error(char *s, t_swap **a, int i)
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
        while (s[i] == ' ')
            i++;
        while (s[i] >= '0' && s[i] <= '9')
        {
            num *= 10;
            num += ((s[i] - 48) * n);
            if (num > 2147483647 || num < -2147483648)
                return (-1);
            i++;
        }
        if (!(ft_newlist_swap(a, num)))
            return (-1);
        while (s[i] == ' ')
            i++;
    }
    if (s[i] == '\0')
        return (1);
    return(-1);
}

int ft_newlist_swap(t_swap **a, int num)
{
    t_swap  *new;
    t_swap  *temp;

    if (!(new = (t_swap*)malloc(sizeof(t_swap))))
        return (0);
    temp = *a;
    new->next = NULL;
    new->num = num;
    new->grp = 0;
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