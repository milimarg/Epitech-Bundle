##
## EPITECH PROJECT, 2022
## B-MUL-100-STG-1-1-myradar-florent.guittre
## File description:
## Makefile
##

SRC	=	main.c	\
		game.c	\
		file.c	\
		lib.c	\
		init.c	\
		display.c	\
		move.c	\
		time.c	\
		math.c	\
		parsing_help.c	\
		collision.c	\
		utils.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_radar

MY_FLAGS	=	-lmy-animation -lmy-entity -lmy-window

CSFML_FLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system

MATHS	=	-lm

all:
	make -C ./my_csfml/animation/
	make -C ./my_csfml/entity/
	make -C ./my_csfml/window/
	gcc $(SRC) -c -g -Wall -Wextra
	gcc $(OBJ) -o $(NAME) -L./my_csfml/ $(MY_FLAGS) $(CSFML_FLAGS) $(MATHS)

clean:
	make clean -C ./my_csfml/animation/
	make clean -C ./my_csfml/entity/
	make clean -C ./my_csfml/window/
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./my_csfml/animation/
	make fclean -C ./my_csfml/entity/
	make fclean -C ./my_csfml/window/
	rm -f $(NAME)

re: fclean all
