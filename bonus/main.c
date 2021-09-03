#include "../push_swap.h"

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	char *line;
	int order;

	a = NULL;
	b = NULL;
	if (argc <= 1)
		ft_error(1);
	order = ft_pushswap(&a, argv, 0);
	while (get_next_line(&line))
	{
		ft_make(line, &a, &b);
		free(line);
		line = NULL;
	}
	if (!a)
		ft_putstr_fd("KO", 1);
	else
		ft_check(&a, order);
	return (0);
}
