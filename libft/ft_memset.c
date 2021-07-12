#include "../libft/libft.h"

void	*ft_memset(void *array, int symbol, size_t bytes)
{
	size_t			a;
	unsigned char	*b;

	b = (unsigned char *)array;
	a = 0;
	while (a < bytes)
	{
		b[a] = (unsigned char)symbol;
		a++;
	}
	return (b);
}
