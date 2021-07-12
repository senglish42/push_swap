#include "../libft/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			a;
	unsigned char	*b;

	if (!s)
		return (NULL);
	a = 0;
	b = (unsigned char *)s;
	while (a < n)
	{
		if (b[a] == (unsigned char)c)
			return (b + a);
		a++;
	}
	return (NULL);
}