#include "../push_swap.h"
#include <stdio.h>

static void		ft_strbigger(char **str1, char **str2);
static long int	ft_elemloop(char **argv, int count, int begin);
static void		ft_strloop(char **str1, char **str2, int count, int begin);
static int		ft_doublequotes(t_stack **seq, char **argv, int argc, int order);
t_stack			*ft_pushswap(char **argv, int argc)
{
	t_stack *seq;
	int order;

	seq = NULL;
	order = 0;

	while (*(argv + ++argc))
	{
		if (ft_strchr(*(argv + argc), 32))
			order = ft_doublequotes(&seq, argv, argc, order);
		else
			ft_numintolist(&seq, ft_lstnew((int) ft_elemloop(argv, argc, 1), order++));
	}
	ft_order(&seq, order);
	ft_count(&seq, order);
//	order = 0;
//	while (seq)
//	{
//		if (seq->value == ++order)
//		{
//			if (seq->value == 500)
//				printf("%s\n", "yes");
//			seq = seq->next;
//		}
//		else
//		{
//			printf("%s\n", "no");
//			printf("%d\n", seq->order);
//			break;
//		}
//	}
	return (seq);
}

static int ft_doublequotes(t_stack **seq, char **argv, int argc, int order)
{
	char **str;
	int count;

	str = ft_split(*(argv + argc), 32);
	count = -1;
	while (*(str + ++count))
	{
		ft_strloop(str + count, argv, argc, 1);
		ft_numintolist(seq, ft_lstnew((int) ft_elemloop(str, count, 0), order++));
	}
	free(*str);
	return (order);
}

static void ft_strloop(char **str1, char **str2, int count, int begin)
{
	int elem;

	elem = count;
	while (elem-- > begin)
		ft_strbigger(str1, str2 + elem);
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
		ft_error(3);
	ft_strloop(argv + count, argv, count, begin);
	return (num);
}

static void ft_strbigger(char **str1, char **str2)
{
	char **mas;
	int count;
	size_t size1;
	size_t size2;

	if (ft_strchr(*str2, 32))
	{
		count = -1;
		mas = ft_split(*str2, 32);
		while (*(mas + ++count))
			ft_strbigger(str1, mas + count);
		free(*mas);
		return ;
	}
	size2 = ft_strlen(*str2);
	size1 = ft_strlen(*str1);
	if (size1 < size2)
		size1 = size2;
	if (!ft_memcmp(*str1, *str2, size1))
		ft_error(4);
}
