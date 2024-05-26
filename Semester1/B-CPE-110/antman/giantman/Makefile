##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## The Makefile
##

SRC	=	giantman.c 	\
		error_gestion.c 	\
		read_file.c 	\
		texte_compression.c 	\
		texte_compression_utils.c	\
		image_compression.c 	\
		utils.c	\
		html_decompression.c 	\

OBJ	=	$(SRC:.c=.o)

NAME	=	giantman

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
