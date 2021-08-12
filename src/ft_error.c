#include "../push_swap.h"

void ft_error(int code)
{
	if (code == 1)
		ft_putstr_fd("Error: input at least one number\n", 1);
	if (code == 2)
		ft_putstr_fd("Error: string should contain only figures\n", 1);
	if (code == 3)
		ft_putstr_fd("Error: your number is out of integer\n", 1);
	if (code == 4)
		ft_putstr_fd("Error: some numbers are recurrent\n", 1);
	exit (1);
}
