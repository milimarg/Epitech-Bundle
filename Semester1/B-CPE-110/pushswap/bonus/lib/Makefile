##
## EPITECH PROJECT, 2022
## B-CPE-110-STG-1-1-pushswap-florent.guittre
## File description:
## Makefile
##

SRC	=	my_getnbr.c	\
		my_put_nbr.c	\
		my_strcmp.c	\
		my_strlen.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:
	gcc $(SRC) -c -g
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
