##
## EPITECH PROJECT, 2024
## MyFTP
## File description:
## Makefile
##

SRC	=	src/server.c \
		src/check_code.c \
		src/init.c \
		src/loop.c \
		src/user.c \
		src/connection_establishment.c \
		src/code_actions/dummy.c \
		src/code_actions/login.c \
		src/code_actions/pass.c \
		src/code_actions/cdup.c \
		src/code_actions/pwd.c \
		src/code_actions/noop.c \
		src/code_actions/help.c \
		src/code_actions/cwd.c \
		src/code_actions/quit.c \
		src/code_actions/pasv.c \
		src/code_actions/list.c \
		src/code_actions/dele.c \
		src/code_actions/retr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	myftp

CFLAGS	=	-Wall -Wextra -std=gnu17

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
