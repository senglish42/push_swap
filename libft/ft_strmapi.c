#include "../libft/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*a;
	unsigned int	b;

	if (!s || !f)
		return (NULL);
	a = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (a == NULL)
		return (NULL);
	b = 0;
	while (s[b])
	{
		a[b] = f(b, s[b]);
		b++;
	}
	a[b] = '\0';
	return (a);
}
