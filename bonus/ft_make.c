#include "../push_swap.h"

static void	ft_make_a(char *line, t_stack **a, t_stack **b)
{
	if (!ft_memcmp(line, "ra", 2))
		ft_rotate(a, 0);
	else if (!ft_memcmp(line, "rra", 3))
		ft_re_rotate(a, 0);
	else if (!ft_memcmp(line, "sa", 2))
		ft_swaptwo(a, 0);
	else if (!ft_memcmp(line, "pa", 2))
		ft_pushelem(b, a, 0);
	else
	{
		ft_putstr_fd("Error\n", 1);
		exit(1);
	}
}

static void	ft_make_b(char *line, t_stack **a, t_stack **b)
{
	if (!ft_memcmp(line, "rb", 2))
		ft_rotate(b, 0);
	else if (!ft_memcmp(line, "rrb", 3))
		ft_re_rotate(b, 0);
	else if (!ft_memcmp(line, "sb", 2))
		ft_swaptwo(b, 0);
	else if (!ft_memcmp(line, "pb", 2))
		ft_pushelem(a, b, 0);
	else
	{
		ft_putstr_fd("Error\n", 1);
		exit(1);
	}
}

static void	ft_make_both(char *line, t_stack **a, t_stack **b)
{
	if (!ft_memcmp(line, "ss", 2))
	{
		ft_swaptwo(b, 0);
		ft_swaptwo(a, 0);
	}
	else if (!ft_memcmp(line, "rrr", 3))
	{
		ft_re_rotate(b, 0);
		ft_re_rotate(a, 0);
	}
	else if (!ft_memcmp(line, "rr", 2))
	{
		ft_rotate(b, 0);
		ft_rotate(a, 0);
	}
	else
	{
		ft_putstr_fd("Error\n", 1);
		exit(1);
	}
}

void	ft_make(char *line, t_stack **a, t_stack **b)
{
	int	count;

	count = 0;
	while (*(line + count))
		count++;
	if (line[count - 1] == 'a')
		ft_make_a(line, a, b);
	else if (line[count - 1] == 'b')
		ft_make_b(line, a, b);
	else if (line[count - 1] == 's' || line[count - 1] == 'r')
		ft_make_both(line, a, b);
	else
	{
		ft_putstr_fd("Error\n", 1);
		exit(1);
	}
}
