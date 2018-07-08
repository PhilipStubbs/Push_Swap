
#include "push_swap.h"

void	ft_intcpy(int *dest, const int *src, size_t n)
{
	int		*p1;
	int		*p2;
	int 	i;

	i = 0;

	p1 = dest;
	p2 = (int*)src;
	while (i <= (int)n)
	{
		*p1++ = *p2++;
		i++;
	}
}
