
#include "push_swap.h"

void        ft_addlist(t_list_swap **stack_a, t_list_swap *temp)
{
    if (stack_a && temp)
    {
        temp->next = *stack_a;
        *stack_a = temp;
    }
}

t_list_swap        *ft_newlist()
{
    t_list_swap	*ret;

    if (!(ret = (t_list_swap*)malloc(sizeof(t_list_swap))))
        return (NULL);
    ret->num = 0;
    ret->next = NULL;
    return (ret);
}

int main(int argc, char **argv)
{
    t_list_swap *stack_a;
    t_list_swap *stack_b;

    int i;

    i = 1;
    //stack_b = ft_newlist(stack_b);
    while (argc > i)
    {
        ft_addlist(&stack_a, ft_newlist(stack_a));
        stack_a->num = ft_atoi(argv[i]);
        i++;
    }
//    if (stack_a && stack_a->next)
//        stack_a = ft_sa(stack_a);
    ft_pa(&stack_b, &stack_a);
    while (stack_a)
    {
        ft_printf("%d\n", stack_a->num);
        stack_a = stack_a->next;
    }
    while (stack_b)
    {
        ft_printf("%d\n", stack_b->num);
        stack_b = stack_a->next;
    }
}