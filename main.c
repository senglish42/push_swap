#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = NULL;
	if (argc <= 1)
		ft_error(0);
	ft_count(&a, ft_pushswap(&a, argv, 0));
	return (0);
}
