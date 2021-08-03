#include "../push_swap.h"

void ft_beginzero(char **str1, char **str2, int arr);
void ft_beginone(char **str1, char **str2, int arr)
{
	int elem;
	int count;

	elem = arr;
	while (elem-- > 1)
	{
		if (ft_strchr(*(str1 + elem), 32))
		{
			count = 0;
			while (*(str2 + count))
				ft_isrecurrent(str1 + arr, str2 + count++);
		}
	}
}

void ft_beginzero(char **str1, char **str2, int arr)
{
	int elem;
	int count;
	int num;
	char **str3;

	elem = arr;
	while (elem-- > 1)
	{
		count = -1;
		while (*(str2 + ++count))
		{
			if (!ft_strchr(*(str1 + elem), 32))
				ft_isrecurrent(str2 + count, str1 + elem);
			else
			{
				str3 = ft_split(*(str1 + elem), 32);
				num = 0;
				while (*(str3 + num))
					ft_isrecurrent(str2 + count, str3 + num++);
			}
		}
	}
}