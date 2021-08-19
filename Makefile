CFILE =     src/ft_pushswap.c	src/ft_filllist.c	src/ft_order.c\
			src/ft_pushelem.c	src/ft_rotate.c		src/ft_param.c\
			src/ft_re_rotate.c	src/ft_count.c		src/ft_error.c\
			src/ft_swaptwo.c 	main.c
OFILE = $(CFILE:.c=.o)
CFLAGS = -Wall -Wextra -Werror -I libft.h
CC = clang
NAME = push_swap
HEADER = push_swap.h
%.o:        %.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $<
#
all: $(NAME)

${NAME}: $(OFILE)
	$(MAKE) -C ./libft
	gcc  $(OFILE) ./libft/libft.a -o $(NAME)

#liba:
#	$(MAKE) -C ./libft
clean:
	${MAKE} clean -C ./libft
	rm -rf ${OFILE}

fclean:
	${MAKE} fclean -C ./libft
	rm -rf ${NAME} $(OFILE)

re: fclean all
.PHONY : all clean fclean re