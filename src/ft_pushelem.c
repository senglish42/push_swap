#include "../push_swap.h"

t_stack *ft_pushelem(t_stack **a, t_stack **b)
{
	t_stack *temp1;

	if (!*a)
		return (NULL);
	temp1 = *a;
	temp1->next = NULL;
	*b = temp1;
	return (*b);
}

