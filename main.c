#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_stack *a;
	int		order;

	a = NULL;
	if (argc <= 1)
		ft_error(1);
	ft_pushswap(&a, argv, 0);
	order = 0;
	while (a)
	{
		if (a->value == ++order)
		{
			if (a->value == 500)
				printf("%s\n", "yes");
			a = a->next;
		}
		else
		{
			printf("%s\n", "no");
			printf("%d\n", a->order);
			break;
		}
	}
//	while (1);
	return (0);
}

