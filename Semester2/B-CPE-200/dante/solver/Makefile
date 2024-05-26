##
## EPITECH PROJECT, 2023
## B-CPE-200-STG-2-1-dante-noam.nedjar
## File description:
## Makefile
##

SRC	=	solver.c \
		my_str_to_word_array.c \
		solver_utils.c \
		my_str_to_word_array_destroy.c \
		../common.c

OBJ	=	$(SRC:.c=.o)

NAME	=	solver

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
