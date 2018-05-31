/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 11:16:37 by rpetluk           #+#    #+#             */
/*   Updated: 2018/05/31 11:16:39 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_div_median(t_var_s *var)
{
	while (ft_check_median(var->a, var->med_a))
	{
		if (var->a->num < var->med_a)
		{
			var->a->grp += var->grp;
			ft_swap_pa(&(var->b), &(var->a));
			write(var->fd, "pb\n", 3);
		}
		else if (var->b && var->b->num < var->med_b
				&& ft_count_grup(var->b) == 0)
		{
			ft_swap_ra(&(var->a));
			ft_swap_ra(&(var->b));
			write(var->fd, "rr\n", 3);
			var->count_ra++;
		}
		else
		{
			ft_swap_ra(&(var->a));
			write(var->fd, "ra\n", 3);
			var->count_ra++;
		}
	}
}

void			next_median(t_var_s *var)
{
	int			i;

	i = 0;
	while (i < var->count_ra)
	{
		ft_swap_rra(&(var->a));
		i++;
	}
	var->med_a = ft_median(var->a);
	while (i--)
	{
		ft_swap_ra(&(var->a));
	}
}

void			ft_qsort2(t_var_s *var)
{
	while (ft_count_grup(var->a) && var->count_ra--)
	{
		ft_swap_rra(&(var->a));
		write(var->fd, "rra\n", 4);
		if (var->a->num < var->med_a)
		{
			var->a->grp += (var->grp + 1);
			ft_swap_pa(&(var->b), &(var->a));
			write(var->fd, "pb\n", 3);
		}
	}
}

void			ft_qsort(t_var_s *var)
{
	while (var->b || ft_check_sort(var->a))
	{
		var->grp = 0;
		var->med_a = ft_median(var->a);
		while (ft_count_elem_grup(var->a) > 3 && ft_check_sort(var->a))
		{
			var->count_ra = 0;
			var->grp++;
			if (var->b)
				var->med_b = ft_median(var->b);
			ft_div_median(var);
			if (var->v == 1)
				ft_stack_debug(var->a, var->b);
			next_median(var);
			ft_qsort2(var);
		}
		ft_sort3(var);
		if (var->v == 1)
			ft_stack_debug(var->a, var->b);
		ft_qsort_b(var);
		if (var->v == 1)
			ft_stack_debug(var->a, var->b);
	}
}
