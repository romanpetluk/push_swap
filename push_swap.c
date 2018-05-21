
#include "push_swap.h"

void ft_stack_print_test(t_swap *a, t_swap *b)
{
        ft_printf("stack_a      stack_b\n");
    while (a || b)
    {
        if (a && b)
        {
            ft_printf("%d %-12d %d % d", a->grp, a->num,b->grp, b->num);
            a = a->next;
            b = b->next;
        }
        else if (a)
        {
            ft_printf("%d %d",a->grp , a->num);
            a = a->next;
        }
        else if (b)
        {
            ft_printf("%16d  %d", b->grp, b->num);
            b = b->next;
        }
        ft_printf("\n");
    }
    ft_printf("\n");
}

static int ft_init(t_var_s **var)
{
    t_var_s *temp;
    if (!(temp = (t_var_s*)malloc(sizeof(t_var_s))))
        return (0);
    temp->a = NULL;
    temp->b = NULL;
    temp->i = 1;
    temp->fd = 1;
    temp->med_a = 0;
    temp->med_b = 0;
    temp->grp = 0;
    temp->count_ra = 0;
    *var = temp;
    return (1);
}

int main(int argc, char **argv)
{
    t_var_s     *var;

    if (argc < 2)
        exit (0);
    ft_init(&var);
    if (argc > var->i + 2 && (var->fd = ft_flag_fd_swap(argv, var->i)))
        var->i += 2;
    if (var->fd < 1)
        var->fd = 1;
    while (argc > var->i)
    {
        if (ft_swap_error(argv[var->i], &(var->a), 0) == -1)
        {
            write(1, "Error\n", 6);
            return (-1);
        }
        var->i++;
    }
    ft_swap_dubl(var->a);
    ft_qsort(var);
}