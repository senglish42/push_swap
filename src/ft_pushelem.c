#include "../push_swap.h"

t_stack *ft_pushelem(t_stack **a, t_stack **b, char *str)
{
	t_stack *temp1;
	t_stack temp2;

	if (!*a)
		return (NULL);
	temp1 = *a;
	temp2.value = temp1->value;
	temp2.order = temp1->order;
	temp2.flag = temp1->flag;
	temp2.next = NULL;
	if (*b == NULL)
	{
		*b = &temp2;
		*a = temp1->next;
	}
	else
	{
		temp1 = *b;
		temp2.next = temp1;
		*b = &temp2;
	}
	if (str)
		ft_putstr_fd(str, 1);
	return (*b);
}

