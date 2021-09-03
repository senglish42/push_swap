#include "../push_swap.h"

void ft_check(t_stack **a, int order)
{
	int count;
	int value;

	count = 0;
	value = (*a)->value;
	while ((*a)->next && count < order && (count == 0 || (*a)->value != value))
	{
		if (((*a)->order < (*a)->next->order || (*a)->order + 1 == order) && ++count)
			ft_rotate(a, 0);
		else
		{
			ft_putstr_fd("KO", 1);
			return ;
		}
	}
	if (count == order || order == 1)
		ft_putstr_fd("OK", 1);
	else
		ft_putstr_fd("KO", 1);
}
