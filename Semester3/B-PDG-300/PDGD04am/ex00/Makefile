##
## EPITECH PROJECT, 2024
## Paradigms Seminar
## File description:
## Makefile
##

SRC	=	z.c

OBJ	=	$(SRC:.c=.o)

NAME	=	z

CFLAGS	=	-Wall -Wextra -std=gnu17

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
