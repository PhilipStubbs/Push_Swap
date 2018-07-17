#include "push_swap.h"

void 	findrange(int *crange, int totalrange, int leftover, int *nrange)
{
	crange[0] = ((totalrange-1) * 3)+leftover;
	crange[1] = (((totalrange) * 3)+leftover);
	if (crange[0] < 0)
		crange[0] = 0;
	if (crange[1] < 0)
		crange[1] = 0;
	*(nrange) = 0;

}

int		*findclosest(t_hold *node ,t_stack *list, int *crange)
{
	int		*ret;
	int		count;
	int		steps;
	t_stack	*a;

	ret = (int*)ft_memalloc(sizeof(int) * 3);
	ft_memset(ret, -1, 3);
	a = list;
	count = 0;
	steps = 0;
	while (a != NULL)
	{
		if (a->pos >= crange[0] && a->pos <= crange[1])
		{
			steps = count;
			if (count < node->size / 2 && steps < node->size / 2)
			{
				ret[0] = 1;
				ret[1] = a->data;
			}
			if (count == node->size / 2 )
			{
				ret[0] = -1;
				ret[1] = a->data;
			}
			if (count > node->size / 2 && (node->size - steps) < (steps < node->size / 2))
			{
				ret[0] = -1;
				ret[1] = a->data;
			}
			if (count == 0 || count == 1 || count == node->size || count == node->size -1)
				return (ret);
		}
		count++;
		a = a->next;
	}
	return (ret);
}

void	mergesorta(t_hold *node, char *cmd, int *crange, int *nrange)
{	
	// int last;
	int		*range;
	// int		lastsorted;
	t_stack *a;

	a = node->a;
	range = findclosest(node, a ,crange);
	printf("link = %d : %d\n", range[0], range[1]);
	(void)cmd;

	*(nrange) = 1;
	
	// last = lastlinkval(a);
	// if (a->pos <= mid && !(a->next->data < a->data))
	// {
	// 	ft_strcpy(cmd, "pb");
	// 	pb(node);
	// 	PB;
	// }

}

// void	sortb(t_hold *node,t_stack *lstb,t_stack *lsta, char *cmd)
// {	
// }

int		mergesort(t_hold *node)
{
	char	*cmd;
	t_stack	*a;
	t_stack	*b;
	int		totalrange;
	int		leftover;
	int		i;
	int		crange[2];
	int 	nrange;

	a = node->a;
	totalrange = node->size / 3;
	leftover = node->size % 3;
	cmd = (char*)ft_memalloc(sizeof(char) * 4);	
	printstack(a);
	// printf("%d : ",crange[0]);
	// totalrange--;
	// printf("%d\n",crange[1]);
	i = 0;
	// printf("%d\n",totalrange);
	nrange = 1;
	while (i < 10 )
	{
		if (nrange == 1)
		{
			findrange(crange, totalrange, leftover, &nrange);
			printf("%d : ",crange[0]);
			printf("%d",crange[1]);
		}

		// a = node->a;
		b = node->b;
		bzero(cmd, 4);
		if (issorted(node) == 1 && listsize(b) == 0)
			break;

		// if (a != NULL)
		mergesorta(node, cmd, crange ,&nrange);

// 
		// a = node->a;
		// printf("[%s]\n",cmd );
		colouroutput(node, cmd);
		debugmode(node);
		totalrange--;
		i++;

	}
	return (1);
}
/*
split the array by a range. put it int o b;
starting with the biggest.
split int o 3. if stack is 6 or less take the lower numbers
else we want to start at the largest numbers;

find the range needed and determain if we sort up or down.

sort b;

find the a part in a and put the sorted list back.

add the rest of the data back int o b and sort.

add back int o a when sorted.

sort in ranges.


*/
