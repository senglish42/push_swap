CFILE =     src/ft_pushswap.c	src/ft_filllist.c	src/ft_order.c\
			src/ft_pushelem.c	src/ft_rotate.c		src/ft_param.c\
			src/ft_re_rotate.c	src/ft_count.c		src/ft_error.c\
			src/ft_swaptwo.c
OFILE = $(CFILE:.c=.o)
BFILE =		bonus/get_next_line.c	bonus/get_next_line_utils.c
BOFILE = $(BFILE:.c=.o)
CFLAGS = -Wall -Wextra -Werror -I libft.h
CC = clang
NAME = push_swap
BNAME = checker
HEADER = push_swap.h
BHEADER = get_next_line.h
%.o:        %.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $<
#
all: $(NAME)

${NAME}: $(OFILE)
	$(MAKE) -C ./libft
	gcc  $(OFILE) ./libft/libft.a -o $(NAME)

${BNAME}: $(BFILE)
	$(MAKE) -C ./libft
	gcc  $(BFILE) ./libft/libft.a -o $(BNAME)

bonus: $(BNAME)

#liba:
#	$(MAKE) -C ./libft
clean:
	${MAKE} clean -C ./libft
	rm -rf ${OFILE} ${BFILE}

fclean:
	${MAKE} fclean -C ./libft
	rm -rf ${NAME} ${OFILE} ${BNAME} ${BFILE}

re: fclean all

.PHONY : all clean fclean re bonus