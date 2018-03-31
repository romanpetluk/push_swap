
#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list_swap *stack_a;
    t_list_swap *stack_b;
    int         i;

    stack_a = NULL;
    stack_b = NULL;
    i = 1;
    while (argc > i)
    {
        if (!(ft_newlist(&stack_a, ft_atoi_swap(argv[i]))))
            return (0);
        i++;
    }
    ft_comands("rra" ,stack_a, stack_b);
}