#include "../push_swap.h"

void ft_isrecurrent(char **str1, char **str2);
void ft_error(int code);
static size_t ft_strbigger(char **str1, char **str2);
static void ft_isnumber(char **argv, int arr, int begin);
void ft_parse(int argc, char **argv, t_stack **row)
{
	int count;
//	int num;
	char **str;

	(void)row;
	if (argc <= 1)
		ft_error(1);
	argc = 1;
	while (*(argv + argc))
	{
		if (ft_strchr(*(argv + argc), 32))
		{
			str = ft_split(*(argv + argc), 32);
			count = 0;
			while (*(str + count))
				ft_isnumber(str, count++, 0);
			ft_beginzero(argv, str, argc++);
		}
		else
		{
			ft_isnumber(argv, argc, 1);
			ft_beginone(argv, str, argc++);
		}
	}
//	num = argc;
//	while (num > 1)
//	{
//		while (!ft_strchr(*(argv + argc), 32))
//			argc--;
//		str = ft_split(*(argv + argc), 32);
//		while (num > argc)
//		{
//			count = 0;
//			while (*(str + count))
//			{
//				if (!ft_memcmp(*(argv + num), *(str + count++), ft_strbigger
//						(*(argv + num), *(str + count))))
//					ft_error(3);
//			}
//			num--;
//		}
//		while ()
//	}
}

static void ft_isnumber(char **argv, int arr, int begin)
{
	int elem;
	long int num;

	elem = 0;
	while (*(*(argv + arr) + elem))
	{
		if ((*(*(argv + arr) + elem) == '-') || (*(*argv + arr) + elem) == '+')
			elem++;
		if (ft_isdigit(*(*(argv + arr) + elem++)) == 0)
			ft_error(2);
	}
	num = ft_atoi(*(argv + arr));
	if (num < -2147483648 || num > 2147483647)
		ft_error(4);
	elem = arr;
	while (elem-- > begin)
		ft_isrecurrent(argv + arr, argv + elem);
}

void ft_error(int code)
{
	if (code == 1)
		ft_putstr_fd("Error: input at least one number\n", 1);
	if (code == 2)
		ft_putstr_fd("Error: string should contain only figures\n", 1);
	if (code == 3)
		ft_putstr_fd("Error: some numbers are recurrent\n", 1);
	if (code == 4)
		ft_putstr_fd("Error: your number is out of integer\n", 1);
	exit (1);
}

void ft_isrecurrent(char **str1, char **str2)
{
	if (!ft_memcmp(*str1, *str2, ft_strbigger(str1, str2)))
		ft_error(3);
}

static size_t ft_strbigger(char **str1, char **str2)
{
	size_t size1;
	size_t size2;

	size1 = ft_strlen(*str1);
	if (ft_strchr(*str2, 32))
		return ;
	size2 = ft_strlen(*str2);
	if (size1 >= size2)
		return (size1);
	return (size2);
}
