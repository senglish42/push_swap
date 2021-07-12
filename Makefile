NAME	=	push_swap.a

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

LIBFT	=	libft/ft_memchr.c		libft/ft_strlen.c		libft/ft_putcharlen_fd.c\
			libft/ft_strchr.c		libft/ft_strjoin.c		libft/ft_putstrlen_fd.c\
			libft/ft_itoa.c			libft/ft_atoi.c			libft/ft_strdup.c\

SRC		=	src/

HEADER	=	libft.h					push_swap.h\

OBJ		=	$(patsubst %.c,%.o,$(SRC))

LIBOBJ	=	$(patsubst %.c,%.o,$(LIBOBJ))

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(LIBOBJ)
		ar rsc $(NAME) $?

%.o		:	%.c $(HEADER)
		$(CC) $(CFLAGS) -o $@ -c $<

clean	:	$(RM) $(OBJ) $(LIBOBJ)

fclean	:	clean $(RM)	$(NAME)

re		:	fclean all

.PHONY	:	all	clean	fclean	re
