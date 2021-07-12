#include "../libft/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			count;
	unsigned char	*to;
	unsigned char	*from;
	unsigned char	a;

	count = 0;
	from = (unsigned char *)src;
	to = (unsigned char *)dst;
	a = (unsigned char)c;
	while (count < n)
	{
		*(to + count) = *(from + count);
		if (*(from + count) == a)
			return (dst + (++count));
		count++;
	}
	return (NULL);
}
