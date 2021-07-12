#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_struct
{
	int 			value;
	int 			order;
	int 			flag;
	struct s_struct	*next;
}					t_stack;
void ft_parse(int argc, char **argv, t_stack **row);

#endif
