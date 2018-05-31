/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 11:42:33 by rpetluk           #+#    #+#             */
/*   Updated: 2018/05/31 11:42:35 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_swap_sa(t_swap **a)
{
	t_swap	*temp;

	if (*a && (*a)->next)
	{
		temp = *a;
		*a = (*a)->next;
		temp->next = (*a)->next;
		(*a)->next = temp;
	}
}

void		ft_swap_pa(t_swap **a, t_swap **b)
{
	t_swap	*temp;

	if (*b)
	{
		temp = *b;
		*b = (*b)->next;
		if (*a)
			temp->next = *a;
		else
			temp->next = NULL;
		*a = temp;
	}
}

void		ft_swap_ra(t_swap **a)
{
	t_swap	*temp;

	if (*a && (*a)->next)
	{
		temp = *a;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = *a;
		temp = temp->next;
		*a = (*a)->next;
		temp->next = NULL;
	}
}

void		ft_swap_rra(t_swap **a)
{
	t_swap	*temp;
	t_swap	*temp2;

	if (*a && (*a)->next)
	{
		temp = *a;
		temp2 = *a;
		while (temp->next)
		{
			temp2 = temp;
			temp = temp->next;
		}
		temp2->next = NULL;
		temp->next = *a;
		*a = temp;
	}
}
