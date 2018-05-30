/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 13:45:45 by rpetluk           #+#    #+#             */
/*   Updated: 2018/05/06 13:49:38 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

void ft_statistics(t_variables *var)
{
    ft_printf("sa: = %-12dpa: = %-12dra: = %-12drra: = %-12d\n"
            , var->sa, var->pa, var->ra, var->rra);
    ft_printf("sb: = %-12dpb: = %-12drb: = %-12drrb: = %-12d\n"
            , var->sb, var->pb, var->rb, var->rrb);
    ft_printf("ss: = %-30drr: = %-12drrr: = %-12d\n"
			, var->ss, var->rr, var->rrr);
    ft_printf("\nall: %d\n"
			, (var->sa + var->pa + var->ra + var->rra + var->sb
			   + var->pb + var->rb + var->rrb + var->ss + var->rr + var->rrr));
}

void	ft_stack_print(t_variables *var, char *s, int com)
{
	t_list_swap *temp_a;
	t_list_swap *temp_b;

	temp_a = var->a;
	temp_b = var->b;
	ft_printf("command: %s\n", s);
	if (temp_a || temp_b)
	{
		ft_printf("stack_a      stack_b\n");
		colour(&temp_a, &temp_b, com);
		colour_0(&temp_a, &temp_b);
	}
	ft_printf("\n");
}

void ft_stack_debug(t_swap *a, t_swap *b)
{
	if (a || b)
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

