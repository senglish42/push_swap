#include "../push_swap.h"

static int *ft_charorder(int *str, t_stack *temp);
void ft_order(t_stack **seq, int order){
	t_stack *temp;
	int *str;

	if (!*seq)
		return;
	temp = *seq;
	str = (int *) malloc(sizeof(int) * order);
	*(str + order) = '\0';
	ft_charorder(str, temp);
	while (order-- > 0) {
		temp = *seq;
		while (order >= 0 && (*(str + order) != temp->value))
			temp = temp->next;
		//	if (*(str + order) == temp->value)
		temp->order = order;
	}
	free(str);
	str = NULL;
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