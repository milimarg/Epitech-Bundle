##
## EPITECH PROJECT, 2024
## Panoramix
## File description:
## Makefile
##

SRC		=	src/main.c

OBJ		=	$(SRC:.c=.o)
NAME	=	panoramix

CFLAGS	=	-Wall -Wextra -g

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
