/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_colour.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 09:28:10 by rpetluk           #+#    #+#             */
/*   Updated: 2018/05/31 09:28:14 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		colour_sa(t_list_swap **a, t_list_swap **b)
{
	if (*a && *b)
	{
		ft_printf(KRED"%-12d", (*a)->num);
		ft_printf(KNRM"% d", (*b)->num);
		*a = (*a)->next;
		*b = (*b)->next;
	}
	else if (*a)
	{
		ft_printf(KRED"%d", (*a)->num);
		*a = (*a)->next;
	}
	else if (*b)
	{
		ft_printf(KNRM"%13c%d", ' ', (*b)->num);
		*b = (*b)->next;
	}
	ft_printf(KNRM"\n");
}

void		colour_sb(t_list_swap **a, t_list_swap **b)
{
	if (*a && *b)
	{
		ft_printf(KNRM"%-12d", (*a)->num);
		ft_printf(KRED"% d", (*b)->num);
		*a = (*a)->next;
		*b = (*b)->next;
	}
	else if (*a)
	{
		ft_printf(KNRM"%d", (*a)->num);
		*a = (*a)->next;
	}
	else if (*b)
	{
		ft_printf(KRED"%13c%d", ' ', (*b)->num);
		*b = (*b)->next;
	}
	ft_printf(KNRM"\n");
}

void		colour_ss(t_list_swap **a, t_list_swap **b)
{
	if (*a && *b)
	{
		ft_printf(KRED "%-12d% d", (*a)->num, (*b)->num);
		*a = (*a)->next;
		*b = (*b)->next;
	}
	else if (*a)
	{
		ft_printf(KRED"%d", (*a)->num);
		*a = (*a)->next;
	}
	else if (*b)
	{
		ft_printf(KRED"%13c%d", ' ', (*b)->num);
		*b = (*b)->next;
	}
	ft_printf(KNRM"\n");
}

void		colour_0(t_list_swap **a, t_list_swap **b)
{
	while (*a || *b)
	{
		if (*a && *b)
		{
			ft_printf("%-12d% d", (*a)->num, (*b)->num);
			*a = (*a)->next;
			*b = (*b)->next;
		}
		else if (*a)
		{
			ft_printf("%d", (*a)->num);
			*a = (*a)->next;
		}
		else if (*b)
		{
			ft_printf("%13c%d", ' ', (*b)->num);
			*b = (*b)->next;
		}
		ft_printf("\n");
	}
}

void		colour(t_list_swap **a, t_list_swap **b, int com)
{
	int i;

	i = 0;
	if (com == 1)
		while (i++ < 2)
			colour_sa(a, b);
	else if (com == 2)
		while (i++ < 2)
			colour_sb(a, b);
	else if (com == 3)
		while (i++ < 2)
			colour_ss(a, b);
	else if (com == 4)
		colour_sa(a, b);
	else if (com == 8)
		colour_sb(a, b);
	else if (com == 5)
		while (*a)
			colour_sa(a, b);
	else if (com == 6)
		while (*b)
			colour_sb(a, b);
	else if (com == 7)
		while (*a || *b)
			colour_ss(a, b);
}
