#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	a;

	if (!s || !fd)
		return ;
	a = 0;
	while (*(s + a))
		write (fd, s + a++, 1);
}
