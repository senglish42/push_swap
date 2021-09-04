#include "../push_swap.h"

int	rev_or_str(t_stack **seq, t_stack **b, int min)
{
	int	num;
	int	top;
	int	reverse;

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
