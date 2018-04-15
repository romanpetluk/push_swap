#include "push_swap.h"

static void ft_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


static int ft_partition(int *m, int left, int right)
{
    int pivot;
    int i = left;
    int x;

    pivot = m[right];
    i = left;
    for (x = left; x < right; x++)
    {
        if (m[x] <= pivot)
        {
            ft_swap(&m[i], &m[x]);
            i++;
        }
    }
    ft_swap(&m[i], &m[right]);
    return i;
}


static int ft_quickselect(int *m, int left, int right, int k)
{
    int p = ft_partition(m, left, right);

    if (p == k - 1)
    {
        return m[p];
    }
    else if (k - 1 < p)
    {
        return ft_quickselect(m, left, p - 1, k);
    }
    else
    {
        return ft_quickselect(m, p + 1, right, k);
    }
}

static int ft_count(t_swap *a)
{
    int i;

    i = 0;
    while (a)
    {
        a = a->next;
        i++;
    }
    return (i);
}

int ft_median(t_swap *a)
{
    int i;
    int *m;

    i = 0;
    m = (int *)malloc(sizeof(int) * (ft_count(a) + 1));
    while (a)
    {
        m[i] = a->num;
        a = a->next;
        i++;
    }
    return (ft_quickselect(m, 0, i - 1, (i / 2) + 1));
}