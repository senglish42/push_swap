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

static int a_smaller_b(t_stack **seq, t_stack **b, int push, int min)
{
	int elem;
	int count;
	int value;

	count = 0;
	value = (*seq)->value;
	while ((*seq)->next)
	{
		ft_rotate(seq, 0);
		elem = push + count++;
		if ((*b)->order < (*seq)->order)
			break ;
	}
	if (elem < min || min == 0)
	{
		(*b)->b_rotate = elem;
		min = rev_or_str(seq, b, elem);
	}
	while ((*seq)->value != value)
		ft_re_rotate(seq, 0);
	count = 0;
	while ((*seq)->next)
	{
		ft_re_rotate(seq, 0);
		elem = push + count++;
		if (elem > min)
			break ;
		if ((*seq)->loop == 'x')
		{
			if ((*b)->order + 1 == (*seq)->order)
				break ;
			ft_re_rotate(seq, 0);
			if ((*b)->order < (*seq)->order)
				elem = push + count++;
			else
			{
				ft_rotate(seq, 0);
				break;
			}
		}
		while ((*b)->order < (*seq)->order)
		{
			ft_re_rotate(seq, 0);
			break;
		}
	}
	if (elem < min)
	{
		(*b)->b_rotate = elem;
		min = rev_or_str(seq, b, elem);
	}
	while ((*seq)->value != value)
		ft_re_rotate(seq, 0);
	return (min);
}
