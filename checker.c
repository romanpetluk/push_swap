
#include "push_swap.h"

int ft_check_error(int argc,char *s, t_list_swap **a)
{
    int i;
    int num;
    int n;

    n = 1;
    i = 0;
    if (str[i] == '-')
        n = -1;
    while ((s[i] >= '0' && s[i] <= '9') || s[i] == ' ')
    {
        num = 0;
        while (s[i] >= '0' && s[i] <= '9')
        {
            num *= 10;
            num += ((s[i] - 48) * n);
            i++;
        }
        if (!(ft_newlist(a, num)))
            return (-1);
        if (s[i] == ' ')
            i++;
    }
    if (s[i] == '\0')
        return (1);
    write(1, "Error\n", 6);
    return(-1);
}

int ft_check_sort(t_list_swap *a, t_list_swap *b)
{
    t_list_swap *temp;

    if (a)
    {
        temp = a->next;
        while (temp)
        {
            if (temp->num < a->num)
            {
                write(1, "KO\n", 3);
                return (-1);
            }
            temp = temp->next;
            a = a->next;
        }
        if (b)
        {
            write(1, "KO\n", 3);
            return (-1);
        }
        write(1, "OK\n", 3);
        return (1);
    }
    return (0);
}

int main(int argc, char **argv)
{
    t_list_swap *stack_a;
    t_list_swap *stack_b;
    int         i;
    char *s;

    stack_a = NULL;
    stack_b = NULL;
    i = 1;
    while (argc > i)
    {
        ft_check_error(argc, argv[i], &stack_a);
        i++;
    }
    while (get_next_line(0, &s) > 0)
        ft_com_cmp(s, &stack_a, &stack_b);
    ft_comands_test(stack_a, stack_b);
    ft_check_sort(stack_a, stack_b);
}