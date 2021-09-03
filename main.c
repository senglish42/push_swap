#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_stack *a;
	int order;

	a = NULL;
	if (argc <= 1)
		ft_error(1);
	ft_count(&a, ft_pushswap(&a, argv, 0));
//	order = 0;
//	while (a)
//	{
//		if (a->value == ++order)
//		{
//			if (a->value == 9)
//				printf("%s\n", "yes");
//			a = a->next;
//		}
//		else
//		{
//			printf("%s\n", "no");
//			printf("%d\n", a->order);
//			break;
//		}
//		printf("%d %d\n", a->order, a->value);
//	}
	//	while (1);
	return (0);
}