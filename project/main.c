

#include "push_swap.h"


int		main(int arc, char **arv)
{
	t_hold	*node;

	(void)arc;
	node = malloctime();

	char **ret;
	int i = 0;

	ret = ft_split("45 6 8 87 fhelo   ");
	while (ret[i])
		printf("%s\n", ret[i++]);

	(void)arv;
	// if (searchandmalloc(arv, node, arc) == 0)
		// return (0);
	// popstack(arv, node);

	// debugmode(node);
	// printf("size:[%d]	debug:[%d]	colour:[%d]\n",node->size, node->debug, node->colour);
	return (1);

}