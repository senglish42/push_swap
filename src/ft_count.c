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
	else
		ft_sort(seq, --order);
}

void ft_sort(t_stack **seq, int order)
{
	t_stack *b;
	t_stack *temp;
	int group;
	int count;
	int elem;
	int class;
	int max;
	int num;
	int middle;

	b = NULL;
	temp = *seq;
	count = 0;
	class = 4;
	max = 0;
	num = (order + 1) / class;
	while (temp->next && count != class)
	{
		group = ++count * (order + 1) / class;
		num = group - num;
		elem = num;
		while (temp->next && elem)
		{
			if (temp->order < group)
			{
				ft_pushelem(&temp, &b, "pb\n");
				if (b->order > max)
					max = b->order;
				elem--;
			}
			else
				ft_rotate(&temp, "ra\n");
			if (b && b->next && b->order < b->next->order)
			{
				while (b->order != max)
				{
					ft_re_rotate(&b, "rb\n");
					if (b->order != max && b->order < b->next->order)
						ft_swaptwo(&b, "sb\n");
				}
			}
		}
		if (group == (order + 1) / 2)
			break ;
	}
	*seq = temp;
	count = order;
	if (order % 2 == 0)
		middle = order - group;
	else
		middle = order - group + 1;
	while (*seq && (*seq)->order != count)
	{
		ft_re_rotate(seq, "rra\n");
		if ((*seq)->order == count)
		{
			ft_re_rotate(seq, "rra\n");
			while ((*seq)->order)
			{
				while ((*seq)->order > (*seq)->next->order)
				{
					ft_swaptwo(seq, "sa\n");
					ft_rotate(seq, "ra\n");
				}
				if ((*seq)->order < (*seq)->next->order)
				{
					if ((*seq)->order == middle && ft_well_ordered(seq, middle))
						break ;
					ft_re_rotate(seq, "rra\n");
				}
			}
			break ;
		}
	}
	while (b)
		ft_pushelem(&b, seq, "pa\n");
}

int	ft_well_ordered(t_stack **seq, int middle)
{
	t_stack *temp;
	int		count;

	temp = *seq;
	count = middle;
	while (temp && temp->next)
	{
		if (temp->order != count)
			return (0);
		count++;
		temp = temp->next;
	}
	return (1);
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

