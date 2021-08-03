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
void ft_beginone(char **str1, char **str2, int arr);
void ft_beginzero(char **str1, char **str2, int arr);
void ft_isrecurrent(char **str1, char **str2);
//t_param settings(void);
#endif
