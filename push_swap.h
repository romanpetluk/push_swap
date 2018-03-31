//
// Created by Roman PETLUK on 2/23/18.
//

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

//# include <unistd.h>
//# include <stdlib.h>
//# include <fcntl.h>
//# include <stdio.h>
# include "libft/libft.h"

typedef struct		    s_list_swap
{
	int				    num;
	struct s_list_swap  *next;
}					    t_list_swap;

int                     ft_newlist(t_list_swap **stack_a, int num);
int						ft_atoi_swap(const char *str);
void                    ft_sa(t_list_swap **a);
void					ft_pa(t_list_swap **a, t_list_swap **b);
void                    ft_ra(t_list_swap **a);
void					ft_rra(t_list_swap **a);
void 					ft_comands(char *s, t_list_swap *a, t_list_swap *b);

void ft_comands_test(t_list_swap *a, t_list_swap *b);
void ft_com_cmp(char *s, t_list_swap **a, t_list_swap **b);

#endif
