NAME	=	push_swap.a

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

LIBFT	=	libft/ft_memchr.c		libft/ft_strlen.c\
			libft/ft_strchr.c		libft/ft_strjoin.c\
			libft/ft_itoa.c			libft/ft_atoi.c			libft/ft_strdup.c\

SRC		=	src/ft_parse.c			src/ft_beginone.c		src/ft_beginzero.c\
			src/ft_isrecurrent.c\

HEADER	=	libft.h					push_swap.h\

OBJ		=	$(patsubst %.c,%.o,$(SRC))

LIBOBJ	=	$(patsubst %.c,%.o,$(LIBFT))

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(LIBOBJ)
		ar rsc $(NAME) $?

%.o		:	%.c $(HEADER)
		$(CC) $(CFLAGS) -o $@ -c $<

clean	:	$(RM) $(OBJ) $(LIBOBJ)

fclean	:	clean $(RM)	$(NAME)

re		:	fclean all

.PHONY	:	all	clean	fclean	re
