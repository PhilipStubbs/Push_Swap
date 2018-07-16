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
	if (a->pos <= mid)
	{
		ft_strcpy(cmd, "pb");
		pb(node);
		PB;
	}
	// a = list;
	// if (a->next != NULL)
	// {

	else if (a->next->data < a->data)
		{
			ft_strcpy(cmd, "sa");
			sa(node);
			SA;
		}
	// }
	
	else if (a->pos > last)
	{
		ft_strcpy(cmd, "rra");
		rra(node);
		RRA;
	}
	else if (last > a->data && islistsorted(a, 'a') != 1)
	{
		ft_strcpy(cmd, "ra");
		ra(node);
		RA;
	}
}

void	sortb(t_hold *node,t_stack *lstb,t_stack *lsta, char *cmd)
{	
	int last;
	int size;
	t_stack *a;
	t_stack *b;

	a = lsta;
	b = lstb;
	last = lastlinkval(b);
	size = listsize(b);
	if (islistsorted(a, 'a') == 1 && islistsorted(b, 'b') == 1)
	{	
		while (size--)
		{
			ft_strcpy(cmd, "pa");
			pa(node);
			PA;
		}

	}
	else if (b->next != NULL && size > 1)
	{
		if (b->next->pos > b->pos)
		{
			ft_strcpy(cmd, "sb");
			sb(node);
			SB;
			colouroutput(node, cmd);
		}
	}
	else if (b->pos > last && size > 1)
	{
		ft_strcpy(cmd, "rrb");
		rrb(node);
		RRB;
	}

}

// "0 1 2 4 3"
int		sortinhalfs(t_hold *node)
{
	char	*cmd;

	t_stack *a;
	t_stack *b;
	int mid;
	a = node->a;

	mid = node->size / 2;
	// printf("%d\n",mid );

	cmd = (char*)ft_memalloc(sizeof(char) * 4);	
	int i = 0;
	while (1)
	{
		a = node->a;
		b = node->b;
		bzero(cmd, 4);

		a = node->a;
		if (a != NULL)
			sorta(node, a, mid, cmd);
		a = node->a;
		if (b != NULL)
			sortb(node, b, a, cmd);
		b = node->b;
		// printf("[%s]\n",cmd );
		colouroutput(node, cmd);
		debugmode(node);
		if (issorted(node) == 1 && listsize(b) == 0)
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