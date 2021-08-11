#include "../push_swap.h"

static void ft_lstaddprelast(t_stack **lst);
static t_stack *ft_lstprelast(t_stack *seq);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack *ft_re_rotate(t_stack **seq)
{
	t_stack *temp1;

	if (!*seq)
		return (NULL);
	temp1 = *seq;
	while (temp1->next)
		temp1 = temp1->next;
	ft_lstaddprelast(seq);
	ft_lstadd_front(seq, temp1);
	return (*seq);
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

static void ft_lstaddprelast(t_stack **lst)
{
	t_stack *temp;

	temp = ft_lstprelast(*lst);
	temp->next = NULL;
}

static t_stack *ft_lstprelast(t_stack *seq)
{
	while (seq->next)
	{
		if (seq->next->next == NULL)
			break;
		seq = seq->next;
	}
	return (seq);
}

