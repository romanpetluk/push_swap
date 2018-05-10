/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 13:50:00 by rpetluk           #+#    #+#             */
/*   Updated: 2018/05/06 13:50:59 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_com_cmp3(char *s, t_variables *var)
{
	if (ft_strcmp(s, "rra") == 0)
    {
        ft_rra(&(var->a));
        var->rra++;
    }
	else if (ft_strcmp(s, "rrb") == 0)
    {
        ft_rra(&(var->b));
        var->rrb++;
    }
	else if (ft_strcmp(s, "rrr") == 0)
	{
        ft_rra(&(var->a));
        ft_rra(&(var->b));
        var->rra++;
        var->rrb++;
	}
	else
	{
		write(1, "Error\n", 6);
		exit (0);
	}
}

static void	ft_com_cmp2(char *s, t_variables *var)
{
    if (ft_strcmp(s, "pb") == 0)
    {
        ft_pa(&(var->b), &(var->a));
        var->pb++;
    }
    else if (ft_strcmp(s, "ra") == 0)
    {
        ft_ra(&(var->a));
        var->ra++;
    }
    else if (ft_strcmp(s, "rb") == 0)
    {
        ft_ra(&(var->b));
        var->rb++;
    }
    else if (ft_strcmp(s, "rr") == 0)
    {
        ft_ra(&(var->a));
        ft_ra(&(var->b));
        var->ra++;
        var->rb++;
    }
    else
        ft_com_cmp3(s, var);
}

void		ft_com_cmp(char *s, t_variables *var)
{
	if (ft_strcmp(s, "sa") == 0)
	{
		ft_sa(&(var->a));
        var->sa++;
	}
	else if (ft_strcmp(s, "sb") == 0)
    {
        ft_sa(&(var->b));
        var->sb++;
    }
	else if (ft_strcmp(s, "ss") == 0)
	{
        ft_sa(&(var->a));
        ft_sa(&(var->b));
        var->sa++;
        var->sb++;
	}
	else if (ft_strcmp(s, "pa") == 0)
    {
        ft_pa(&(var->a), &(var->b));
        var->pa++;
    }
    else
        ft_com_cmp2(s, var);
}


