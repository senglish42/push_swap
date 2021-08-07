#include "../push_swap.h"

void ft_isrecurrent(char **str1, char **str2, size_t strbigger);
void ft_error(int code);
static void ft_strbigger(char **str1, char **str2);
t_stack *ft_isnumber(t_stack **seq, char **argv, int arr);
static long int ft_elemloop(char **argv, int count, int begin);
static void ft_splitstr(char **str1, char **str2);
t_stack *ft_parse(int argc, char **argv)
{
	t_stack *seq;

	seq = NULL;
	if (argc <= 1)
		ft_error(1);
	argc = 1;
	while (*(argv + argc))
		ft_isnumber(&seq, argv, argc++);
	return (seq);
}

t_stack *ft_isnumber(t_stack **seq, char **argv, int arr)
{
	int elem;
	char **str;
	int count;

	if (ft_strchr(*(argv + arr), 32))
	{
		str = ft_split(*(argv + arr), 32);
		count = -1;
		while (*(str + ++count))
		{
			elem = arr;
			while (elem-- > 1)
				ft_strbigger(str + count, argv + elem);
			ft_numintolist(seq, ft_lstnew((int)ft_elemloop(str, count, 0)));
		}
		free(*str);
	}
	else
		ft_numintolist(seq, ft_lstnew((int)ft_elemloop(argv, arr, 1)));
	return (*seq);
}

static long int ft_elemloop(char **argv, int count, int begin)
{
	int elem;
	long int num;

	elem = 0;
	while (*(*(argv + count) + elem))
	{
		if ((*(*(argv + count) + elem) == '-') || (*(*argv + count) + elem) == '+')
			elem++;
		if (ft_isdigit(*(*(argv + count) + elem++)) == 0)
			ft_error(2);
	}
	num = ft_atoi(*(argv + count));
	if (num < -2147483648 || num > 2147483647)
		ft_error(4);
	elem = count;
	while (elem-- > begin)
		ft_strbigger(argv + count, argv + elem);
	return (num);
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

void ft_isrecurrent(char **str1, char **str2, size_t strbigger)
{
	if (!ft_memcmp(*str1, *str2, strbigger))
		ft_error(3);
}

static void ft_strbigger(char **str1, char **str2)
{
	size_t size1;
	size_t size2;

	if (ft_strchr(*str1, 32))
		ft_splitstr(str1, str2);
	if (ft_strchr(*str2, 32))
		ft_splitstr(str2, str1);
	size1 = ft_strlen(*str1);
	size2 = ft_strlen(*str2);
	if (size1 >= size2)
		ft_isrecurrent(str1, str2, size1);
	ft_isrecurrent(str1, str2, size2);
}

static void ft_splitstr(char **str1, char **str2)
{
	char **mas;
	int count;

	count = -1;
	mas = ft_split(*str1, 32);
	while (*(mas + ++count))
		ft_strbigger(mas + count, str2);
	free(*mas);
}

