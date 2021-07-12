#include "../libft/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	str = (void *)malloc(count * size);
	if (!str)
		return (NULL);
	ft_bzero(str, size * count);
	return (str);
}
