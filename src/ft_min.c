#include "../push_swap.h"

static void	check_min(t_stack **seq, int count, int value)
{
	int	size_a;

	size_a = count_elem(seq);
	if ((*seq)->value != value)
	{
		if (count >= size_a / 2)
			while ((*seq)->next && (*seq)->value != value)
				ft_re_rotate(seq, 0);
		else
			while ((*seq)->next && (*seq)->value != value)
				ft_rotate(seq, 0);
	}
}

int	reverse_upper(t_stack **seq, t_stack **b, int min, int value)
{
	int	count;

	count = 0;
	while ((*b)->order >= (*seq)->order + 1 && (count++ < min || min == 0))
	{
		ft_re_rotate(seq, 0);
		while ((*seq)->loop == 'x' || ((*b)->order <= (*seq)->order + 1
				&& (++count < min || min == 0)))
		{
			ft_re_rotate(seq, 0);
			if ((*b)->order > (*seq)->order && --count)
			{
				ft_rotate(seq, 0);
				break ;
			}
		}
	}
	if (count > 0 && (min == 0 || count < min))
	{
		min = count;
		rev_or_str(seq, b, count);
	}
	check_min(seq, count, value);
	return (min);
}

int	reverse_below(t_stack **seq, t_stack **b, int min, int value)
{
	int	count;

	count = 0;
	while ((*b)->order <= (*seq)->order + 1 && (count++ < min || min == 0))
	{
		ft_re_rotate(seq, 0);
		if ((*b)->order > (*seq)->order)
		{
			ft_rotate(seq, 0);
			break ;
		}
	}
	if (count > 0 && (min == 0 || count < min))
	{
		min = count;
		rev_or_str(seq, b, count);
	}
	check_min(seq, count, value);
	return (min);
}

int	straight_below(t_stack **seq, t_stack **b, int min, int value)
{
	int	count;

	count = 0;
	while ((*b)->order <= (*seq)->order + 1 && (count++ < min || min == 0))
	{
		ft_rotate(seq, 0);
		if ((*seq)->loop == 'x')
		{
			ft_rotate(seq, 0);
			while ((*seq)->next && (*b)->order >= (*seq)->order + 1
				&& (++count < min || min == 0))
				ft_rotate(seq, 0);
			if ((*b)->order > (*seq)->order
				&& (++count < min || min == 0) && --count)
				ft_re_rotate(seq, 0);
			break ;
		}
	}
	if (count > 0 && (min == 0 || count < min))
	{
		min = count;
		rev_or_str(seq, b, count);
	}
	check_min(seq, count, value);
	return (min);
}

int	straight_upper(t_stack **seq, t_stack **b, int min, int value)
{
	int	count;

	count = 0;
	while ((*b)->order >= (*seq)->order + 1 && (count++ < min || min == 0))
		ft_rotate(seq, 0);
	if (count > 0 && (min == 0 || count < min))
	{
		min = count;
		rev_or_str(seq, b, count);
	}
	check_min(seq, count, value);
	return (min);
}
