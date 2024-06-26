##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile template
##

###### PARAMETERS #####
SRC=$(wildcard src/*.c)
BINARY=navy
OBJ=$(SRC:.c=.o)
CC=gcc
AR=ar rc
CFLAGS+=-W -Wall -I./include -pedantic -ansi -std=gnu99
UNIT_TESTS_FILES=*.gcno *.gcna *.gcda coverage.info *.c.gcda *.c.gcov
LIBS=-lcriterion -fprofile-arcs -ftest-coverage

##### EXEC #####
all: $(BINARY)

$(BINARY): $(OBJ)
	@make -C lib/my all
	@$(CC) $(OBJ) -Llib/my/ -lmy -Iinclude/ -o $(BINARY)

clean:
	@make -C lib/my clean
	@rm -f $(OBJ) *~ *# unit_tests $(UNIT_TESTS_FILES)

fclean: clean
	@make -C lib/my fclean
	@rm -f $(BINARY)

re: fclean all

unit_tests: all
	@$(CC) $(OBJ) lib/my/*.c tests/*.c -L./lib/my -lmy -o unit_tests $(LIBS)

run_tests: unit_tests
	@./unit_tests

output_tests: run_tests
	@gcov *.gcda
	@lcov -c --directory . --output-file coverage.info
	@genhtml coverage.info --output-directory ../output
	@make fclean

.PHONY: all clean fclean re
