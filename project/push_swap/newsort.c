
#include "push_swap.h"

int		maxposition(t_hold *node, int max, int totalrange)
{	
	int count;
	int lower;
	t_stack *a;


	count = 0;
	a = node->a;
	lower = max-totalrange;
	if (lower < 0)
		lower = 0;
	while(a != NULL)
	{
		if ((a->pos >= lower && a->pos <= max))
		{
			return(count);
		}
		// if (a->pos >= max-totalrange && a->pos <= max)
		// 	return (count);
		a = a->next;
		count++;
	}
	// printf("INSED%d\n",count );
	return (count);
}

int		closestsmaxval(t_stack *tmp, int totalrange)
{
	int hi;
	int	low;
	t_stack *a;

	hi = -2147483648;
	a = tmp;
	
	while(a != NULL)
	{
		if (a->pos > hi)
			hi = a->pos;
		a = a->next;
	}
	a = tmp;
	low = hi - totalrange;
	while(a != NULL)
	{
		if ((a->pos >= low && a->pos <= hi))
		{
			return(a->data);
		}
		a = a->next;
	}

	return (0);
}

void	movea(t_hold *node,int totalrange, int size, char *cmd)
{
	int count;
	int	closestmaxint;
	int	maxpos;
	t_stack *tmp;

	count = totalrange;
	tmp = node->a;
	closestmaxint = closestsmaxval(tmp, totalrange);
	maxpos = maxposition(node, closestmaxint, totalrange);
	while (count && tmp != NULL)
	{
		closestmaxint = closestsmaxval(tmp, totalrange);
		maxpos = maxposition(node ,closestmaxint, totalrange);
		
		// printf("%d\n",closestmaxint);
		// printf("%d %d\n",maxpos, size/2 );
		if (tmp->data == closestmaxint)
		{
			ft_strcpy(cmd, "pb");
			pb(node);
			PB;
			count--;
			tmp = node->a;


			

		}

		else if (maxpos >= size / 2)
		{
			ft_strcpy(cmd, "rra");
			rra(node);
			RRA;
		}

		else if (maxpos < size / 2)
		{
			ft_strcpy(cmd, "ra");
			ra(node);
			RA;
		}
		
		tmp = node->a;
		colouroutput(node, cmd);
	}
	// ft_strcpy(cmd, "pb");
	// pb(node);
	// PB;
}

int		newsort(t_hold *node)
{
	char	*cmd;
	t_stack	*a;
	// t_stack	*b;
	int		i;
	int		size;
	int		newrange;
	int		totalrange;

	a = node->a;
	cmd = (char*)ft_memalloc(sizeof(char) * 4);	
	// printstack(a);
	i = 0;
	newrange = 1;
	// totalrange = 0;
	while (i < 10)
	{
		a = node->a;
		// 
		size = listsize(a);
		if (newrange == 1)
		{	if (totalrange != 0)
				totalrange = totalrange - (totalrange / 5);
			else
				totalrange = node->size / 5;
			if (totalrange < 5)
				totalrange = 4;
		}
		movea(node, totalrange, size, cmd);
		// b = node->b;
		bzero(cmd, 4);

		// colouroutput(node, cmd);
		debugmode(node);
		
		i++;

	}
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

