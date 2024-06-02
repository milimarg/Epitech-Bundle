##
## EPITECH PROJECT, 2024
## Paradigms Seminar
## File description:
## Makefile
##

SRC	=	string.c \
		assign.c \
		append.c \
		at.c \
		clear.c \
		length.c \
		compare.c

TESTS = tests/tests_string.c \
		tests/tests_assign.c \
		tests/tests_append.c \
		tests/tests_at.c \
		tests/tests_clear.c \
		tests/tests_length.c \
		tests/tests_compare.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libstring.a

TEST    =    unit_tests

CFLAGS    =    -std=gnu17 -Wall -Wextra

CRITERION    =    --coverage -lcriterion

all:    $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f *.o
	find . -name "*.gcno" -delete
	find . -name "*.gcda" -delete

fclean:    clean
	rm -f $(TEST)
	rm -f $(NAME)

re:    fclean all

tests_run: $(TEST)

$(TEST): $(SRC) $(TESTS)
	gcc -o $(TEST) $(SRC) $(TESTS) $(CFLAGS) $(CRITERION)

.PHONY: re clean fclean all tests_run
