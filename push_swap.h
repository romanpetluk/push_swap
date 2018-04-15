//
// Created by Roman PETLUK on 2/23/18.
//

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct		    s_list_swap
{
	int				    num;
	struct s_list_swap  *next;
}					    t_list_swap;

typedef struct		    s_swap
{

    int				    num;
    int                 grp;
    struct s_swap  *next;
}					    t_swap;

int                     ft_newlist(t_list_swap **stack_a, int num);
int                     ft_check_error(char *s, t_list_swap **a, int i);
int                     ft_check_dubl(t_list_swap *a);
//int						ft_atoi_swap(const char *str);
void                    ft_sa(t_list_swap **a);
void					ft_pa(t_list_swap **a, t_list_swap **b);
void                    ft_ra(t_list_swap **a);
void					ft_rra(t_list_swap **a);
void 					ft_comands(char *s, t_list_swap *a, t_list_swap *b);

int                     ft_swap_dubl(t_swap *a);
int                     ft_swap_error(char *s, t_swap **a, int i);
int                     ft_newlist_swap(t_swap **a, int num);
void                    ft_swap_sa(t_swap **a);
void                    ft_swap_pa(t_swap **a, t_swap **b);
void                    ft_swap_ra(t_swap **a);
void                    ft_swap_rra(t_swap **a);
void                    ft_com_cmp(char *s, t_list_swap **a, t_list_swap **b);
int                     ft_flag_fd_swap(char **av, int i);
int                     ft_median(t_swap *a);

void                    ft_stack_print(t_list_swap *a, t_list_swap *b);
int                     ft_flag_fd(char **av, int i);

#endif
