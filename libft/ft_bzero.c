#include "../libft/libft.h"

void	ft_bzero(void *array, size_t bytes)
{
	size_t	a;
	char	*b;

	a = 0;
	b = (char *)array;
	while (a < bytes)
	{
		b[a] = 0;
		a++;
	}
}
