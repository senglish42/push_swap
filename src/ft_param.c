#include "../push_swap.h"

t_stack	*settings(t_stack **b)
{
	t_stack	*set;

	set = *b;
	*b = set->next;

	set->top = 0;
	set->b_rotate = 0;
	set->reverse = 0;
	set->a_reverse = 0;
	set->a_rotate = 0;
	set->b_reverse = 0;
	*b = set;
	return (*b);
}
