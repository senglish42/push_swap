#include "../push_swap.h"

static int	sort_b(t_stack **seq, t_stack **b, int size_b);
static void ft_fresh(t_stack **b);
static void b_rotate(t_stack **seq, t_stack **b, int count);
static void top_to_bottom(t_stack **seq);
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
//	else if (order == 4)
//		ft_four(seq, --order);
//	else if (order == 5)
//		ft_five(seq, --order);
	else
		ft_push_to_b(seq, b, --order);
}

void ft_push_to_b(t_stack **seq, t_stack *b, int order)
{
	t_stack *temp;
	int count;

	count = 0;
	temp = *seq;
	*seq = temp->next;
	while (temp->next && count != order - 2)
	{
		if (temp->order != 0 && temp->order != order / 2 && temp->order != order)
		{
			ft_pushelem(&temp, &b, "pb\n");
			b = settings(&b);
			count++;
		}
		else
			ft_rotate(&temp, "ra\n");
	}
	if (!(temp->order < temp->next->order && temp->order > temp->next->next->order))
	{
		ft_three(&temp);
		ft_rotate(&temp, "sa\n");
	}
	while (b)
	{
		top_to_bottom(&temp);
		top_to_bottom(&b);
		b_rotate(&temp, &b, count--);
	}
	top_to_bottom(&temp);
	ft_re_rotate(&temp, "rra\n");
}

static void top_to_bottom(t_stack **seq)
{
	t_stack	*temp;
	int		count;
	int		num;

	count = 0;
	temp = *seq;
	*seq = temp->next;
	num = temp->value;
	while (temp->next)
	{
		temp->top = count++;
		ft_rotate(&temp, 0);
		if (temp->value == num)
			break;
	}
	*seq = temp;
}

//static void b_rotate(t_stack **seq, t_stack **b, int count)
//{
//	int min;
//	t_stack *temp_a;
//	t_stack *temp_b;
//
//	temp_a = *seq;
//	*seq = temp_a->next;
//	temp_b = *b;
//	*b = temp_b->next;
//	min = sort_b(&temp_a, &temp_b, count);
//	while (temp_b->next && temp_b->b_rotate != min && min > 0)
//		ft_rotate(&temp_b, "rb\n");
//	while (temp_b->next && temp_b->b_rotate != min && min < 0)
//		ft_re_rotate(&temp_b, "rrb\n");
//	if (min < 0)
//		min = -min;
//	ft_push_to_a(&temp_a, &temp_b);
//	*seq = temp_a;
//	*b = temp_b;
//}

//void ft_push_to_a(t_stack **seq, t_stack **b)
//{
//	t_stack *temp_a;
//	t_stack *temp_b;
//	int clean_b_top;
//	int back_a;
//
//	temp_a = *seq;
//	*seq = temp_a->next;
//	temp_b = *b;
//	*b = temp_b->next;
//	ft_pushelem(&temp_b, &temp_a, "pa\n");
//	clean_b_top = temp_a->b_top;
//	temp_a->b_top = 0;
//	back_a = 0;
//	while (temp_a->next && temp_a->order > temp_a->next->order)
//	{
//		back_a++;
//		ft_swaptwo(&temp_a, "sa\n");
//		ft_rotate(&temp_a, "ra\n");
//	}
//	while (back_a--)
//		ft_re_rotate(&temp_a, "rra\n");
//	ft_fresh(&temp_b, clean_b_top);
//	*seq = temp_a;
//	*b = temp_b;
//}

static void b_rotate(t_stack **seq, t_stack **b, int count)
{
	int min;
	t_stack *temp_a;
	t_stack *temp_b;

	temp_a = *seq;
	*seq = temp_a->next;
	temp_b = *b;
	*b = temp_b->next;
	min = sort_b(&temp_a, &temp_b, count);
	while (temp_b->next && temp_b->b_rotate != min && min > 0)
		ft_rotate(&temp_b, "rb\n");
	while (temp_b->next && temp_b->b_rotate != min && min < 0)
		ft_re_rotate(&temp_b, "rrb\n");
	if (min < 0)
		min = -min;
//	if (min == 1)
//		ft_pushelem(&temp_a, &temp_b, "pa\n");
	ft_push_to_a(&temp_a, &temp_b);
	*seq = temp_a;
	*b = temp_b;
}

void ft_push_to_a(t_stack **seq, t_stack **b)
{
	t_stack *temp_a;
	t_stack *temp_b;
	int back_a;

	temp_a = *seq;
	*seq = temp_a->next;
	temp_b = *b;
	*b = temp_b->next;
	ft_pushelem(&temp_b, &temp_a, "pa\n");
	temp_a->top = 0;
	back_a = 0;
	while (temp_a->next && temp_a->order > temp_a->next->order)
	{
		back_a++;
		ft_swaptwo(&temp_a, "sa\n");
		ft_rotate(&temp_a, "ra\n");
	}
	while (back_a--)
		ft_re_rotate(&temp_a, "rra\n");
	ft_fresh(&temp_b);
	*seq = temp_a;
	*b = temp_b;
}

static int sort_b(t_stack **seq, t_stack **b, int size_b)
{
	t_stack *temp_b;
	t_stack *temp_a;
	int count;
	int back_b;
	int min;
	int push;
	int straight;
	int reverse;

	temp_b = *b;
	temp_a = *seq;
	*b = temp_b->next;
	*seq = temp_a->next;
	back_b = 0;
	min = 0;
	while (back_b != size_b)
	{
		count = 0;
		straight = 0;
		reverse = 0;
		if (temp_b->top >= (size_b + 1)/ 2)
		{
			push = size_b - temp_b->top;
			temp_b->b_reverse = 1;
		}
		else
			push = temp_b->top;
		if (temp_b->b_rotate == 0)
		{
			if (temp_b->order < temp_a->order)
			{
				while (temp_a->next && temp_b->order < temp_a->order)
				{
					temp_b->b_rotate = push + (count++ * 2) + 1;
					ft_re_rotate(&temp_a, 0);
				}
				reverse = temp_b->b_rotate;
				while (count-- > 0)
					ft_rotate(&temp_a, 0);
				count = 0;
				while (temp_a->next)
				{
					temp_b->b_rotate = push + ++count + 1;
					ft_rotate(&temp_a, 0);
					if (temp_b->order > temp_a->order && temp_b->order < temp_a->next->order)
						break;
				}
				straight = temp_b->b_rotate;
				while (count-- > 0)
					ft_re_rotate(&temp_a, 0);
			}
			else if (temp_b->order > temp_a->order)
			{
				count = 0;
				while (temp_a->next && temp_b->order > temp_a->order)
				{
					temp_b->b_rotate = push + ++count + 1;
					ft_rotate(&temp_a, 0);
				}
				straight = temp_b->b_rotate;
				while (count-- > 0)
					ft_re_rotate(&temp_a, 0);
				count = 0;
				while (temp_a->next)
				{
					temp_b->b_rotate = push + (count++ * 2) + 1;
					ft_re_rotate(&temp_a, 0);
					if (temp_b->order < temp_a->order && temp_b->order > temp_a->next->order)
						break;
				}
				reverse = temp_b->b_rotate;
				while (count-- > 0)
					ft_rotate(&temp_a, 0);
			}
				if (straight <= reverse)
					temp_b->b_rotate = straight;
				if (reverse < straight)
				{
					temp_b->b_rotate = reverse;
					if (reverse > 1) //maybe temporary
						temp_b->a_reverse = 1;
				}
			if (min == 0 || temp_b->b_rotate < min)
				min = temp_b->b_rotate;
		}
		else
			break ;
		if (size_b == 1)
			break ;
		ft_rotate(&temp_b, 0);
		back_b++;
	}
	while (back_b--)
	{
		if (temp_b->b_rotate == min && temp_b->top > size_b / 2)
		{
			min = -min;
			temp_b->top = min;
		}
		ft_re_rotate(&temp_b, 0);
	}
	*seq = temp_a;
	*b = temp_b;
	return (min);
}

static void ft_fresh(t_stack **b)
{
	t_stack *temp;

	if (!*b)
		return ;
	temp = *b;
	*b = temp->next;
	while (temp && temp->b_rotate != 0)
	{
		temp->b_rotate = 0;
		if (temp->next != NULL)
			ft_rotate(&temp, 0);
	}
	*b = temp;
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
