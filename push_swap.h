#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_struct
{
	int 			value;
	int 			order;
	int 			flag;
	struct s_struct	*next;
}					t_stack;

t_stack *ft_parse(int argc, char **argv);
void	ft_numintolist(t_stack **seq, t_stack *new);
t_stack *ft_lstlast(t_stack *seq);
t_stack	*ft_lstnew(int content, int order);
t_stack *ft_order(t_stack **seq, int order);
t_stack *ft_swaptwo(t_stack **seq);
t_stack *ft_pushelem(t_stack **a, t_stack **b);

#endif
