##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC	=	main.c \
		src/count.c \
		src/error.c \
		src/move.c  \
		src/my_sokoban.c \
		src/print.c \
		src/exec_move.c \
		src/set_struct.c \
		src/game_end.c \
		src/struct_count.c

NAME =	my_sokoban

CFLAGS = -Wall -Wextra -Werror


all:	$(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(SRC) $(CFLAGS) -lncurses
	@echo "all done"
clean:
	rm -f $(NAME)
	@echo "all clean"

fclean: clean

re:	$(NAME)