#include "../push_swap.h"

t_stack *ft_pushelem(t_stack **a, t_stack **b, char *str)
{
	t_stack *temp;

	if (!*a)
		return (NULL);
	if (*b == NULL)
	{
		temp = *a;
		*a = temp->next;
		temp->next = NULL;
		*b = temp;
	}
	else
		ft_lstadd_front(b, *a);
	if (str)
		ft_putstr_fd(str, 1);
	return (*b);
}

