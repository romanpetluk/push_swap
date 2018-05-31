/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push_swap_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 10:26:55 by rpetluk           #+#    #+#             */
/*   Updated: 2018/05/31 10:26:56 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_check_sort(t_swap *a)
{
	int		num;

	while (a->next)
	{
		num = a->num;
		a = a->next;
		if (num > a->num)
			return (1);
	}
	return (0);
}

int			ft_check_median(t_swap *a, int med)
{
	while (a)
	{
		if (a->num < med)
			return (1);
		a = a->next;
	}
	return (0);
}

int			ft_count_elem_grup(t_swap *a)
{
	int		i;
	int		grp;

	i = 0;
	if (a)
	{
		grp = a->grp;
		while (a && a->grp == grp)
		{
			a = a->next;
			i++;
		}
	}
	return (i);
}

int			ft_count_elem(t_swap *a)
{
	int i;

	i = 0;
	if (a)
	{
		while (a)
		{
			a = a->next;
			i++;
		}
	}
	return (i);
}

int			ft_count_grup(t_swap *a)
{
	int		grp;
	int		i;

	i = 0;
	if (a)
	{
		grp = a->grp;
		while (a)
		{
			if (grp != a->grp)
				i++;
			a = a->next;
		}
	}
	return (i);
}
