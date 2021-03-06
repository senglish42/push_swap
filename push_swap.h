#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include "./bonus/get_next_line.h"

typedef struct s_struct
{
	int				value;
	int				order;
	int				top;
	int				reverse;
	int				b_rotate;
	int				a_reverse;
	int				a_rotate;
	int				b_reverse;
	char			loop;
	struct s_struct	*next;
}					t_stack;

t_stack	*settings(t_stack **b);
void	ft_numintolist(t_stack **seq, t_stack *new);
t_stack	*ft_lstlast(t_stack *seq);
t_stack	*ft_lstnew(int content, int order);
void	ft_order(t_stack **seq, int order);
void	ft_swaptwo(t_stack **seq, char *str);
void	ft_pushelem(t_stack **a, t_stack **b, char *str);
void	ft_rotate(t_stack **seq, char *str);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_re_rotate(t_stack **seq, char *str);
void	ft_count(t_stack **seq, int order);
void	ft_three(t_stack **seq);
void	ft_error(int code);
int		ft_pushswap(t_stack **a, char **argv, int argc);
void	ft_push_to_b(t_stack **seq, t_stack *b, int order);
void	ft_check(t_stack **a, int order);
void	ft_make(char *line, t_stack **a, t_stack **b);
void	sort_b(t_stack **seq, t_stack **b, int size_b, int order);
void	b_rotate(t_stack **seq, t_stack **b);
void	top_to_bottom(t_stack **seq);
int		reverse_upper(t_stack **seq, t_stack **b, int min, int value);
int		reverse_below(t_stack **seq, t_stack **b, int min, int value);
int		straight_below(t_stack **seq, t_stack **b, int min, int value);
int		straight_upper(t_stack **seq, t_stack **b, int min, int value);
int		rev_or_str(t_stack **seq, t_stack **b, int min);
void	a_b_str(t_stack **seq, t_stack **b);
void	a_b_rev(t_stack **seq, t_stack **b);
void	a_rev_b_str(t_stack **seq, t_stack **b);
void	a_str_b_rev(t_stack **seq, t_stack **b);
void	b_null(t_stack **seq, t_stack **b);
int		count_elem(t_stack **seq);

#endif
