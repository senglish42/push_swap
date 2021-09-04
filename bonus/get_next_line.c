#include "../push_swap.h"

size_t	get_next_line(char **line)
{
	char	ch;
	char	*buf;
	int		i;
	size_t	res;

	ch = '\0';
	i = 0;
	buf = malloc(3);
	*line = buf;
	res = read(0, &ch, 1);
	while (res > 0 && ch != '\n')
	{
		buf[i++] = ch;
		res = read(0, &ch, 1);
	}
	buf[i] = '\0';
	return (res);
}
