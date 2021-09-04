#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_stack *a;

	a = NULL;
	if (argc <= 1)
		ft_error(1);
	ft_count(&a, ft_pushswap(&a, argv, 0));
	return (0);
}