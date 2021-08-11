#include "../push_swap.h"
#include "stdio.h"

t_stack *ft_swaptwo(t_stack **seq)
{
	printf("\n");
	t_stack *temp1;
	t_stack *temp2;
	t_stack *temp3;
	int count;

	if (!*seq)
		return (NULL);
	temp1 = *seq;
	count = 0;
	while (temp1)
	{
		temp1 = temp1->next;
		count++;
	}
	if (count < 2)
		return (NULL);
	temp1 = *seq;
	temp2 = temp1;
	temp1 = temp1->next;
	temp2->next = NULL;
	temp3 = temp1;
	temp1 = temp1->next;
	temp2->next = temp1;
	temp3->next = NULL;
	temp3->next = temp2;
	*seq = temp3;
//	while (temp1)
//	{
//		printf("%d\n", temp1->order);
//		temp1 = temp1->next;
//	}
//	printf("\n");
	return (*seq);
}