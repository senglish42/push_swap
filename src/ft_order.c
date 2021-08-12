#include "../push_swap.h"

static int *ft_charorder(int *str, t_stack *temp);
void ft_order(t_stack **seq, int order)
{
	t_stack *temp;
	int *str;

	if (!*seq)
		return ;
	temp = *seq;
	str = (int *)malloc(sizeof(int) * order + 1);
	*(str + order) = '\0';
	ft_charorder(str, temp);
	while (temp)
	{
		order = -1;
		while (*(str + ++order))
			if (*(str + order) == temp->value)
				temp->order = order;
		temp = temp->next;
	}
}

static int *ft_charorder(int *str, t_stack *temp)
{
	int countdown;
	int order;

	order = -1;
	while (temp)
	{
		if (++order > 0 && *(str + order - 1) > temp->value)
		{
			countdown = order;
			while (countdown > 0 && *(str + countdown - 1) > temp->value)
			{
				*(str + countdown) = *(str + countdown - 1);
				*(str + countdown-- - 1) = temp->value;
			}
		}
		else
			*(str + order) = temp->value;
		temp = temp->next;
	}
	return (str);
}