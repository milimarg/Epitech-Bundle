##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## description
##

SRC	=	src/main.c	\
		src/my_str_to_word_array.c	\
		src/action/start.c	\
		src/action/stop.c	\
		src/action/forward.c	\
		src/action/backward.c	\
		src/action/get_info_lidar.c	\
		src/action/turn.c	\
		src/action/cycle.c	\
		src/print_float_tab.c	\
		src/get_between_idx.c	\
		src/compute_average_float.c

NAME	=	ai

CFLAGS	=	-Wall -Wextra

DEBUG	=	-g

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) $(DEBUG)

clean:
	rm -f *.o
	rm -f *~

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all re clean fclean
