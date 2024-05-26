##
## EPITECH PROJECT, 2022
## my_ls
## File description:
## Makefile_libmya
##

SRC	=	my_char_isalpha.c		\
		my_intlen.c				\
		my_put_nbr.c			\
		my_putchar.c			\
		my_putstr.c				\
		my_strlen.c				\
		my_strcat.c				\
		my_intlen.c				\
		my_swap.c				\
		my_strdup.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:
	gcc -c $(SRC) && ar rc $(NAME) $(OBJ)
	mv $(NAME) ../../

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f ../../$(NAME)

re:	fclean all
