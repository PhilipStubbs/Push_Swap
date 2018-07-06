
#include "push_swap.h"

int		popstack(char **str, t_hold *node)
{
	int	i;
	int	dx;
	int	sti;

	i = 1;
	sti = 0;

	while (str[i])
	{
		dx = 0;
		while (ft_isspace(str[i][dx]) == 1)
			dx++;

		if (!(str[i][dx] == '-' && str[i][dx + 1] == 'v'))
		{
			node->a->stack[sti] = ft_atoi(str[i]);
			sti++;
		}		
		i++;
	}
	return (i);
}