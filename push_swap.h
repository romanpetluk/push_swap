/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 11:00:51 by rpetluk           #+#    #+#             */
/*   Updated: 2018/05/31 11:00:52 by rpetluk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct			s_swap
{
	int					num;
	int					grp;
	struct s_swap		*next;
}						t_swap;

typedef struct			s_variables_s
{
	t_swap				*a;
	t_swap				*b;
	int					v;
	int					i;
	int					fd;
	int					med_a;
	int					med_b;
	int					grp;
	int					count_ra;
}						t_var_s;

int						ft_swap_dubl(t_swap *a);
int						ft_swap_error(char *s, t_swap **a);
int						ft_newlist_swap(t_swap **a, int num);
void					ft_swap_sa(t_swap **a);
void					ft_swap_pa(t_swap **a, t_swap **b);
void					ft_swap_ra(t_swap **a);
void					ft_swap_rra(t_swap **a);
int						ft_median(t_swap *a);
void					ft_qsort(t_var_s *var);
void					ft_qsort_b(t_var_s *var);
int						ft_count_elem(t_swap *a);
int						ft_count_grup(t_swap *a);

int						ft_check_sort(t_swap *a);
int						ft_check_median(t_swap *a, int med);
int						ft_check_swap(t_swap *a);
int						ft_check_swap_b(t_swap *a);

void					ft_stack_debug(t_swap *a, t_swap *b);
int						ft_check_qsortb(t_swap *b);
int						ft_count_elem_grup(t_swap *a);
int						ft_sort3(t_var_s *var);

#endif
