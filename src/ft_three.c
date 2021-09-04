#include "../push_swap.h"

void	ft_three(t_stack **seq)
{
	if ((*seq)->order < (*seq)->next->order
		&& (*seq)->next->order > (*seq)->next->next->order
		&& (*seq)->order < (*seq)->next->next->order)
	{
		ft_swaptwo(seq, "sa\n");
		ft_rotate(seq, "ra\n");
	}
	else if ((*seq)->order > (*seq)->next->order
		&& (*seq)->order < (*seq)->next->next->order)
		ft_swaptwo(seq, "sa\n");
	else if ((*seq)->order < (*seq)->next->order
		&& (*seq)->order > (*seq)->next->next->order)
		ft_re_rotate(seq, "rra\n");
	else if ((*seq)->order > (*seq)->next->order
		&& (*seq)->next->order < (*seq)->next->next->order)
		ft_rotate(seq, "ra\n");
	else if ((*seq)->order > (*seq)->next->order
		&& (*seq)->next->order > (*seq)->next->next->order)
	{
		ft_swaptwo(seq, "sa\n");
		ft_re_rotate(seq, "rra\n");
	}
}
