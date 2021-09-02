#include "../push_swap.h"

int main(int argc, char **argv)
{
	t_stack *a;
	char *line;
	int order;

	a = NULL;
	if (argc <= 1)
		ft_error(1);
	order = ft_pushswap(&a, argv, 0);
//	ft_count(&a, order);
	while (get_next_line(&line))
	{
		write(1, "privet", 6);
	}
	return (0);
}
