#include "push_swap.h"
#include <stdio.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	t_stack *a;

	if (argc <= 1)
		ft_error(1);
	a = ft_pushswap(argv, 0);
	while (a)
	{
		printf("%d\n", a->value);
		printf("%d\n", a->order);
		a = a->next;
	}
	return (0);
}

