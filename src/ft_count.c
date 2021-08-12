#include "../push_swap.h"

void	ft_count(t_stack **seq, int order)
{
	if (order == 2 && ((*seq)->order == 1 && (*seq)->next->order == 0))
		ft_swaptwo(seq,"sa\n");
	else if (order == 3)
		ft_three(seq);
	else if (order <= 5)
		ft_five(seq, order);
}

//void ft_three(t_stack **seq)
//{
//	if ((*seq)->order == 0 && (*seq)->next->order == 2 && (*seq)->next->next->order == 1)
//	{
//		ft_swaptwo(seq, "sa\n");
//		ft_rotate(seq, "ra\n");
//	}
//	else if ((*seq)->order == 1 && (*seq)->next->order == 0 && (*seq)->next->next->order == 2)
//		ft_swaptwo(seq, "sa\n");
//	else if ((*seq)->order == 1 && (*seq)->next->order == 2 && (*seq)->next->next->order == 0)
//		ft_re_rotate(seq, "rra\n");
//	else if ((*seq)->order == 2 && (*seq)->next->order == 0 && (*seq)->next->next->order == 1)
//		ft_rotate(seq, "ra\n");
//	else if ((*seq)->order == 2 && (*seq)->next->order == 1 && (*seq)->next->next->order == 0)
//	{
//		ft_swaptwo(seq, "sa\n");
//		ft_re_rotate(seq, "rra\n");
//	}
//}
void ft_three(t_stack **seq)
{
	if ((*seq)->order < (*seq)->next->order && (*seq)->next->order > (*seq)->next->next->order
		&& (*seq)->next->order && (*seq)->next->next->order)
	{
		ft_swaptwo(seq, "sa\n");
		ft_rotate(seq, "ra\n");
	}
	else if ((*seq)->order > (*seq)->next->order && (*seq)->order < (*seq)->next->next->order) //102
		ft_swaptwo(seq, "sa\n");
	else if ((*seq)->order < (*seq)->next->order && (*seq)->order > (*seq)->next->next->order) //120
		ft_re_rotate(seq, "rra\n");
	else if ((*seq)->order > (*seq)->next->order && (*seq)->next->order < (*seq)->next->next->order) //201
		ft_rotate(seq, "ra\n");
	else if ((*seq)->order > (*seq)->next->order && (*seq)->next->order > (*seq)->next->next->order) //210
	{
		ft_swaptwo(seq, "sa\n");
		ft_re_rotate(seq, "rra\n");
	}
}

void ft_five(t_stack **seq, int order)
{
	t_stack *b;

	b = NULL;
	if (order == 4)
	{
		ft_pushelem(seq, &b, "pb\n");
		ft_three(seq);
		b = ft_pushelem(&b, seq, "pa\n");
		if ((*seq)->order > (*seq)->next->order && b->order > (*seq)->next->next->order
			&& b->order > (*seq)->next->next->next->order)
			ft_rotate(seq, "ra\n");
		else if ((*seq)->order > (*seq)->next->order && b->order > (*seq)->next->next->order
		&& b->order < (*seq)->next->next->next->order)
		{
			ft_re_rotate(seq, "rra\n");
			ft_swaptwo(seq, "sa\n");
			ft_rotate(seq, "ra\n");
			ft_rotate(seq, "ra\n");
		}
		else if ((*seq)->order > (*seq)->next->order && b->order < (*seq)->next->next->order
		&& b->order < (*seq)->next->next->next->order)
			ft_swaptwo(seq, "sa\n");
	}
}



