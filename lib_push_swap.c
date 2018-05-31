/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 10:21:40 by rpetluk           #+#    #+#             */
/*   Updated: 2018/05/31 10:21:41 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_swap_dubl(t_swap *a)
{
	t_swap	*temp;

	temp = a;
	while (a)
	{
		temp = a->next;
		while (temp)
		{
			if (temp->num == a->num)
			{
				write(1, "Error\n", 6);
				exit(0);
			}
			temp = temp->next;
		}
		a = a->next;
	}
	return (1);
}

int			ft_swap_error2(char *s, t_swap **a, int i, int n)
{
	long	num;

	while ((s[i] >= '0' && s[i] <= '9') || s[i] == ' ' ||
			(s[i] == '-' && s[i + 1]))
	{
		num = 0;
		if (s[i] == '-')
			n = -1;
		if (s[i] == '-')
			i++;
		while (s[i] == ' ')
			i++;
		while (s[i] >= '0' && s[i] <= '9')
		{
			num *= 10;
			num += ((s[i++] - 48) * n);
			if (num > 2147483647 || num < -2147483648)
				return (-1);
		}
		if (!(ft_newlist_swap(a, num)))
			return (-1);
		while (s[i] == ' ')
			i++;
	}
	return (i);
}

int			ft_swap_error(char *s, t_swap **a)
{
	int		i;

	i = ft_swap_error2(s, a, 0, 1);
	if (s[i] == '\0')
		return (1);
	return (-1);
}

int			ft_newlist_swap(t_swap **a, int num)
{
	t_swap	*new;
	t_swap	*temp;

	if (!(new = (t_swap*)malloc(sizeof(t_swap))))
		return (0);
	temp = *a;
	new->next = NULL;
	new->num = num;
	new->grp = 0;
	if (*a)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	else
		*a = new;
	return (1);
}
