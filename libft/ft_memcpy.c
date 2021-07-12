#include "../libft/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			a;
	unsigned char	*b;
	unsigned char	*c;

	a = 0;
	b = (unsigned char *)src;
	c = (unsigned char *)dst;
	if (!dst && !src)
		return (NULL);
	if (b == 0 && c == 0)
		return (dst);
	while (a < n)
	{
		c[a] = b[a];
		a++;
	}
	return (c);
}
