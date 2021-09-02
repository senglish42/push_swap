//#include "../push_swap.h"
//
//char	*ft_strdup(const char *s1)
//{
//	char	*a;
//	int		b;
//
//	if (!s1)
//		return (NULL);
//	a = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
//	if (!a)
//		return (NULL);
//	b = 0;
//	while (s1[b])
//	{
//		a[b] = s1[b];
//		b++;
//	}
//	a[b] = '\0';
//	return (a);
//}
//
//char	*ft_strchr(const char *s, int c)
//{
//	return (ft_memchr(s, c, ft_strlen(s)));
//}
//
//void	*ft_memchr(const void *s, int c, size_t n)
//{
//	size_t			a;
//	unsigned char	*b;
//
//	if (!s)
//		return (NULL);
//	a = 0;
//	b = (unsigned char *)s;
//	while (a < n)
//	{
//		if (b[a] == (unsigned char)c)
//			return (b + a);
//		a++;
//	}
//	return (NULL);
//}
//
//size_t	ft_strlen(const char *str)
//{
//	size_t	a;
//
//	if (!str)
//		return (0);
//	a = 0;
//	while (str[a] != '\0')
//		a++;
//	return (a);
//}
//
//char	*ft_strdupton(const char *s1)
//{
//	char	*a;
//	int		b;
//	int		c;
//
//	if (!s1)
//		return (NULL);
//	c = 0;
//	while (s1[c] && s1[c] != '\n')
//		c++;
//	a = (char *)malloc(sizeof(char) * (c + 1));
//	if (!a)
//		return (NULL);
//	b = 0;
//	while (s1[b] && s1[b] != '\n')
//	{
//		a[b] = s1[b];
//		b++;
//	}
//	a[b] = '\0';
//	return (a);
//}
