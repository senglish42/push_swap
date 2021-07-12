#include "../libft/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;
	unsigned int	j;
	unsigned int	lenlen;

	if (!s || ft_strlen(s) < start)
		return (ft_strdup(""));
	lenlen = ft_strlen(s) - start;
	if (lenlen < len)
		len = lenlen;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[start + i] && j < len)
		res[j++] = s[start + (i++)];
	res[j] = '\0';
	return (res);
}
