
NAME = project

all: $(NAME)

$(NAME) :
	make -C libft/
	make -C checker/
	make -C push_swap/

clean:
	make clean -C checker/
	make clean  -C push_swap/
	

fclean: clean
	make fclean -C checker/
	make fclean  -C push_swap/

lib: 
	make re -C libft/

re: fclean all