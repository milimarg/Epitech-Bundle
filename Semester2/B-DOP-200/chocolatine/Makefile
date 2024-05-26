##
## EPITECH PROJECT, 2023
## minishell1
## File description:
## Makefile
##

SRC	=	src/main.c \
		src/prompt.c \
		src/update_shell.c \
		src/user_input.c \
		src/custom_commands.c \
		src/run_command.c \
		src/exit.c \
		src/cd.c \
		src/commands_checker.c \
		src/my_strsignal.c \
		src/my_error.c \
		src/env.c \
		src/custom_lib.c \
		src/signal_handler.c \
		src/fill_env.c \
		src/replace_env_variables.c \
		src/node_utils_env.c \
		src/env_array.c \
		src/user_input_utils.c \
		src/special_cases_execve.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./src/lib/my/ -s
	gcc $(OBJ) -o $(NAME) -L./src/lib/my/ -lmy

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C ./src/lib/my -s

re: fclean all

tests_run:
	echo "tests_run rule test!"

.PHONY: all clean fclean re tests_run
