#include "../libft/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*a;
	int		b;

	a = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!a)
		return (NULL);
	b = 0;
	while (s1[b])
	{
		a[b] = s1[b];
		b++;
	}
	a[b] = '\0';
	return (a);
}
