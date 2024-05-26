##
## EPITECH PROJECT, 2022
## B-CPE-110-STG-1-1-pushswap-florent.guittre
## File description:
## Makefile
##

SRC	=	main.c	\
		util.c \
		move_util.c	\
		basic_handler.c	\
		init.c	\
		parsing.c

OBJ	=	$(SRC:.c=.o)

NAME	=	push_swap

all:
	make -C ./lib/
	gcc $(SRC) -c -g
	gcc $(OBJ) -o $(NAME) -L./lib/ -lmy

clean:
	make clean -C ./lib/
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./lib/
	rm -f $(NAME)

re: fclean all
