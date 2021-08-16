#include "../push_swap.h"

void	ft_count(t_stack **seq, int order)
{
	t_stack *temp;
	int count;

	temp = *seq;
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
	else if (order == 4)
		ft_four(seq, --order);
	else if (order == 5)
		ft_five(seq, --order);
}

void ft_three(t_stack **seq)
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

void ft_four(t_stack **seq, int order)
{
	t_stack *b;

	b = NULL;
	if ((*seq)->next->next->next->order == order)
		ft_re_rotate(seq, "rra\n");
	ft_pushelem(seq, &b, "pb\n");
	ft_three(seq);
	ft_pushelem(&b, seq, "pa\n");
	if ((*seq)->order > (*seq)->next->order)
		ft_fourtofive(seq);
}

void ft_five(t_stack **seq, int order)
{
	t_stack *b;

	b = NULL;
	if ((*seq)->next->next->next->next->order == order || (*seq)->next->next->next->next->order == 0)
		ft_re_rotate(seq, "rra\n");
	while ((*seq)->next && (*seq)->order != order && (*seq)->order != 0)
		ft_rotate(seq, "ra\n");
	ft_pushelem(seq, &b, "pb\n");
	ft_four(seq, order);
	ft_pushelem(&b, seq, "pa\n");
	if ((*seq)->order < (*seq)->next->order)
		return ;
	else if ((*seq)->order > (*seq)->next->next->next->next->order)
		ft_rotate(seq, "ra\n");
	else if ((*seq)->order > (*seq)->next->next->next->order)
		ft_prelast(seq);
	else if ((*seq)->order > (*seq)->next->next->order)
	{
		ft_swaptwo(seq, "sa\n");
		ft_pushelem(seq, &b, "pb\n");
		ft_swaptwo(seq, "sa\n");
		ft_pushelem(&b, seq, "pa\n");
	}
	else if ((*seq)->order > (*seq)->next->order)
		ft_swaptwo(seq, "sa\n");
}

void ft_fourtofive(t_stack **seq)
{
	if ((*seq)->order > (*seq)->next->next->next->order)
		ft_rotate(seq, "ra\n");
	else if ((*seq)->order > (*seq)->next->next->order)
		ft_prelast(seq);
	else
		ft_swaptwo(seq, "sa\n");
}

void ft_prelast(t_stack **seq)
{
	ft_re_rotate(seq, "rra\n");
	ft_swaptwo(seq, "sa\n");
	ft_rotate(seq, "ra\n");
	ft_rotate(seq, "ra\n");
}

