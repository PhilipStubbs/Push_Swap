
#include "push_swap.h"


int		main(int arc, char **arv)
{
	t_hold	*node;

	(void)arc;
	node = malloctime();
	if (searchandmalloc(arv, node) == 0)
		return (0);
	popstack(arv, node);

	debugmode(node);
	printf("size:[%d]	debug:[%d]	colour:[%d]\n",node->size, node->debug, node->colour);
	return (1);

}