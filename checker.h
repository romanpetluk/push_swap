
#ifndef SUB_CHECKER_H
#define SUB_CHECKER_H

# include "libft/libft.h"

typedef struct		    s_list_swap
{
    int				    num;
    int                 grp;
    struct s_list_swap  *next;
}					    t_list_swap;

typedef struct		    s_variables
{
    t_list_swap			*a;
    t_list_swap			*b;
    int                 i;
    int                 fd;
    int                 c;
    int                 stat;
    int				    sa;
    int				    sb;
    int				    ss;
    int				    pa;
    int				    pb;
    int				    ra;
    int				    rb;
    int				    rr;
    int				    rra;
    int				    rrb;
    int				    rrr;
}					    t_variables;

int                     ft_newlist(t_list_swap **stack_a, int num);
int                     ft_check_error(char *s, t_list_swap **a, int i);
int                     ft_check_dubl(t_list_swap *a);
void                    ft_sa(t_list_swap **a);
void					ft_pa(t_list_swap **a, t_list_swap **b);
void                    ft_ra(t_list_swap **a);
void					ft_rra(t_list_swap **a);
void 					ft_comands(char *s, t_list_swap *a, t_list_swap *b);
int	                    ft_com_cmp(char *s, t_variables *var);

void ft_statistics(t_variables *var);
void	ft_stack_print(t_variables *var, char *s, int i);
void colour(t_list_swap **a, t_list_swap **b, int com);
void colour_0(t_list_swap **a, t_list_swap **b);

#endif
