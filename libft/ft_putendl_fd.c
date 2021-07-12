#include "../libft/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	a;

	if (!s || !fd)
		return ;
	a = 0;
	while (*(s + a))
	{
		write (fd, s + a, 1);
		a++;
	}
	write (fd, "\n", 1);
}
