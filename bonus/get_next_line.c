#include "../push_swap.h"

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