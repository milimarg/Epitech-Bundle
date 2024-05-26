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
		src/commands_checker.c \
		src/my_strsignal.c \
		src/my_error.c \
		src/custom_lib.c \
		src/signal_handler.c \
		src/user_input_utils.c \
		src/special_cases_execve.c \
		src/chevrons.c \
		src/pipes.c \
		src/pre_run_command.c \
		src/env/env.c \
		src/env/fill_env.c \
		src/env/node_utils_env.c \
		src/env/replace_env_variables.c \
		src/env/env_array.c \
		src/custom/cd.c \
		src/custom/exit.c \
		src/redirection_handler.c

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

.PHONY: all clean fclean re
