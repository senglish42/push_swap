#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	if (argc > 1)
		ft_parse(argc, argv, &a);
	return 0;
}
