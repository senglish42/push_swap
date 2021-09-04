#include "../push_swap.h"

static void	second_loop(t_stack **seq, t_stack **b, int order, int cnt)
{
	int count;

	count = -1;
	while ((*seq)->next && count++ != order - cnt)
	{
		if ((*seq)->loop == 'x')
		{
			if ((*seq)->order != order)
				(*seq)->loop = 'o';
			ft_rotate(seq, "ra\n");
		}
		else if ((*seq)->order <= (order + 1) * 0.25 || (*seq)->order > (order + 1) * 0.75)
		{
			ft_pushelem(seq, b, "pb\n");
			*b = settings(b);
			if ((*b)->next && (*b)->order >= order * 0.75)
				ft_rotate(b, "rb\n");
		}
	}
}

static int	first_loop(t_stack **seq, t_stack **b, int order)
{
	int count;
	int cnt;

	count = -1;
	cnt = 0;
	while ((*seq)->next && count++ != order)
	{
		if ((*seq)->order > (order + 1) * 0.25 && (*seq)->order <= (order + 1) * 0.75 && (*seq)->order < order - 2)
		{
			ft_pushelem(seq, b, "pb\n");
			*b = settings(b);
			if ((*b)->next && (*b)->order >= order * 0.5)
				ft_rotate(b, "rb\n");
			cnt++;
		}
		else
		{
			if ((*seq)->order == order || (*seq)->order == order - 1 || (*seq)->order == order - 2)
				(*seq)->loop = 'x';
			ft_rotate(seq, "ra\n");
		}
	}
	return (cnt);
}

void	ft_push_to_b(t_stack **seq, t_stack *b, int order)
{
	int	count;

	second_loop(seq, &b, order, first_loop(seq, &b, order));
	ft_three(seq);
	count = ++order;
	while (b)
	{
		top_to_bottom(seq);
		top_to_bottom(&b);
		sort_b(seq, &b, count-- - 3, order);
		b_rotate(seq, &b);
	}
	if ((*seq)->order < order / 2)
		while ((*seq)->order != 0)
			ft_re_rotate(seq, "rra\n");
	else
		while ((*seq)->order != 0)
			ft_rotate(seq, "ra\n");
}

void	ft_count(t_stack **seq, int order)
{
	t_stack *temp;
	t_stack *b;
	int count;

	temp = *seq;
	b = NULL;
	count = 0;
	while (temp->next)
	{
		if (temp->order < temp->next->order)
			count += 1;
		temp = temp->next;
	}
	if (++count == order)
		return ;
	if (order == 2 && ((*seq)->order > (*seq)->next->order))
		ft_swaptwo(seq,"sa\n");
	else if (order == 3)
		ft_three(seq);
	else
		ft_push_to_b(seq, b, --order);
}

void	ft_three(t_stack **seq)
{
	if ((*seq)->order < (*seq)->next->order && (*seq)->next->order > (*seq)->next->next->order
	&& (*seq)->order < (*seq)->next->next->order) //021
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
