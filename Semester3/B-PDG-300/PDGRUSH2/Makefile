##
## EPITECH PROJECT, 2024
## Paradigms Seminar
## File description:
## Makefile
##

SRC	=	array.c \
		char.c \
		float.c \
		int.c \
		new.c \
		player.c \
		point.c \
		vertex.c \
		tests/tests_new.c \
		tests/tests_int.c \
		tests/tests_float.c \
		tests/tests_char.c \
		tests/tests_array.c \
		tests/tests_point.c \
		tests/tests_vertex.c

OBJ	=	$(SRC:.c=.o)

NAME	=	unit_tests

CFLAGS	=	-Wall -Wextra -std=gnu17 -lcriterion --coverage

all:


clean:
	rm -f $(OBJ)
	find . -name "*.gcda" -delete
	find . -name "*.gcno" -delete

fclean: clean
	rm -f $(NAME)

re: fclean all

tests_run: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS)
	./$(NAME)

.PHONY: all clean fclean re tests_run
