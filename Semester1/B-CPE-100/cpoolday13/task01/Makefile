##
## EPITECH PROJECT, 2022
## CPOOL_Day13
## File description:
## Makefile_task01
##

SRC		=	main.c		\
			display_window.c

OBJ		=	$(SRC:.c=.o)

NAME		=	task01

BLD_CSFML	=	-lcsfml-graphics -lcsfml-window

BLD_LIB		=	-L../lib/my/ -lmy

all:
	(cd ../lib/my/ && make && make clean)
	gcc -c $(SRC)
	gcc $(OBJ) -o $(NAME) $(BLD_CSFML) $(BLD_LIB)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
