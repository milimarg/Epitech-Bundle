##
## EPITECH PROJECT, 2022
## CPOOL_Day13
## File description:
## Makefile_task01
##

SRC		=	main.c			\
			display_window.c	\
			framebuffer_create.c	\
			put_pixel.c

OBJ		=	$(SRC:.c=.o)

NAME		=	task02

BLD_CSFML	=	-lcsfml-graphics -lcsfml-window

BLD_LIB		=	-L../lib/my/ -lmy

all:
	(cd ../lib/my/ && make && make clean)
	gcc -c $(SRC)
	gcc $(OBJ) -o $(NAME) -lcsfml-graphics $(BLD_CSFML) $(BLD_LIB)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
