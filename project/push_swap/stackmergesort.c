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


// int		maxval(t_stack *tmp)
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

int		*findclosest(t_hold *node ,t_stack *list, int *crange)
{
	int		*ret;
	int		count;
	int		steps;
	int		size;
	t_stack	*a;

	ret = (int*)ft_memalloc(sizeof(int) * 3);
	ft_memset(ret, 0, 3);
	a = list;
	size = listsize(a);
	count = 0;
	steps = 0;
	// printf("listsize%d\n",listsize(a) );
	a = list;
	while (a != NULL)
	{
		if (a->pos > crange[0] && a->pos <= crange[1])
		{
			// printf(" START%d\n",crange[0] );
			steps = count;
			// printf("HERE%d, %d\n", steps , size / 2);
			if ( steps < size / 2)
			{
				ret[0] = 1;
				ret[1] = a->data;
			}
			// if (count == node->size / 2 )
			// {
			// 	ret[0] = -1;
			// 	ret[1] = a->data;
			// }
			// printf("HERE2 %d, %d\n", (size - steps) , size / 2);
			if (count >= node->size / 2) //|| (size - steps) < (steps < size / 2))
			{
				ret[0] = -1;
				ret[1] = a->data;
			}
			if (count == 0 || count == size )
				return (ret);
		}
		count++;
		a = a->next;
	}
	return (ret);
}
void	mergesortb(t_hold *node, char *cmd, int *nrange)
{	

	t_stack *b;
	// t_stack *a;
	int last;
	int	i;

	b = node->b;
	while (1)
	{
		b = node->b;
		last = lastlinkval(b);
		b = node->b;
		if (b->data < b->next->data)
		{
			ft_strcpy(cmd, "sb");
			sb(node);
			SB;
		}
		else if (b->data > last)
		{
			ft_strcpy(cmd, "rb");
			rb(node);
			RB;
		}
		else if (b->data > b->next->data && b->data < last)
		{
			ft_strcpy(cmd, "rrb");
			rrb(node);
			RRB;
		}
		b = node->b;
		if (islistsorted(b, 'b') == 1)
			break;
		colouroutput(node, cmd);
		bzero(cmd, 4);
	}
	i = 3;
	while (i > 0)
	{
		ft_strcpy(cmd, "pa");
		pa(node);
		PA;
		i--;
	}
	*(nrange) = 1;
}

void	mergesorta(t_hold *node, char *cmd, int *crange)
{	
	// int last;
	int		*range;
	// int		lastsorted;
	t_stack *a;

	a = node->a;
	range = findclosest(node, a ,crange);
	// printf("link = %d : %d\n", range[0], range[1]);
	// *(nrange) = 1;
	a = node->a;
	// last = lastlinkval(a);
	if (range[0] == -1 && listsize(node->b) < 3)
	{
		ft_strcpy(cmd, "rra");
		rra(node);
		RRA;
	}
	else if (a->data == range[1] && listsize(node->b) < 3)
	{
		ft_strcpy(cmd, "pb");
		pb(node);
		PB;
	}
	else if (range[0] == 1 && listsize(node->b) < 3)
	{
		ft_strcpy(cmd, "ra");
		ra(node);
		RA;
	}
	else if (node->b->data < node->b->next->data)
	{
		ft_strcpy(cmd, "sb");
		sb(node);
		SB;
	}
	
}

void	sortalessfive(t_hold *node, char *cmd)
{
	int last;
	int size;
	// int max;
	t_stack *a;
	// t_stack *b;

	a = node->a;
	// b = node->b;
	size = listsize(a);
	if (size <= 5)
	{
		if (size > 3)
		{
		ft_strcpy(cmd, "pb");
		pb(node);
		PB;
		}
		a = node->a;
		while (1)
		{
			if (islistsorted(a, 'a') == 1)
				break;
			a = node->a;
			last = lastlinkval(a);
			a = node->a;
			if (a->data < a->next->data)
			{
				ft_strcpy(cmd, "ra");
				rra(node);
				RRA;
			}
			else if (a->data > a->next->data)
			{
				ft_strcpy(cmd, "sa");
				sa(node);
				SA;
			}
			else if (a->data < last && a->data > a->next->data )
			{
				ft_strcpy(cmd, "ra");
				ra(node);
				RA;
			}
			// else if (b != NULL)
			// {

			// }

			a = node->a;

			colouroutput(node, cmd);
			bzero(cmd, 4);
		}

	}
}


int		stackmergesort(t_hold *node)
{
	char	*cmd;
	// t_stack	*a;
	t_stack	*b;
	int		totalrange;
	int		leftover;
	int		i;
	int		crange[2];
	int 	nrange;

	// a = node->a;
	totalrange = node->size / 3;
	leftover = node->size % 3;
	cmd = (char*)ft_memalloc(sizeof(char) * 4);	
	// printstack(a);
	i = 0;
	nrange = 1;
	while (i < 10)
	{
		// a = node->a;
		if (nrange == 1)
		{
			findrange(crange, totalrange, leftover, &nrange);
			// printf("%d : ",crange[0]);
			// printf("%d",crange[1]);
			totalrange--;
		}

		// a = node->a;
		b = node->b;
		bzero(cmd, 4);

			sortalessfive(node, cmd);

		if (issorted(node) == 1 && listsize(b) == 0)
			break;

		// if (a != NULL)
		// mergesorta(node, cmd, crange);
		if (listsize(b) == 3)
			mergesortb(node, cmd,&nrange);

// 
		// a = node->a;
		// printf("[%s]\n",cmd );
		colouroutput(node, cmd);
		debugmode(node);
		
		i++;

	}
	return (1);
}



/*


ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
ARG="0  13 4 7 9 11 8 6 1 10 2 14 5 3 16 12 15 -s";

rra goes down. things more than halfway use rra

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







stack a = 500
devide stack by 5. 
have 5 chunks.
100 ints per chunk

do i take the top 500? 

5 : put 2 into b; pb pb sa pa pa,

put tthe first chunk in b.
take out the biggest first until its empty.
new chunk = chunk - (a chunk / 5); eg 100 - (100 / 5) = 80;

throw 80 into b.
pull the biggest out first.


repeat;

have a min value of 4.
*/


























