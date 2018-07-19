
#include "push_swap.h"

int		maxposition(t_stack *lst, int max, int totalrange)
{	
	int count;
	int lower;
	t_stack *a;

	count = 0;
	a = lst;
	lower = max-totalrange;
	if (lower < 0)
		lower = 0;
	while(a != NULL)
	{
		if ((a->pos > lower && a->pos <= max))
		{
			return(count);
		}
		a = a->next;
		count++;
	}
	return (count);
}

int		closestsmaxval(t_stack *tmp, int totalrange, int hi)
{
	// int hi;
	int	low;
	t_stack *a;

	a = tmp;
	low = hi - totalrange;
	if (low < 0)
		low = 0;
	while(a != NULL)
	{
		if ((a->pos > low && a->pos <= hi))
		{
			return(a->data);
		}
		a = a->next;
	}

	return (0);
}
int		maxval(t_stack *lst)
{
	int hi;
	t_stack *tmp;

	tmp = lst;
	hi = -2147483648;
	while(tmp != NULL)
	{
		if (tmp->pos > hi)
			hi = tmp->pos;
		tmp = tmp->next;
	}
	return (hi);
}


void	movea(t_hold *node,int totalrange, int size, char *cmd)
{
	int count;
	int	closestmaxint;
	int	maxpos;
	int	hi;
	t_stack *tmp;

	count = totalrange;
	tmp = node->a;
	hi = maxval(tmp);
	closestmaxint = closestsmaxval(tmp, totalrange, hi);
	maxpos = maxposition(node->a , closestmaxint, totalrange);
	while (count && tmp != NULL)
	{
		if (node->supcolour == 1)
			colouroutput(node, cmd);
		if (tmp->data == closestmaxint)
		{
			pb(node, cmd, 1);
			count--;
			tmp = node->a;
			closestmaxint = closestsmaxval(tmp, totalrange, hi);
			maxpos = maxposition(node->a ,closestmaxint, totalrange);
		}
		else if (maxpos >= size / 2)
			rra(node, cmd, 1);

		else if (maxpos < size / 2)
			ra(node, cmd, 1);
		tmp = node->a;
		if (node->supcolour == 1)
			colouroutput(node, cmd);
		debugmode(node);
	}
}

void	sortbackin(t_hold *node, char *cmd)
{
	t_stack *b;
	int	maxint;
	int	ctoint;
	int		size;

	b = node->b;
	size = listsize(b);
	maxint = maxval(b);
	ctoint = maxposition(b , maxint, 1);
	while (b != NULL)
	{
		if (b->pos == maxint)
		{
			pa(node, cmd, 1);
			b = node->b;
			size = listsize(b);
			maxint = maxval(b);
			ctoint = maxposition(b , maxint, 1);
		}
		else if (ctoint >= size / 2)
			rrb(node, cmd, 1);
		else if (ctoint < size / 2)
			rb(node, cmd, 1);
		if (node->supcolour == 1)
			colouroutput(node, cmd);
		debugmode(node);
		b = node->b;
	}
}

void	settotalrange(int *totalrange, t_hold *node)
{
	if (*totalrange != 0)
		*totalrange = *totalrange - (*totalrange / 5);
	else
		*totalrange = node->size / 5;
	if (*totalrange < 5)
		*totalrange = 4;
}

int		newsort(t_hold *node)
{
	char	*cmd;
	t_stack	*a;
	int		size;
	int		totalrange;

	cmd = (char*)ft_memalloc(sizeof(char) * 4);
	totalrange = 0;
	if (node->size <= 5)
		dumbsort(node ,cmd);
	while (1)
	{
		a = node->a;
		if (a == NULL)
			sortbackin(node, cmd);
		if (issorted(node) == 1 && listsize(node->b) == 0)
			break;
		size = listsize(a);
		settotalrange(&totalrange, node);
		movea(node, totalrange, size, cmd);
	}
	if (node->colour == 1)
		colouroutput(node, cmd);
	return (1);
}


/*

stack a = 500
devide stack by 5. 
have 5 chunks.
100 int per chunk
move int o all 100 int o b.
that 100 would be 400 -> 499



put tthe first chunk in b.

new chunk = chunk - (a chunk / 5); eg 100 - (100 / 5) = 80;

throw 80 int o b.
would be 320 -> 399;


repeat;

have a min value of 4.

only pull out of B when a == NULL;
starting at biggest.

5 : put 2 int o b; pb pb sa pa pa,
*/


// ARG="74 88 55 16 30 99 44 80 58 62 37 18 56 98 6 17 79 47 95 29 2 12 67 15 4 51 81 0 50 75 31 13 76 22 19 92 68 54 39 94 59 91 63 49 97 33 34 65 3 73 72 61 42 93 41 53 70 52 21 45 36 27 85 11 32 14 66 86 38 78 89 64 90 1 35 82 24 71 77 8 9 69 28 83 10 87 96 43 25 48 60 46 20 40 57 5 7 26 84 23 -s"; ./push_swap.out $ARG
