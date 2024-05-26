##
## EPITECH PROJECT, 2023
## B-CPE-200-STG-2-1-dante-noam.nedjar
## File description:
## Makefile
##

SRC	=	generator.c \
		lib.c \
		generator_utils.c \
		../common.c

OBJ	=	$(SRC:.c=.o)

NAME	=	generator

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) -g

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
