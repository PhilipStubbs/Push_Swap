
#include "push_swap.h"

// int		max(t_stack *tmp)
// {
// 	int hi;

// 	hi = -2147483648;
// 	while(tmp != NULL)
// 	{
// 		if (tmp->data > hi)
// 			hi = tmp->data;
// 		tmp = tmp->next;
// 	}
// 	return (hi);
// }

int		min(t_stack *tmp)
{
	int	low;

	low = 2147483647;
	while(tmp != NULL)
	{
		if (tmp->data < low)
			low = tmp->data;
		tmp = tmp->next;
	}
	return (low);
}

int		minpos(t_stack *tmp, int min)
{	
	int count;

	count = 0;
	while(tmp != NULL)
	{
		if (tmp->data != min)
			return (count);
		tmp = tmp->next;
		count++;
	}
	return (count);
}

int		simplerotatesort(t_hold *node)
{	
	char	*cmd;
	t_stack *a;
	t_stack *b;
	int	low;
	int last;
	int	amid;
	int	aminpos;
	cmd = (char*)ft_memalloc(sizeof(char) * 4);	
	
	a = node->a;
	b = node->b;
	low = min(a);

	while (1)
	{
		a = node->a;
		b = node->b;
		amid = (listsize(a)/2);
		low = min(a);
		aminpos = minpos(a, low);
		bzero(cmd, 4);
		last = lastlinkval(a);
		if (a != NULL)
		{
			if (a->data == low)
			{
				
				ft_strcpy(cmd, "pb");
				pb(node);
				PB;
			}
			if (aminpos <= amid)
			{
				ft_strcpy(cmd, "ra");
				ra(node);
				RA;
			}
			if (aminpos > amid)
			{
				ft_strcpy(cmd, "rra");
				rra(node);
				RRA;
			}
		}
		else if (b != NULL && a == NULL)
		{	
		
			last = 0;
			while (last < node->size)
			{
				ft_strcpy(cmd, "pa");
				pa(node);
				PA;
				last++;
			}

			
		}

		// write(1, "2\n", 2);
		// write(1, "6\n", 2);

		colouroutput(node, cmd);
		debugmode(node);
		if (issorted(node) == 1)
			break;
	}

	
	return (1);
}
