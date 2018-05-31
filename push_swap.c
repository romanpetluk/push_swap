/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 10:54:45 by rpetluk           #+#    #+#             */
/*   Updated: 2018/05/31 10:54:46 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			stack_del(t_swap **a, t_swap **b)
{
	t_swap		*temp;

	while (*a)
	{
		temp = *a;
		*a = (*a)->next;
		free(temp);
	}
	while (*b)
	{
		temp = *b;
		*b = (*b)->next;
		free(temp);
	}
	*a = NULL;
	*b = NULL;
}

static int		ft_init(t_var_s **var)
{
	t_var_s		*temp;

	if (!(temp = (t_var_s*)malloc(sizeof(t_var_s))))
		return (0);
	temp->a = NULL;
	temp->b = NULL;
	temp->i = 1;
	temp->fd = 1;
	temp->med_a = 0;
	temp->med_b = 0;
	temp->grp = 0;
	temp->count_ra = 0;
	*var = temp;
	return (1);
}

static int		ft_flag(char **s, t_var_s *var)
{
	if (ft_strcmp(s[var->i], "-v") == 0)
	{
		var->v = 1;
		return (1);
	}
	else if (ft_strcmp(s[var->i], "-fd") == 0)
	{
		var->fd = open(s[++var->i], O_CREAT
									| O_RDWR | O_TRUNC, S_IWRITE | S_IREAD);
		return (2);
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_var_s		*var;

	ft_init(&var);
	if (argc < 2)
		exit(0);
	while (ft_flag(argv, var))
	{
		var->i++;
		if (argc < var->i + 1)
			exit(0);
	}
	while (argc > var->i)
	{
		if (ft_swap_error(argv[var->i], &(var->a)) == -1)
		{
			write(1, "Error\n", 6);
			return (-1);
		}
		var->i++;
	}
	ft_swap_dubl(var->a);
	if (var->v == 1)
		ft_stack_debug(var->a, var->b);
	ft_qsort(var);
	stack_del(&(var->a), &(var->b));
}
