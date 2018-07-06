
#include "push_swap.h"

void	mallocstacks(t_hold *node, int size)
{
	node->a->stack = (int*)ft_memalloc(sizeof(int) * size);
	node->b->stack = (int*)ft_memalloc(sizeof(int) * size);
}

int		isflag(char *s, t_hold *node)
{	
	int i;

	i = 0;
	if (s[i] == '-' && s[i + 1] == 'v')
	{
		node->debug = 1;
		return (1);
	}
	if (s[i] == '-' && s[i + 1] == 'c')
	{
		node->colour = 1;
		return (1);
	}
	return (0);
}

int		isvalid(char *s, t_hold *node)
{
	int	i;

	i = 0;
	while(s[i])
	{
		while (ft_isspace(s[i]) == 1 && s[i] != '\0')
			i++;
		if (s[i] == '-' && !(s[i] >= '0' && s[i] <= '9') && s[i] != '\0')
		{
			if (isflag(s + i, node) == 1)
				return (1);
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