#include "../push_swap.h"

void ft_pushelem(t_stack **a, t_stack **b, char *str)
{
	t_stack *temp;

	if (!*a)
		return ;
	temp = *a;
	*a = temp->next;
	temp->next = NULL;
	if (*b == NULL)
		*b = temp;
	else
		ft_lstadd_front(b, temp);
	if (str)
		ft_putstr_fd(str, 1);
}
