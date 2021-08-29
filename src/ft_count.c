#include "../push_swap.h"

static int	first_loop(t_stack **seq, t_stack **b, int order);
static void	second_loop(t_stack **seq, t_stack **b, int order, int cnt);
static int	rev_or_str(t_stack **seq, t_stack **b, int min);
static int	count_elem(t_stack **seq);
static void	sort_b(t_stack **seq, t_stack **b, int size_b);
//static void refresh(t_stack **seq, int value);
static void b_rotate(t_stack **seq, t_stack **b, int count);
static void	top_to_bottom(t_stack **seq);
static int	reverse_upper(t_stack **seq, t_stack **b, int push, int min);
static int	reverse_below(t_stack **seq, t_stack **b, int push, int min);
static int	straight_below(t_stack **seq, t_stack **b, int push, int min);
static int	straight_upper(t_stack **seq, t_stack **b, int push, int min);
void		ft_count(t_stack **seq, int order)
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

static void second_loop(t_stack **seq, t_stack **b, int order, int cnt)
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
				ft_rotate(b, "pb\n");
		}
	}
}

int first_loop(t_stack **seq, t_stack **b, int order)
{
	int count;
	int cnt;

	count = -1;
	cnt = 0;
	while ((*seq)->next && count++ != order)
	{
		if ((*seq)->order > (order + 1) * 0.25 && (*seq)->order <= (order + 1) * 0.75)
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

void ft_push_to_b(t_stack **seq, t_stack *b, int order)
{
	int	count;

	second_loop(seq, &b, order, first_loop(seq, &b, order));
	ft_three(seq);
	count = ++order;
	while (b)
	{
		top_to_bottom(seq);
		top_to_bottom(&b);
		b_rotate(seq, &b, count-- - 3);
	}
	if ((*seq)->order < order / 2)
		while ((*seq)->order != 0)
			ft_re_rotate(seq, "rra\n");
	else
		while ((*seq)->order != 0)
			ft_rotate(seq, "ra\n");
}

static int count_elem(t_stack **seq)
{
	int		elem;
	int		num;

	num = (*seq)->value;
	elem = 0;
	while ((*seq)->next)
	{
		ft_rotate(seq, 0);
		elem++;
		if ((*seq)->value == num)
			break;
	}
	return (elem);
}

static void top_to_bottom(t_stack **seq)
{
	int		count;
	int		num;
	int		order;

	count = 0;
	order = count_elem(seq);
	num = (*seq)->value;
	while ((*seq)->next)
	{
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
			break;
	}
}

static void b_rotate(t_stack **seq, t_stack **b, int count)
{
	int num;
	int elem;

	sort_b(seq, b, count);
	if ((*b)->next == NULL && (*seq)->order > (*b)->order)
	{
		while ((*seq) && (*b)->order < (*seq)->order - 1)
			ft_re_rotate(seq, "rra\n");
	}
	else if ((*b)->next == NULL && (*seq)->order < (*b)->order)
	{
		while ((*seq) && (*b)->order > (*seq)->order)
			ft_rotate(seq, "ra\n");
	}
	else if ((*b) && (*b)->a_reverse == 0 && (*b)->b_reverse == 0)
	{
		num = 0;
		while (num != (*b)->a_rotate && num != (*b)->b_rotate)
		{
			ft_rotate(b, 0);
			ft_rotate(seq, 0);
			ft_putstr_fd("rr\n", 1);
			num += 1;
		}
		while (num < (*b)->a_rotate)
		{
			ft_rotate(seq, "ra\n");
			num++;
		}
		while (num < (*b)->b_rotate)
		{
			ft_rotate(b, "rb\n");
			num++;
		}
	}
	else if (*b && (*b)->a_reverse == 1 && (*b)->b_reverse == 1)
	{
		num = 0;
		while (num != (*b)->a_rotate && num != (*b)->b_rotate)
		{
			ft_re_rotate(b, 0);
			ft_re_rotate(seq, 0);
			ft_putstr_fd("rrr\n", 1);
			num++;
		}
		while (num < (*b)->a_rotate && num >= (*b)->b_rotate)
		{
			ft_re_rotate(seq, "rra\n");
			num++;
		}
		while (num >= (*b)->a_rotate && num < (*b)->b_rotate)
		{
			ft_re_rotate(b, "rrb\n");
			num++;
		}
	}
	else if ((*b) && (*b)->a_reverse == 1 && (*b)->b_reverse == 0)
	{
		num = 0;
		while ((*b)->a_rotate > num)
		{
			ft_re_rotate(seq, "rra\n");
			num++;
		}
		num = 0;
		while ((*b)->b_rotate > num)
		{
			ft_rotate(b, "rb\n");
			num++;
		}
	}
	else if (*b && (*b)->a_reverse == 0 && (*b)->b_reverse == 1)
	{
		num = 0;
		while ((*b)->a_rotate > num)
		{
			ft_rotate(seq, "ra\n");
			num++;
		}
		num = 0;
		while ((*b)->b_rotate > num)
		{
			ft_re_rotate(b, "rrb\n");
			num++;
		}
	}
	ft_pushelem(b, seq, "pa\n");
	elem = (*seq)->value;
	while ((*seq)->next && *b)
	{
		(*seq) = settings(seq);
		ft_rotate(seq, 0);
		if ((*seq)->value == elem)
			break;
	}
	if (*b)
		elem = (*b)->value;
	while (*b)
	{
		*b = settings(b);
		if ((*b)->next)
			ft_rotate(b, 0);
		if ((*b)->value == elem)
			break;
	}
}

static void sort_b(t_stack **seq, t_stack **b, int size_b)
{
	int back_b;
	int min;
	int top;

	back_b = 0;
	min = 0;
	top = (*b)->top;
	while (back_b != size_b && size_b != 1)
	{
		if (min == 0 || (*b)->top < min)
		{
			if ((*b)->order + 1 == (*seq)->order)
			{
				rev_or_str(seq, b, (*b)->top);
				break ;
			}
			min = straight_below(seq, b, top, min);
			min = straight_upper(seq, b, top, min);
			min = reverse_below(seq, b, top, min);
			min = reverse_upper(seq, b, top, min);
		}
		ft_rotate(b, 0);
		back_b++;
	}
	if (back_b > 0 && back_b != size_b && back_b < size_b / 2)
		while (back_b-- > 0)
			ft_re_rotate(b, 0);
	else if (back_b > 0 && back_b != size_b && back_b >= size_b / 2)
		while (size_b != back_b++)
			ft_rotate(b, 0);
}

static int reverse_upper(t_stack **seq, t_stack **b, int push, int min)
{
	int count;
	int value;

	count = 0;
	value = (*seq)->value;
	while ((*seq)->next && (*b)->order >= (*seq)->order + 1 && (count++ +
	push < min || min == 0))
	{
		ft_re_rotate(seq, 0);
		if ((*seq)->loop == 'x' )
		{
			while ((*seq)->next && (*b)->order <= (*seq)->order + 1 &&
			(++count + push < min || min == 0))
			{
				ft_re_rotate(seq, 0);
				if ((*b)->order > (*seq)->order)
				{
					ft_rotate(seq, 0);
					--count;
					break ;
				}
			}
			break ;
		}
	}
	if (count > 0 && (min == 0 || count + push < min))
	{
		min = count + push;
		rev_or_str(seq, b, min);
	}
	while ((*seq)->next && (*seq)->value != value)
		ft_re_rotate(seq, 0);
	return (min);
}

static int reverse_below(t_stack **seq, t_stack **b, int push, int min)
{
	int count;
	int value;

	count = 0;
	value = (*seq)->value;
	while ((*seq)->next && (*b)->order <= (*seq)->order + 1 && (count++ +
	push < min || min == 0))
	{
		ft_re_rotate(seq, 0);
		if ((*b)->order > (*seq)->order)
		{
			ft_rotate(seq, 0);
			break ;
		}
	}
	if (count > 0 && (min == 0 || count + push < min))
	{
		min = count + push;
		rev_or_str(seq, b, min);
	}
	while ((*seq)->next && (*seq)->value != value)
		ft_re_rotate(seq, 0);
	return (min);
}

static int straight_below(t_stack **seq, t_stack **b, int push, int min)
{
	int count;
	int value;

	count = 0;
	value = (*seq)->value;
	while ((*seq)->next && (*b)->order <= (*seq)->order + 1 && (min == 0 ||
	count++ + push < min))
	{
		ft_rotate(seq, 0);
		if ((*seq)->loop == 'x')
		{
			ft_rotate(seq, 0);
			if ((*seq)->next && (*b)->order < (*seq)->order + 1 &&
			(++count + push < min || min == 0))
				break;
			while ((*seq)->next && (*b)->order >= (*seq)->order + 1 &&
			(++count + push < min || min == 0))
				ft_rotate(seq, 0);
			if ((*b)->order > (*seq)->order &&
				(++count + push < min || min == 0))
			{
				ft_re_rotate(seq, 0);
				--count;
			}
			break ;
		}
	}
	if (count > 0 && (min == 0 || count + push < min))
	{
		min = count + push;
		rev_or_str(seq, b, min);
	}
	while ((*seq)->next && (*seq)->value != value)
		ft_re_rotate(seq, 0);
	return (min);
}

static int straight_upper(t_stack **seq, t_stack **b, int push, int min)
{
	int count;
	int value;

	count = 0;
	value = (*seq)->value;
	while ((*seq)->next && (*b)->order >= (*seq)->order + 1 && (count++ +
	push < min || min == 0))
		ft_rotate(seq, 0);
	if (count > 0 && (min == 0 || count + push < min))
	{
		min = count + push;
		rev_or_str(seq, b, min);
	}
	while ((*seq)->next && (*seq)->value != value)
		ft_re_rotate(seq, 0);
	return (min);
}

//static void refresh(t_stack **seq, int value)
//{
//	while ((*seq)->next && (*seq)->value != value)
//		ft_re_rotate(seq, 0);
//}

static int rev_or_str(t_stack **seq, t_stack **b, int min)
{
	int		num;
	int 	top;
	int 	reverse;

	num = (*b)->value;
	reverse = (*b)->reverse;
	top = (*b)->top;
	while ((*b)->next)
	{
		(*b)->b_rotate = top;
		(*b)->a_rotate = (*seq)->top;
		(*b)->a_reverse = (*seq)->reverse;
		(*b)->b_reverse = reverse;
		ft_rotate(b, 0);
		if ((*b)->value == num)
			break ;
	}
	return (min);
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
