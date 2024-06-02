##
## EPITECH PROJECT, 2024
## B-PSU-400-STG-4-1-ftrace-noe.tritsch
## File description:
## Makefile
##

SRC     =	src/main.c	\
			src/print_notice.c	\
			src/tracing/ftrace.c	\
			src/tracing/get_function_name.c	\
			src/get_symb.c

OBJ     =	$(SRC:.c=.o)

NAME    =	ftrace

CFLAGS	=	-g -I./include

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) -lelf

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
