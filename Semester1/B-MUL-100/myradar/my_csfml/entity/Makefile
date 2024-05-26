##
## EPITECH PROJECT, 2022
## B-MUL-100-STG-1-1-myradar-florent.guittre
## File description:
## Makefile
##

SRC	=	entity.c	\
		extra_lib.c	\
		destroy.c	\
		ootb.c	\
		entity_animation.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy-entity.a

CSFML_ARGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system

all:
	gcc -c $(SRC) $(CSFML_ARGS)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f ../$(NAME)

re:	fclean all
