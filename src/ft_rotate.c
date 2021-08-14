#include "../push_swap.h"

void	ft_rotate(t_stack **seq, char *str)
{
	t_stack *temp1;
	t_stack *temp2;

	if (!*seq)
		return ;
	temp1 = *seq;
	temp2 = temp1->next;
	temp1->next = NULL;
	ft_lstadd_back(&temp2, temp1);
	*seq = temp2;
	if (str)
		ft_putstr_fd(str, 1);
}

void ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack *temp;

	if (!new)
		return ;
	temp = ft_lstlast(*lst);
	temp->next = new;
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}



