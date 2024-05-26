##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## jesouisperdu
##

SRC	=	main.c \
		error_handling/free_all_functions.c \
		error_handling/error_handling.c \
		error_handling/get_rooms_func.c \
		error_handling/sec_part_eh.c \
		find_way.c	\
		error_handling/pars_func.c \
		lem_in.c \
		calculate_way.c \
		matrix.c \
		dip_into_anthill.c \
		display_moves.c		\
		direct_way.c 		\
		subdivision_move_ant.c 			\

OBJ	=	$(SRC:.c=.o)

NAME	=	lem_in

CFLAGS += -g

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -L./lib/my/ -lmy

clean:
	rm -f $(OBJ)
	(cd ./lib/my/; make fclean)
	find -name "*~" -delete -or -name "#*#" -delete

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
