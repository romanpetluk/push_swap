/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 13:51:31 by rpetluk           #+#    #+#             */
/*   Updated: 2018/05/06 13:56:50 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int ft_init(t_variables **var)
{
    t_variables *temp;

    if (!(temp = (t_variables *)malloc(sizeof(t_variables))))
        return (0);
    temp->a = NULL;
    temp->b = NULL;
    temp->i = 1;
    temp->fd = 0;
//    temp->v = 0;
    temp->c = 0;
    temp->stat = 0;
    temp->sa = 0;
    temp->sb = 0;
    temp->ss = 0;
    temp->pa = 0;
    temp->pb = 0;
    temp->ra = 0;
    temp->rb = 0;
    temp->rr = 0;
    temp->rra = 0;
    temp->rrb = 0;
    temp->rrr = 0;
    *var = temp;
    return (1);
}

static int				ft_flag(char **s, t_variables *var)
{
    if (ft_strcmp(s[var->i], "-c") == 0)
    {
        var->c = 1;
        return (1);
    }
    else if (ft_strcmp(s[var->i], "-s") == 0)
    {
        var->stat = 1;
        return (1);
    }
    else if (ft_strcmp(s[var->i], "-fd") == 0)
    {
        var->fd = (open(s[++var->i], O_RDONLY));
        return (1);
    }
    return (0);
}

int					ft_check_sort(t_list_swap *a, t_list_swap *b)
{
	t_list_swap		*temp;

	if (a)
	{
		temp = a->next;
		while (temp)
		{
			if (temp->num < a->num)
			{
				write(1, "KO\n", 3);
				exit(0);
			}
			temp = temp->next;
			a = a->next;
		}
		if (b)
		{
			write(1, "KO\n", 3);
			exit(0);
		}
		write(1, "OK\n", 3);
		return (1);
	}
	return (0);
}

static void			checker(t_variables *var)
{
    char			*s;
	int				i;

    if (!var->a)
        exit (0);
    ft_check_dubl(var->a);
    while (get_next_line(var->fd, &s) > 0)
    {
        i = ft_com_cmp(s, var);
        if (var->c == 1)
            ft_stack_print(var, s, i);
    }
    if (var->stat == 1)
        ft_statistics(var);
}

int				main(int argc, char **argv)
{
    t_variables *var;

	if (argc < 2)
		exit (0);
    ft_init(&var);
	while (ft_flag(argv, var))
    {
        var->i++;
        if (argc < var->i + 1)
            exit (0);
    }
	while (argc > var->i)
		if (ft_check_error(argv[var->i++], &(var->a), 0) == -1)
		{
			write(1, "Error\n", 6);
			exit (0);
            var->i++;
		}
	checker(var);
    ft_check_sort(var->a, var->b);
}