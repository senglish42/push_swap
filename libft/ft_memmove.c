#include "../libft/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			a;
	unsigned char	*b;
	unsigned char	*c;

	a = 0;
	b = (unsigned char *)src;
	c = (unsigned char *)dst;
	if (!c && !b)
		return (NULL);
	while (a < len)
	{
		if (c > b)
		{
			c[len - 1] = b[len - 1];
			len--;
		}
		if (b >= c)
		{
			c[a] = b[a];
			a++;
		}
	}
	return (c);
}
