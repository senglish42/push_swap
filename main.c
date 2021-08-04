#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

//	argc = 2;
//	argv[1] = "435";
//	argv[2] = "45";
//	argv[3] = "435";
//	argv[4] = '\0';
	b = NULL;
//	b = NULL;
	ft_parse(argc, argv);
	a = ft_filllist(argv);
	return 0;
}
