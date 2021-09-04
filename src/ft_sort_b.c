#include "../push_swap.h"

int	count_elem(t_stack **seq)
{
	int	elem;
	int	num;

	num = (*seq)->value;
	elem = 0;
	while ((*seq)->next)
	{
		ft_rotate(seq, 0);
		elem++;
		if ((*seq)->value == num)
			break ;
	}
	return (elem);
}

void	top_to_bottom(t_stack **seq)
{
	int	count;
	int	num;
	int	order;

	count = 0;
	order = count_elem(seq);
	num = (*seq)->value;
	while ((*seq)->next)
	{
		*seq = settings(seq);
		if (count == 1 && order == 2)
			(*seq)->reverse = 1;
		if (count <= order / 2)
			(*seq)->top = count++;
		else if (count > order / 2)
		{
			(*seq)->top = order - count++;
			(*seq)->reverse = 1;
		}
		ft_rotate(seq, 0);
		if ((*seq)->value == num)
			break ;
	}
}

void	b_rotate(t_stack **seq, t_stack **b)
{
	if ((*b)->next == NULL)
		b_null(seq, b);
	else if ((*b) && (*b)->a_reverse == 0 && (*b)->b_reverse == 0)
		a_b_str(seq, b);
	else if (*b && (*b)->a_reverse == 1 && (*b)->b_reverse == 1)
		a_b_rev(seq, b);
	else if ((*b) && (*b)->a_reverse == 1 && (*b)->b_reverse == 0)
		a_rev_b_str(seq, b);
	else if (*b && (*b)->a_reverse == 0 && (*b)->b_reverse == 1)
		a_str_b_rev(seq, b);
	ft_pushelem(b, seq, "pa\n");
}

static int	b_turns(t_stack **seq, t_stack **b, int size_b)
{
	int	min;
	int	back_b;
	int	value;

	min = 0;
	back_b = -1;
	while (++back_b != size_b && size_b != 1)
	{
		value = (*seq)->value;
		if ((min == 0 || (*b)->top < min) && (*b)->order > (*seq)->order)
		{
			min = straight_upper(seq, b, min, value);
			min = reverse_upper(seq, b, min, value);
		}
		else if ((min == 0 || (*b)->top < min) && (*b)->order < (*seq)->order)
		{
			min = straight_below(seq, b, min, value);
			min = reverse_below(seq, b, min, value);
		}
		ft_rotate(b, 0);
	}
	return (back_b);
}

void	sort_b(t_stack **seq, t_stack **b, int size_b, int order)
{
	int	back_b;
	int	last;

	ft_re_rotate(seq, 0);
	last = (*seq)->order;
	ft_rotate(seq, 0);
	if ((*b)->order + 1 == (*seq)->order || (((*b)->order > last
				|| last == order - 1) && (*b)->order < (*seq)->order))
	{
		rev_or_str(seq, b, (*b)->top);
		return ;
	}
	back_b = b_turns(seq, b, size_b);
	if (back_b > 0 && back_b != size_b && back_b < size_b / 2)
		while (back_b-- > 0)
			ft_re_rotate(b, 0);
	else if (back_b > 0 && back_b != size_b && back_b >= size_b / 2)
		while (size_b != back_b++)
			ft_rotate(b, 0);
}
