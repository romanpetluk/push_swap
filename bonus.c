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

#include "push_swap.h"

int		ft_flag_fd_swap(char **av, int i)
{
	int	fd;

	if (ft_strcmp(av[i], "-fd") == 0)
	{
		fd = open(av[i + 1], O_CREAT | O_RDWR | O_TRUNC, S_IWRITE | S_IREAD);
		return (fd);
	}
	return (0);
}

void ft_statistics(t_variables *var)
{
    ft_printf("sa = %-12dpa = %-12dra = %-12drra = %-12d\n"
            , var->sa, var->pa, var->ra, var->rra);
    ft_printf("sb = %-12dpb = %-12drb = %-12drrb = %-12d\n"
            , var->sb, var->pb, var->rb, var->rrb);
    ft_printf("ss = %-29drr = %-12drrr = %-12d\n", var->ss, var->rr, var->rrr);
}

void	ft_stack_print(t_list_swap *a, t_list_swap *b)
{
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
