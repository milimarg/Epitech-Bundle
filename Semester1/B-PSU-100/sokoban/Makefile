##
## EPITECH PROJECT, 2022
## my_sokoban
## File description:
## Makefile
##

SRC	=	main.c	\
		file.c	\
		game.c	\
		map.c	\
		move.c	\
		init.c	\
		utils.c	\
		items.c	\
		sokoban.c	\
		display.c	\
		my_strdup.c	\
		my_strlen.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

all:
	gcc $(SRC) -c -g
	gcc $(OBJ) -o $(NAME) -lncurses

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
