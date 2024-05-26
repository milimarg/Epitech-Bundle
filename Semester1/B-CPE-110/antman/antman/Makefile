##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## The Makefile
##

SRC	=	antman.c 	\
		error_gestion.c 	\
		read_file.c 	\
		texte_compression.c 	\
		image_compression.c 	\
		str_to_word_array_antman.c 	\
		strcat_antman.c 	\
		fill_array_no_rep.c 	\
		html_compression.c 	\

OBJ	=	$(SRC:.c=.o)

NAME	=	antman

all:
	make -C ../lib/my/
	gcc -o $(NAME) $(SRC) -L../lib/my/ -lmy -g

clean:
		rm -f $(OBJ)

fclean: clean
		make fclean -C ../lib/my/
		rm *.o -f
		rm *~ -f
		rm *.a -f
		rm $(NAME) -f

re: fclean all
