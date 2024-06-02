##
## EPITECH PROJECT, 2024
## strace
## File description:
## Makefile
##

.SILENT:

SRC	=	src/main.c \
		src/parsing.c \
		src/env.c \
		src/core/strace.c \
		src/core/core.c \
		src/core/init.c \
		src/core/utils.c \
		src/core/format.c \
		src/core/format_stat.c \

OBJ = $(SRC:.c=.o)

NAME	=	strace

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
