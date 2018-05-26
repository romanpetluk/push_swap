#include "checker.h"

void	ft_stack_print(t_list_swap *a, t_list_swap *b, char *s)
{
	ft_printf("command: %s\n", s);
	if (a || b)
		ft_printf("stack_a      stack_b\n");
	while (a || b)
	{
		if (a && b)
		{
			ft_printf("%-12d% d", a->num, b->num);
			a = a->next;
			b = b->next;
		}
		else if (a)
		{
			ft_printf("%d", a->num);
			a = a->next;
		}
		else if (b)
		{
			ft_printf("%13c%d", ' ', b->num);
			b = b->next;
		}
		ft_printf("\n");
	}
	ft_printf("\n");
}

void colour_ss()