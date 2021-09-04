#include "../push_swap.h"

void	ft_numintolist(t_stack **seq, t_stack *new)
{
	t_stack	*seqnum;

	if (*seq == NULL)
		*seq = new;
	else
	{
		seqnum = ft_lstlast(*seq);
		seqnum->next = new;
		new->next = NULL;
	}
}

t_stack	*ft_lstlast(t_stack *seq)
{
	while (seq->next)
		seq = seq->next;
	return (seq);
}

t_stack	*ft_lstnew(int content, int order)
{
	t_stack	*seq;

	seq = (t_stack *)malloc(sizeof(t_stack));
	if (!seq)
		return (NULL);
	seq->value = content;
	seq->order = order;
	seq->next = NULL;
	return (seq);
}
