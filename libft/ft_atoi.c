#include "../libft/libft.h"

int	ft_atoi(const char *str)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	b = 1;
	c = 0;
	while ((str[a] >= 9 && str[a] <= 13) || str[a] == 32 || str[a] == 127)
		a++;
	if (str[a] == '+')
		a++;
	else if (str[a] == '-')
	{
		b = -b;
		a++;
	}
	while (str[a] >= 48 && str[a] <= 57)
	{
		c = c * 10 + ((str[a] - 48));
		a++;
	}
	c = b * c;
	return (c);
}
