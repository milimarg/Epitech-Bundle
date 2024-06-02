##
## EPITECH PROJECT, 2024
## Paradigms Seminar
## File description:
## Makefile
##

SRC	=	StupidUnitConverter.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	StupidUnitConverter

CFLAGS	=	-Wall -Wextra -std=c++20

all: $(NAME)

$(NAME): $(OBJ)
	g++ $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
