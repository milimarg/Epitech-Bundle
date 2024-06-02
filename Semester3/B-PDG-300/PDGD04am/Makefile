##
## EPITECH PROJECT, 2024
## Paradigms Seminar
## File description:
## Makefile
##

SRC	=	ex01/mul_div.c \
		ex02/concat.c \
		ex03/array_1d_to_2d.c \
		ex04/print.c \
		ex05/sort.c \
		ex05/uniq.c \
		ex05/disp.c \
		tests/tests_MUL_DIV.c \
		tests/tests_CONCAT.c \
		tests/tests_1D_ARRAY_TO_2D_ARRAY.c \
		tests/tests_FUNCTION_POINTERS.c \
		tests/tests_ARRAYS.c

OBJ	=	$(SRC:.c=.o)

NAME	=	unit_tests

CFLAGS	=	-Wall -Wextra -std=gnu17 -lcriterion --coverage

all:


clean:
	rm -f $(OBJ)
	find . -name *.gcda -delete
	find . -name *.gcno -delete

fclean: clean
	rm -f $(NAME)

re: fclean all

tests_run: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS)
	./$(NAME)

.PHONY: all clean fclean re tests_run
