# ifndef PUSH_SWAP_h
# define PUSH_SWAP_h
# define ERROR ft_putendl("Error");
# include "../libft/libft.h"

#include <stdio.h>

typedef	struct		s_stack
{
	int				*stack;
	int				size;
	int				loc;
}					t_stack;

typedef	struct		s_pushswap
{
	t_stack			*a;
	t_stack			*b;
	char			**raw;
	int				loc;
	int				size;
	int				debug;
	int				colour;
}					t_hold;

t_hold				*malloctime(void);
int					searchandmalloc(char **str, t_hold *node, int arc);
int					popstack(char **str, t_hold *node);
void				debugmode(t_hold *node);

#endif
