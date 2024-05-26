##
## EPITECH PROJECT, 2022
## B-CPE-110-STG-1-1-pushswap-florent.guittre
## File description:
## Makefile
##

SRC	=	main.c	\
		my_getnbr.c	\
		util.c \
		push_util.c	\
		swap_util.c	\
		rotate_util.c	\
		anti_rotate_util.c	\
		basic_handler.c	\
		init.c

OBJ	=	$(SRC:.c=.o)

NAME	=	push_swap

all:
	gcc $(SRC) -c -g
	gcc $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
