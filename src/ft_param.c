#include "../push_swap.h"

t_stack	*settings(t_stack **b)
{
	t_stack	*set;

	set = *b;
	*b = set->next;

	set->b_rotate = -1;
	set->b_reverse = -1;
	set->a_reverse = -1;
	*b = set;
	return (*b);
}
