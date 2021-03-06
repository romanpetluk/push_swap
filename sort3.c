/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 11:33:41 by rpetluk           #+#    #+#             */
/*   Updated: 2018/05/31 11:33:42 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_check_swap_b(t_swap *a)
{
	int		i;
	int		num;
	int		grp;

	i = 0;
	if (a)
	{
		grp = a->grp;
		if (a)
		{
			while (a->next)
			{
				num = a->num;
				a = a->next;
				if (a->grp != grp)
					return (0);
				i++;
				if (num < a->num)
					return (i);
			}
		}
	}
	return (0);
}

int			ft_check_swap(t_swap *s_a)
{
	int		a;
	int		b;
	int		c;

	if (ft_count_elem_grup(s_a) == 2)
	{
		if (s_a->next && s_a->num > s_a->next->num)
			return (1);
		return (0);
	}
	a = s_a->num;
	b = s_a->next->num;
	c = s_a->next->next->num;
	if (a > b && a > c && b < c && ft_count_elem(s_a) < 4)
	{
		return (3);
	}
	if (a > b)
		return (1);
	else if (b > c)
		return (2);
	else
		return (0);
}

static void	sort_ss(t_var_s *var)
{
	int		ib;

	ib = ft_check_swap_b(var->b);
	if (ib == 1)
	{
		ft_swap_sa(&(var->a));
		ft_swap_sa(&(var->b));
		write(var->fd, "ss\n", 3);
	}
	else
	{
		ft_swap_sa(&(var->a));
		write(var->fd, "sa\n", 3);
	}
}

static void	ft_sort32(t_var_s *var, int ib)
{
	if (ft_count_elem(var->a) < 4 && var->i == 2)
	{
		ft_swap_rra(&(var->a));
		write(var->fd, "rra\n", 4);
	}
	else if (var->i == 2 && ib == 2)
	{
		ft_swap_ra(&(var->a));
		ft_swap_ra(&(var->b));
		ft_swap_sa(&(var->b));
		ft_swap_sa(&(var->a));
		ft_swap_rra(&(var->a));
		ft_swap_rra(&(var->b));
		write(var->fd, "rr\nss\nrrr\n", 10);
	}
	else if (var->i == 2)
	{
		ft_swap_ra(&(var->a));
		write(var->fd, "ra\n", 3);
		sort_ss(var);
		ft_swap_rra(&(var->a));
		write(var->fd, "rra\n", 4);
	}
}

int			ft_sort3(t_var_s *var)
{
	int		ib;
	t_swap	*temp;

	var->grp = var->a->grp;
	temp = var->a;
	while (temp && temp->grp == var->grp)
	{
		temp->grp = 0;
		temp = temp->next;
	}
	while ((var->i = ft_check_swap(var->a)))
	{
		ib = ft_check_swap_b(var->b);
		if (var->i == 1)
			sort_ss(var);
		else if (var->i == 2)
			ft_sort32(var, ib);
		else if (var->i == 3)
		{
			ft_swap_ra(&(var->a));
			write(var->fd, "ra\n", 3);
		}
	}
	return (0);
}
