#include "push_swap.h"


void	printstack(t_stack *list)
{
	t_stack *tmp;

	tmp = list;

	while (tmp != NULL)
	{
		printf("(%d:[%d])\n",tmp->pos, tmp->data);
		tmp = tmp->next;
	}
}

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
	if (a->pos <= mid && !(a->next->data < a->data))
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
	
	else if (a->data > last)
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
	b = lstb;
	if(b->next != NULL)
	{
	 if (b->next->data < b->data)
		{
			ft_strcpy(cmd, "sb");
			sb(node);
			SB;
		}
	}
	
	else if (b->data > last)
	{
		ft_strcpy(cmd, "rrb");
		rrb(node);
		RRB;
	}
	else if (last > b->data && islistsorted(b, 'b') != 1)
	{
		ft_strcpy(cmd, "rb");
		rb(node);
		RB;
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
// ARG="1 3 5 2 0 4"; ./push_swap.out $ARG
	mid = node->size / 2;
	// printf("%d\n",mid );
	printstack(node->a);
	cmd = (char*)ft_memalloc(sizeof(char) * 4);	
	int i = 0;
	while (i < 15 )
	{
		a = node->a;
		b = node->b;
		bzero(cmd, 4);
		if (issorted(node) == 1 && listsize(b) == 0)
			break;


		if (a != NULL)
			sorta(node, a, mid, cmd);
		a = node->a;


		if (b != NULL)
			sortb(node, b, a, cmd);
		b = node->b;


		// printf("[%s]\n",cmd );
		colouroutput(node, cmd);
		debugmode(node);

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