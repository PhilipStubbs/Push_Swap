
#include "push_swap.h"

int				*lastcmdb(char *cmd, t_stack *temp)
{
	int *ret;

	ret = (int*)malloc(sizeof(int) * 2);
	ret[0] = -1;
	ret[1] = -1;
	if (ft_strcmp(cmd, "sb") == 0 || ft_strcmp(cmd, "ss") == 0)
	{
		ret[0] = 0;
		ret[1] = 1;
	}
	else if (ft_strcmp(cmd, "rb") == 0 || ft_strcmp(cmd, "rr") == 0)
	{
		if (listsize(temp) == 1)
			ft_putstr(CYN);
	}
	else if (ft_strcmp(cmd, "rrb") == 0 || ft_strcmp(cmd, "rrr") == 0)
		ret[0] = 0;
	else if (ft_strcmp(cmd, "pb") == 0)
		ret[0] = 0;
	return (ret);
}

int				*lastcmda(char *cmd, t_stack *temp)
{
	int *ret;

	ret = (int*)malloc(sizeof(int) * 2);
	ret[0] = -1;
	ret[1] = -1;
	if (ft_strcmp(cmd, "sa") == 0 || ft_strcmp(cmd, "ss") == 0)
	{
		ret[0] = 0;
		ret[1] = 1;
	}
	else if (ft_strcmp(cmd, "ra") == 0 || ft_strcmp(cmd, "rr") == 0)
	{
		if (listsize(temp) == 1)
			ft_putstr(CYN);
	}
	else if (ft_strcmp(cmd, "rra") == 0 || ft_strcmp(cmd, "rrr") == 0)
		ret[0] = 0;
	else if (ft_strcmp(cmd, "pa") == 0)
		ret[0] = 0;
	return (ret);
}



static int		output(t_stack *temp, int count, char *cmd, int ab)
{	
	int *loc;

	if (ab == 1)
		loc = lastcmda(cmd, temp);
	else
		loc = lastcmdb(cmd, temp);
	if ((count == loc[0] || count == loc[1]) && loc[0] != -1)
		ft_putstr(CYN);
	ft_putchar_fd(' ', 2);
	ft_putnbr_fd(temp->data, 2);
	ft_putstr(NRM);
	return (1);
}

static void		loop(t_stack *tempa, t_stack *tempb, int isplaced, int size, char *cmd)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < size)
	{
		if (tempa != NULL)
		{
			isplaced = output(tempa, count, cmd, 1);
			tempa = tempa->next;
		}
		if (tempb != NULL)
		{
			ft_putchar_fd('\t', 2);
			isplaced = output(tempb, count, cmd, 2);
			tempb = tempb->next;
		}
		i++;
		if (isplaced == 1)
			ft_putchar_fd('\n', 2);
		isplaced = 0;
		count++;
	}
	ft_putendl_fd("___	___", 2);
	ft_putendl_fd(" a	 b", 2);
}

void		colouroutput(t_hold *node, char *cmd)
{
	t_stack	*tempa;
	t_stack	*tempb;
	int		isplaced;

	if (node->colour != 1 && node->supcolour != 1)
		return ;
	tempa = node->a;
	tempb = node->b;
	isplaced = 0;
	loop(tempa, tempb, isplaced, node->size, cmd);
}
