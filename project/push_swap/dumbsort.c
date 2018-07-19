
#include "push_swap.h"


int		minval(t_stack *lst)
{
	int low;
	t_stack *tmp;

	tmp = lst;
	low = 2147483647;
	while(tmp != NULL)
	{
		if (tmp->pos < low)
			low = tmp->pos;
		tmp = tmp->next;
	}
	return (low);
}


void	movesmalltob(t_hold *node, char *cmd)
{
	int count;
	int min;
	int minloc;
	t_stack *a;


	count = node->size - 3;
	while(count > 0)
	{
		a = node->a;
		min = minval(node->a);
		minloc = maxposition(node->a, min, 0);
		if (a->pos == min)
		{
			pb(node, cmd, 1);
			count--;
		}
		else if (minloc >= node->size  / 2)
			rra(node, cmd, 1);
		else if (minloc < node->size  / 2)
			ra(node, cmd, 1);
		if (node->supcolour == 1)
			colouroutput(node, cmd);
	}
}

void	dumbsortbigger(t_hold *node, char *cmd)
{
	
	// int last;

	t_stack *b;


	movesmalltob(node, cmd);
	dumbsort(node, cmd);
	b = node->b;
	while (b != NULL)
	{
		pa(node, cmd, 1);
		if (node->supcolour == 1)
			colouroutput(node, cmd);
		if (issorted(node) == 1 && listsize(node->b) == 0)
			break;
	}


	// while (1)
	// {
	// 	a = node->a;
	// 	if (issorted(node) == 1 && listsize(node->b) == 0)
	// 		break;

	// }
	// last = lastlinkval(a);

}


void	dumbsort(t_hold *node, char *cmd)
{
	t_stack *a;
	if (listsize(node->a) <= 3)
	{
		while (1)
		{
			a = node->a;
			if (islistsorted(a, 'a') == 1)
				break;
			if (a->data < a->next->data)
				rra(node, cmd, 1);
			if (a->data > a->next->data)
				sa(node, cmd, 1);
			if (node->supcolour == 1)
				colouroutput(node, cmd);
		}
	}
	else
		dumbsortbigger(node, cmd);
}


// maxposition(t_stack *lst, int max, int totalrange)