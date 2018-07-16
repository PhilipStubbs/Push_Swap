#include "push_swap.h"

void	sorta(t_hold *node,t_stack *list, int mid, char *cmd)
{	
	// int last;

	t_stack *a;

	// a = list;
// 	last = lastlinkval(a);
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

	t_stack *a;
	t_stack *b;
	int mid;
	a = node->a;
	mid = node->size / 2;
	// printstack(node->a);
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
		// printf("[%s]\n",cmd );
		colouroutput(node, cmd);
		debugmode(node);

		i++;

	}
	return (1);
}
