#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

int		get_next_line(char **line);
//char	*ft_strdup (const char *s1);
//void	*ft_memchr(const void *s, int c, size_t n);
//char	*ft_strchr(const char *s, int c);
//size_t	ft_strlen(const char *str);
//char	*ft_strdupton(const char *s1);

#endif
