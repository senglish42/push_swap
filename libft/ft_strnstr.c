#include "../libft/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	size_t			nlen;
	size_t			hlen;

	nlen = ft_strlen(needle);
	hlen = ft_strlen(haystack);
	if (!needle || !*needle)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	if (len > hlen)
		len = hlen;
	i = 0;
	while (haystack[i] && i < len - nlen + 1)
	{
		if (ft_strncmp((haystack + i), needle, nlen) == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
