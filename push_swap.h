#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"

typedef struct s_struct
{
	int 			value;
	int 			order;
	int 			flag;
	struct s_struct	*next;
}					t_stack;

void	ft_numintolist(t_stack **seq, t_stack *new);
t_stack *ft_lstlast(t_stack *seq);
t_stack	*ft_lstnew(int content, int order);
void	ft_order(t_stack **seq, int order);
//void	ft_lstaddprelast(t_stack **lst);
void	ft_swaptwo(t_stack **seq, char *str);
//t_stack *ft_pushelem(t_stack **a, t_stack **b, char *str);
void 	ft_pushelem(t_stack **a, t_stack **b, char *str);
//t_stack *ft_rotate(t_stack **seq, char *str);
void	ft_rotate(t_stack **seq, char *str);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
//t_stack *ft_re_rotate(t_stack **seq, char *str);
void	ft_re_rotate(t_stack **seq, char *str);
void	ft_count(t_stack **seq, int order);
void	ft_three(t_stack **seq);
void	ft_four(t_stack **seq);
void	ft_error(int code);
t_stack	*ft_pushswap(char **argv, int argc);
void	ft_fourtofive(t_stack **seq);
void	ft_prelast(t_stack **seq);
void	ft_five(t_stack **seq);

#endif
