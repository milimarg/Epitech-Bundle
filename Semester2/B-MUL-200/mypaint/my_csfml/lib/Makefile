##
## EPITECH PROJECT, 2023
## my_csfml_container
## File description:
## Makefile
##

SRC	=	my_strlen.c \
		my_strcmp.c \
		my_strcat.c \
		my_strdup.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy-csfml-lib.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
