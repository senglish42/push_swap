#include "../push_swap.h"

static int check_min(t_stack **seq, t_stack **b, int count, int min, int order, int size_b, int value)
{
	if (count > 0 && (min == 0 || count < min))
	{
		min = count;
		rev_or_str(seq, b, count);
	}
	if ((*seq)->value != value)
	{
		if (count >= order - size_b / 2)
			while ((*seq)->next && (*seq)->value != value)
				ft_re_rotate(seq, 0);
		else
			while ((*seq)->next && (*seq)->value != value)
				ft_rotate(seq, 0);
	}
	return (min);
}

int reverse_upper(t_stack **seq, t_stack **b, int min, int size_b, int order)
{
	int count;
	int value;

	count = 0;
	value = (*seq)->value;
	while ((*seq)->next && (*b)->order >= (*seq)->order + 1 && (count++ < min || min == 0))
	{
		ft_re_rotate(seq, 0);
		if ((*seq)->loop == 'x' )
			while ((*seq)->next && (*b)->order <= (*seq)->order + 1 && (++count < min || min == 0))
			{
				ft_re_rotate(seq, 0);
				if ((*b)->order > (*seq)->order && --count)
				{
					ft_rotate(seq, 0);
					break ;
				}
			}
	}
	return (check_min(seq, b, count, min, order, size_b, value));
}

int reverse_below(t_stack **seq, t_stack **b, int min, int size_b, int order)
{
	int count;
	int value;

	count = 0;
	value = (*seq)->value;
	while ((*seq)->next && (*b)->order <= (*seq)->order + 1 && (count++ < min || min == 0))
	{
		ft_re_rotate(seq, 0);
		if ((*b)->order > (*seq)->order)
		{
			ft_rotate(seq, 0);
			break ;
		}
	}
	return (check_min(seq, b, count, min, order, size_b, value));
}

int straight_below(t_stack **seq, t_stack **b, int min, int size_b, int order)
{
	int count;
	int value;

	count = 0;
	value = (*seq)->value;
	while ((*seq)->next && (*b)->order <= (*seq)->order + 1 && (count++ < min || min == 0))
	{
		ft_rotate(seq, 0);
		if ((*seq)->loop == 'x')
		{
			ft_rotate(seq, 0);
			while ((*seq)->next && (*b)->order >= (*seq)->order + 1 && (++count < min || min == 0))
				ft_rotate(seq, 0);
			if ((*b)->order > (*seq)->order && (++count < min || min == 0) && --count)
				ft_re_rotate(seq, 0);
			break ;
		}
	}
	return (check_min(seq, b, count, min, order, size_b, value));
}

int straight_upper(t_stack **seq, t_stack **b, int min, int size_b, int order)
{
	int count;
	int value;

	count = 0;
	value = (*seq)->value;
	while ((*seq)->next && (*b)->order >= (*seq)->order + 1 && (count++ < min || min == 0))
		ft_rotate(seq, 0);
	return (check_min(seq, b, count, min, order, size_b, value));
}

