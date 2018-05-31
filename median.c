/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 10:49:03 by rpetluk           #+#    #+#             */
/*   Updated: 2018/05/31 10:49:05 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_swap(int *a, int *b)
{
	int			temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int		ft_partition(int *m, int left, int right)
{
	int			pivot;
	int			i;
	int			x;

	pivot = m[right];
	i = left;
	x = left;
	while (x < right)
	{
		if (m[x] <= pivot)
		{
			ft_swap(&m[i], &m[x]);
			i++;
		}
		x++;
	}
	ft_swap(&m[i], &m[right]);
	return (i);
}

static int		ft_quickselect(int *m, int left, int right, int k)
{
	int			p;

	p = ft_partition(m, left, right);
	if (p == k - 1)
	{
		return (m[p]);
	}
	else if (k - 1 < p)
	{
		return (ft_quickselect(m, left, p - 1, k));
	}
	else
	{
		return (ft_quickselect(m, p + 1, right, k));
	}
}

static int		ft_count(t_swap *a)
{
	int			i;
	int			grp;

	grp = a->grp;
	i = 0;
	while (a && a->grp == grp)
	{
		a = a->next;
		i++;
	}
	return (i);
}

int				ft_median(t_swap *a)
{
	int			i;
	int			*m;
	int			grp;
	int			ret;

	i = 0;
	grp = a->grp;
	m = (int *)malloc(sizeof(int) * (ft_count(a) + 1));
	while (a && grp == a->grp)
	{
		m[i] = a->num;
		a = a->next;
		i++;
	}
	ret = ft_quickselect(m, 0, i - 1, (i / 2) + 1);
	free(m);
	return (ret);
}
