##
## EPITECH PROJECT, 2023
## B-MAT-200-STG-2-1-106bombyx-florent.guittre
## File description:
## Makefile
##

SRC	=	mandelbrot.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mandelbrot

CFLAGS	=	-Wall -Wextra

CSFML_FLAGS	=	-lcsfml-graphics

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS) $(CSFML_FLAGS) -lm

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
