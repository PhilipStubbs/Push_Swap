#include "push_swap.h"

int		max(t_stack *list)
{
	int hi;
	t_stack *tmp;

	tmp = list;
	hi = -2147483648;
	while(tmp != NULL)
	{
		if (tmp->data > hi)
			hi = tmp->data;
		tmp = tmp->next;
	}
	return (hi);
}

int		maxinstack(t_stack *list, int prevmax)
{
	int hi;
	t_stack *tmp;

	tmp = list;
	hi = -2147483648;

	while(tmp != NULL)
	{
		if (tmp->data > hi && tmp->data < prevmax)
			hi = tmp->data;
		tmp = tmp->next;
	}
	return (hi);
}

int		ispossorted(t_stack *list)
{
	t_stack	*tmpa;

	tmpa = list;
	while (tmpa != NULL)
	{
		if (tmpa->pos == 0)
		{	
			return (0);
		}
		tmpa = tmpa->next;
	}
	return (1);
}

int		normlize(t_hold *node, int size)
{
	int		tmpmax;
	t_stack *a;

	a = node->a;
	tmpmax = max(a);
	while (size != 0)
	{
		while (a != NULL)
		{
			if (a->data == tmpmax)
			{
				a->pos = size;
				size--;
				a = node->a;
				tmpmax = maxinstack(a, tmpmax);
				break;
			}
			a = a->next;
		}
		a = node->a;
	}

	// t_stack *tmp;
	// tmp = node->a;
	// while(tmp != NULL)
	// {
	// 	printf("%d:[%d]\n",tmp->data, tmp->pos );
	// 	tmp = tmp->next;
	// }
	return (1);
}