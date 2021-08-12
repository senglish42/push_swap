#include "push_swap.h"
#include <stdio.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	t_stack *a;
//	int order;

	if (argc <= 1)
		ft_error(1);
	a = ft_isnumber(argv, 0);
//	ft_order(&a, order);
//	ft_count(&a, order);
	while (a)
	{
		printf("%d\n", a->value);
		printf("%d\n", a->order);
		a = a->next;
	}
	return (0);
}

