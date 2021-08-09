#include "push_swap.h"
#include <stdio.h>

//int main(int argc, char **argv)
//{
//	t_stack *a;
//	t_stack *b;
//
//	b = NULL;
//	ft_parse(argc, argv);
//	a = ft_filllist(argv);
//	while (a)
//	{
//		printf("%d\n", a->value);
//		a = a->next;
//	}
//	return 0;
//}
int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	b = NULL;
	a = ft_parse(argc, argv);
	while (a)
	{
		printf("%d\n", a->order);
		a = a->next;
	}
	return (0);
}

