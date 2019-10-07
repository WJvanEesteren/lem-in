NAME = ./lem-in

SRC = main.c get_next_line.c extras.c iterate_list.c linker.c hash.c path_finder.c

INCL = lem_in.h

LIB = -L ./LIBFT/ -lft

all: $(NAME)

$(NAME):
	@make -C LIBFT/
	@echo COMPILING LEM_IN
	@gcc -o $(NAME) $(SRC) -I $(INCL) $(LIB) -Wall -Wextra -Werror -g

clean:
	@make -C ./LIBFT/ clean

fclean: clean
	@make -C ./LIBFT/ fclean
	@echo DELETING LEM_IN
	@rm $(NAME)

re: fclean all
