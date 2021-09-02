#include "../push_swap.h"

//char	*ft_substr(char const *s, size_t len);
//char	*ft_strjoin(char const *s1, char const *s2);
//int		get_into_gnl(int fd, char **line, char *buff, size_t count);
//int		get_into_loop(char **ost, char **line, char **tm);
//
//int	get_next_line(int fd, char **line)
//{
//	char	buff[BUFFER_SIZE + 1];
//	int		a;
//	size_t	count;
//
//	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
//		return (-1);
//	count = 1;
//	a = get_into_gnl(fd, &(*line), buff, count);
//	if (a < 0)
//		return (-1);
//	if (a > 0)
//		return (1);
//	return (0);
//}
//
//int	get_into_gnl(int fd, char **line, char *buff, size_t count)
//{
//	static char	*tmp;
//	static char	*ost;
//	int			a1;
//
//	while (count || ft_strchr(ost, '\n'))
//	{
//		count = read(fd, buff, BUFFER_SIZE);
//		buff[count] = '\0';
//		if (!ft_strlen(ost))
//			tmp = ft_strdup(buff);
//		else
//			tmp = ft_strjoin(ost, buff);
//		a1 = get_into_loop(&ost, &(*line), &tmp);
//		if (a1 < 0)
//			return (-1);
//		if (a1 > 0)
//			return (1);
//	}
//	*line = ft_strdup(ost);
//	free(ost);
//	ost = NULL;
//	if (!*line)
//		return (-1);
//	return (0);
//}
//
//int	get_into_loop(char **ost, char **line, char **tmp)
//{
//	free(*ost);
//	*ost = NULL;
//	if (!*tmp)
//		return (-1);
//	if (ft_strchr(*tmp, '\n'))
//	{
//		*line = ft_strdupton(*tmp);
//		if (!*line)
//			return (-1);
//		*ost = ft_substr(*tmp, ft_strlen(*tmp));
//		if (!*ost)
//			return (-1);
//		free(*tmp);
//		*tmp = NULL;
//		return (1);
//	}
//	*ost = ft_strdup(*tmp);
//	free(*tmp);
//	*tmp = NULL;
//	if (!*ost)
//		return (-1);
//	return (0);
//}
//
//char	*ft_substr(char const *s, size_t len)
//{
//	char			*res;
//	unsigned int	i;
//	unsigned int	j;
//
//	if (!s)
//		return (ft_strdup(""));
//	res = (char *)malloc(sizeof(char) * (len + 1));
//	if (!res)
//		return (NULL);
//	i = 0;
//	j = 0;
//	while (s[i])
//	{
//		if ((s[i]) == '\n')
//			break ;
//		i++;
//	}
//	while (s[i] && i < len)
//		res[j++] = s[i++ + 1];
//	res[j] = '\0';
//	return (res);
//}
//
//char	*ft_strjoin(char const *s1, char const *s2)
//{
//	char	*a;
//	int		b;
//	int		c;
//
//	if (!s1 || !s2)
//		return (NULL);
//	a = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
//	b = 0;
//	c = 0;
//	if (a == NULL)
//		return (NULL);
//	while (s1[b])
//	{
//		a[b] = s1[b];
//		b++;
//	}
//	while (s2[c])
//		a[b++] = s2[c++];
//	a[b] = '\0';
//	return (a);
//}
int get_next_line(char **line)
{
	char ch;
	char *buf;
	int i;
	int res;

	ch = '\0';
	i = 0;
	buf = malloc(3);
	*line = buf;
	while ((res = read(0, &ch, 1)) > 0 && ch != '\n')
		buf[i++] = ch;
	buf[i] = '\0';
	return (res);
}