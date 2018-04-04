
#include "push_swap.h"


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
        if (ft_check_error(argv[i], &stack_a, 0) == -1)
        {
            write(1, "Error\n", 6);
            return (-1);
        }
        i++;
    }
    if (ft_check_dubl(stack_a) == -1)
    {
        write(1, "Error\n", 6);
        return (-1);
    }
    while (get_next_line(0, &s) > 0)
        ft_com_cmp(s, &stack_a, &stack_b);
    ft_comands_test(stack_a, stack_b);
    ft_check_sort(stack_a, stack_b);
}