##
## EPITECH PROJECT, 2022
## my_ls
## File description:
## Makefile_libmya
##

SRC	=	animation.c	\
		destroy.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy-animation.a

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
