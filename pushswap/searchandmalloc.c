
#include "push_swap.h"

void	mallocstacks(t_hold *node, int size)
{
	node->a->stack = (int*)ft_memalloc(sizeof(int) * size);
	node->b->stack = (int*)ft_memalloc(sizeof(int) * size);
}
int	ft_isspace(char c)
{
	if ((c == '\n') || (c == '\t') || (c == '\v') ||
		(c == ' ') || (c == '\f') || (c == '\r'))
		return (1);
	else
		return (0);
}

int		isvalid(char *str, t_hold *node)
{
	int	i;

	i = 0;
	while(str[i])
	{
		while (ft_isspace(str[i]) == 1)
			i++;
		if (str[i] != '-' && !(str[i] >= '0' && str[i] <= '9'))
		{
			if (str[i] == 'v' && str[i - 1] == '-')
			{
				node->debug = 1;
				return (1);
			}
			if (str[i] == 'c' && str[i - 1] == '-')
			{
				node->colour = 1;
				return (1);
			}
			else
				return (0);
		}
		i++;
	}
	return (i);
}

int		searchandmalloc(char **str, t_hold *node)
{
	int	i;

	i = 1;
	while (str[i] != NULL)
	{
		if (isvalid(str[i], node) == 0)
		{
			ERROR;
			return (0);
		}
		i++;
	}
	i -= (1 + node->debug + node->colour);
	node->size = i;
	mallocstacks(node, i);

	return (i);
}