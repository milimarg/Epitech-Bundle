##
## EPITECH PROJECT, 2022
## BSQ
## File description:
## Makefile
##

SRC	=	main.c	\
		map.c	\
		file.c	\
		modify_map.c	\
		calc.c	\
		lib.c	\
		convert_string_to_int.c	\
		my_strlen.c	\
		map_generator.c

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

all:
	gcc $(SRC) -c
	gcc $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
