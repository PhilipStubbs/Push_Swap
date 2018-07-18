
NAME = push_swap.out

SRC = ../src/astackops.c \
	../src/bstackops.c \
	../src/colouroutput.c \
	../src/combops.c \
	../src/debugmode.c \
	../src/endpop.c \
	../src/listsize.c \
	../src/malloctime.c \
	../src/populatestack.c \
	../src/searchandmalloc.c \
	../src/startpop.c \
	../src/issorted.c \

PUSH = main_push_swap.c \
	simplerotatesort.c \
	lastlinkval.c \
	sortinhalfs.c \
	normlize.c \
	stackmergesort.c \
	newsort.c \

OBJ = *.o

all: $(NAME)

$(NAME) :
	make -C ../libft/
	gcc -c -Wall -Werror -Wextra $(SRC) $(PUSH) -I../includes/
	gcc -o $(NAME) $(OBJ) -I../includes/ -L. ../libft/libft.a
	rm -f $(OBJ)
	mv -f $(NAME) ../
	@echo "push_swap.out done" 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all