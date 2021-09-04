#include "../push_swap.h"

void b_null(t_stack **seq, t_stack **b)
{
	if ((*seq)->order > (*b)->order)
	{
		while ((*seq) && (*b)->order < (*seq)->order - 1)
			ft_re_rotate(seq, "rra\n");
	}
	else if ((*seq)->order < (*b)->order)
	{
		while ((*seq) && (*b)->order > (*seq)->order)
			ft_rotate(seq, "ra\n");
	}
}

void a_b_str(t_stack **seq, t_stack **b)
{
	int num;

	num = -1;
	if ((*b)->b_rotate == 1 && ((*seq)->a_rotate == 1 && ++num))
	{
		ft_swaptwo(seq, 0);
		ft_swaptwo(b, 0);
		ft_putstr_fd("ss\n", 1);
	}
	while (++num != (*b)->a_rotate && num != (*b)->b_rotate)
	{
		ft_rotate(b, 0);
		ft_rotate(seq, 0);
		ft_putstr_fd("rr\n", 1);
	}
	while (num < (*b)->a_rotate && ++num)
		ft_rotate(seq, "ra\n");
	while (num < (*b)->b_rotate && ++num)
		ft_rotate(b, "rb\n");
}

void a_b_rev(t_stack **seq, t_stack **b)
{
	int num;

	num = -1;
	while (++num != (*b)->a_rotate && num != (*b)->b_rotate)
	{
		ft_re_rotate(b, 0);
		ft_re_rotate(seq, 0);
		ft_putstr_fd("rrr\n", 1);
	}
	while (num < (*b)->a_rotate && num >= (*b)->b_rotate && ++num)
		ft_re_rotate(seq, "rra\n");
	while (num >= (*b)->a_rotate && num < (*b)->b_rotate && ++num)
		ft_re_rotate(b, "rrb\n");
}

void a_rev_b_str(t_stack **seq, t_stack **b)
{
	int num;

	num = 0;
	while ((*b)->a_rotate > num && ++num)
		ft_re_rotate(seq, "rra\n");
	num = 0;
	while ((*b)->b_rotate > num && ++num)
		ft_rotate(b, "rb\n");
}

void a_str_b_rev(t_stack **seq, t_stack **b)
{
	int num;

	num = 0;
	while ((*b)->a_rotate > num && ++num)
		ft_rotate(seq, "ra\n");
	num = 0;
	while ((*b)->b_rotate > num && ++num)
		ft_re_rotate(b, "rrb\n");
}
