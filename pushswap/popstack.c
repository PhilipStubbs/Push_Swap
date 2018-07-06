
#include "push_swap.h"

int		popstack(char **str, t_hold *node)
{
	int	i;
	int	dx;

	i = 0;

	while (str[i])
	{
		dx = 0;
		while (ft_isspace(str[i][dx]) == 1)
			dx++;
		node->a->stack[i] = atoi(str[i + dx]);
		// printf("%s\n", str[i]);
		i++;
	}
	return (i);
}