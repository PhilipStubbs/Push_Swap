#include "push_swap.h"

int		middlevalue(t_stack *list, int size)
{
	t_stack *tmp;
	int	av;

	av = 0;

	tmp = list;
	while (tmp != NULL)
	{
		av += tmp->pos;
		tmp = tmp->next;
	}
	return (av / size);
}

void	sorta(t_hold *node,t_stack *list, int mid, char *cmd)
{	
	int last;

	t_stack *a;

	a = list;
	last = lastlinkval(a);
	if (a->pos < mid)
	{
		ft_strcpy(cmd, "pb");
		pb(node);
		// PB;
	}
	a = list;
	// if (a->next != NULL)
	// {
		if (a->next->pos < a->pos)
		{
			printf("%d : %d\n",a->next->data, a->data );
			ft_strcpy(cmd, "sa");
			sa(node);
			// SA;
		}
	// }
	a = list;
	if (a->pos > last)
	{
		ft_strcpy(cmd, "rra");
		rra(node);
		// RRA;
	}
}

void	sortb(t_hold *node,t_stack *b,t_stack *a, char *cmd)
{	
	int last;
	int size;

	last = lastlinkval(b);
	size = listsize(b);
	printf("%d\n", size);
	if (b->pos < a->pos && size > 1)
	{	
		ft_strcpy(cmd, "pa");
		pa(node);
		// PA;

	}
	if (b->next != NULL && size > 1)
	{
		if (b->next->pos < b->pos)
		{
			ft_strcpy(cmd, "sb");
			sb(node);
			// SB;
		}
	}
	if (b->pos > last && size > 1)
	{
		ft_strcpy(cmd, "rrb");
		rrb(node);
		// RRB;
	}
	// else
	// {
	// 	ft_strcpy(cmd, "ra");
	// 	ra(node);
	// 	// RA;
	// }
}


int		sortinhalfs(t_hold *node)
{
	char	*cmd;

	t_stack *a;
	t_stack *b;
	int mid;
	a = node->a;

	mid = node->size / 2;
	printf("%d\n",mid );

	cmd = (char*)ft_memalloc(sizeof(char) * 4);	
	int i = 0;
	while (i < 5)
	{
		a = node->a;
		b = node->b;
		bzero(cmd, 4);

		if (a != NULL)
			sorta(node, a, mid, cmd);
		if (b != NULL)
			sortb(node, b, a, cmd);
		
		printf("[%s]\n",cmd );
		colouroutput(node, cmd);
		debugmode(node);
		if (issorted(node) == 1) //&& listsize(b) == 0)
			break;
		i++;

	}
	return (1);
}

/*
if less that mid move to b;
check if 2 is bigger that 1;
if it is sa;
check if 1 is bigger than last;
if it is rra;
check if 1 is smaller than last && is smaller than mid;
if it is ra and pb
*/