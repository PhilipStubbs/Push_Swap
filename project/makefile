
NAME = push_swap
NAMECH = checker

SRC = astackops.c \
	bstackops.c \
	combops.c \
	debugmode.c \
	endpop.c \
	listsize.c \
	malloctime.c \
	populatestack.c \
	searchandmalloc.c \
	startpop.c \

CHECK = get_commands.c \
	issorted.c \
	main_checker.c \

PUSH = main_push_swap.c \

OBJ = *.o

all: $(NAME)

$(NAME) :
	gcc -c -Wall -Werror -Wextra $(SRC) $(PUSH) $(CHECK)
	gcc -o $(NAMECH) $(OBJ) -I. -L. ../libft/libft.a
	rm -f $(OBJ)
	gcc -c -Wall -Werror -Wextra $(SRC) $(PUSH)
	gcc -o $(push_swap) $(OBJ) -I. -L. ../libft/libft.a
	rm -f $(OBJ)
	make re -C ../libft/


clean:
	rm -f $(OBJ)
	make clean -C ../libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C ../libft/

re: fclean all