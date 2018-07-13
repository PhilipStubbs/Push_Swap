
NAME = checker.out

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

CHECK = get_commands.c \
	issorted.c \
	main_checker.c \

OBJ = *.o

all: $(NAME)

$(NAME) :
	make -C ../libft/
	gcc -c -Wall -Werror -Wextra $(SRC) $(CHECK) -I../includes/
	gcc -o $(NAME) $(OBJ) -I../includes/ -L. ../libft/libft.a
	rm -f $(OBJ)
	# mv -f $(NAME) ../
	@echo "checker.out done" 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all