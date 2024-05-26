##
## EPITECH PROJECT, 2022
## my_ls
## File description:
## Makefile_main
##

SRC	=	main.c						\
		my_ls.c						\
		utils.c						\
		get_args.c					\
		get_files_array.c			\
		display_files.c				\
		display_files_extra.c		\
		sort_by_time.c				\
		count_files_to_display.c	\
		display.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls

all:
	(cd ./lib/my/ && make re && make clean)
	gcc -c $(SRC) && gcc -o $(NAME) $(OBJ) -L. -lmy

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
