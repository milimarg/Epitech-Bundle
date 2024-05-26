##
## EPITECH PROJECT, 2022
## CPOOL_mini_printf
## File description:
## Makefile_bonus
##

SRC		=	main.c			\
			miniprintf.c	\
			vabs_list.c		\
			lib.c

OBJ		=	$(SRC:.c=.o)

NAME	=	mini_printf

all:
	(cd .. && gcc -c $(SRC))
	(cd .. && gcc -o $(NAME) $(OBJ))

clean:
	(cd .. && rm -f $(OBJ))

fclean: clean
	(cd .. && rm -f $(NAME))

re:	fclean all
