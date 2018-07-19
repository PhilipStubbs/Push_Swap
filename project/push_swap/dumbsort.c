
#include "push_swap.h"

void	dumbsort(t_hold *node, char *cmd)
{
	// int last;
	t_stack *a;

	while (1)
	{
		a = node->a;
		if (islistsorted(a, 'a') == 1)
			break;
		// last = lastlinkval(a);
		if (a->data < a->next->data)
			rra(node, cmd, 1);
		if (a->data > a->next->data)
			sa(node, cmd, 1);
		if (node->supcolour == 1)
			colouroutput(node, cmd);
	}
}