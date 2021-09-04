#include "../push_swap.h"

void	ft_re_rotate(t_stack **seq, char *str)
{
	t_stack	*copy;
	t_stack	*copy2;

	if (!*seq || !(*seq)->next)
		return ;
	copy = *seq;
	copy2 = NULL;
	while (copy->next)
	{
		copy2 = copy;
		copy = copy->next;
	}
	copy2->next = NULL;
	copy->next = *seq;
	*seq = copy;
	if (str)
		ft_putstr_fd(str, 1);
}
