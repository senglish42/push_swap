#include "../push_swap.h"
#include "stdio.h"

void	ft_swaptwo(t_stack **seq, char *str)
{
	t_stack	*temp1;
	t_stack *temp2;

	if (!*seq)
		return ;
	temp1 = *seq;
	temp2 = temp1->next;
	temp1->next = temp2->next;
	temp2->next = temp1;
	*seq = temp2;
	if (str)
		ft_putstr_fd(str, 1);
}