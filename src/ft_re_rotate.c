#include "../push_swap.h"

//void ft_lstaddprelast(t_stack **lst);
void ft_re_rotate(t_stack **seq, char *str)
{
	t_stack 	*copy;
	t_stack 	*copy2;

	if (!*seq)
		return ;
	copy = *seq;
	copy2 = NULL;
	while (copy->next)
	{
		copy2 = copy;
		copy = copy->next;
	}
	copy2->next = NULL;
	copy->next = *seq;
	*seq = copy;
	if (str)
		ft_putstr_fd(str, 1);
}

//if ((*seq)->order > (*seq)[1].order && (*seq)->order > (*seq)[2].order && (*seq)->order > (*seq)[3].order)
//ft_rotate(seq, "ra\n");
//else if ((*seq)->order > (*seq)[1].order && (*seq)->order > (*seq)[2].order && (*seq)->order < (*seq)[3].order)
//ft_prelast(seq);
//else if ((*seq)->order > (*seq)[1].order && (*seq)->order < (*seq)[2].order && (*seq)->order < (*seq)[3].order)
//ft_swaptwo(seq, "sa\n");
//	t_stack *temp1;
//
//	if (!seq)
//		return ;
//	temp1 = *seq;
//	while (temp1->next)
//		temp1 = temp1->next;
//	ft_lstaddprelast(seq);
//	ft_lstadd_front(seq, temp1);
//	if (str)
//		ft_putstr_fd(str, 1);
//}
//
//void	ft_lstadd_front(t_stack **lst, t_stack *new)
//{
//	new->next = *lst;
//	*lst = new;
//}
//
//void ft_lstaddprelast(t_stack **lst)
//{
//	t_stack *temp;
//
//	temp = *lst;
//	while (temp->next)
//	{
//		if (temp->next->next == NULL)
//			break;
//		temp = temp->next;
//	}
//	temp->next = NULL;
//	*lst = temp;
//}
