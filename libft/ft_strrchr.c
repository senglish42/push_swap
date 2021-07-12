#include "../libft/libft.h"

static void	*ft_memrchr(const void *s, int c, size_t n);

char	*ft_strrchr(const char *s, int c)
{
	return (ft_memrchr(s, c, ft_strlen(s) + 1));
}

static void	*ft_memrchr(const void *s, int c, size_t n)
{
	unsigned char	*b;

	b = (unsigned char *)s + n - 1;
	while (n > 0)
	{
		if (*b == (unsigned char)c)
			return (b);
		b--;
		n--;
	}
	return (0);
}
