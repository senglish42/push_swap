#include "../push_swap.h"

t_stack *ft_rotate(t_stack **seq, char *str)
{
	t_stack *temp1;
	t_stack *temp2;

	if (!*seq)
		return (NULL);
	temp1 = *seq;
	temp1 = temp1->next;
	temp2 = *seq;
	temp2->next = NULL;
	*seq = temp1;
	ft_lstadd_back(seq, temp2);
	if (str)
		ft_putstr_fd(str, 1);
	return (*seq);
}

void ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack *temp;
	if (!new)
		return ;
	temp = ft_lstlast(*lst);
	temp->next = new;
}



