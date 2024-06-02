##
## EPITECH PROJECT, 2024
## Paradigms Seminar
## File description:
## Makefile
##

SRC	=	seminar/Student.cpp \
		seminar/Assistant.cpp \
		seminar/Dean.cpp \
		seminar/Seminar.cpp \
		tests/tests_student.cpp \
		tests/tests_assistant.cpp \
		tests/tests_dean.cpp \
		tests/tests_seminar.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	unit_tests

CPPFLAGS	=	-Wall -Wextra -std=c++20 -lcriterion --coverage

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
	g++ $(OBJ) -o $(NAME) $(CPPFLAGS)
	./$(NAME)

.PHONY: all clean fclean re tests_run
