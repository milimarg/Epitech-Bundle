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
		bonus.c	\
		lib.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

NCURSES	=	-lncurses

CSFML	=	-lcsfml-audio

all:
	gcc $(SRC) -c -g
	gcc $(OBJ) -o $(NAME) -g $(NCURSES) $(CSFML)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
