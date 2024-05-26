##
## EPITECH PROJECT, 2022
## Bootstrap_MyHunter
## File description:
## Makefile
##

SRC	=	main.c	\
		game.c	\
		constants.c	\
		spawn.c	\
		player.c	\
		my_intlen.c	\
		my_strlen.c	\
		my_strcmp.c	\
		events.c	\
		move.c	\
		display.c	\
		destroy.c	\
		duck_die_event.c	\
		sound.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

CSFML_ARGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:
	(cd ./my-csfml/ && make re && make clean)
	gcc $(SRC) -Wall -Wextra -c
	gcc $(OBJ) -g -o $(NAME) -L. -lmy-csfml $(CSFML_ARGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
