##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## The Makefile
##

all:
		make -C ./lib/my
		make -C ./antman/
		make -C ./giantman/

clean:
		rm -f $(OBJ)

fclean: clean
		make fclean -C ./lib/my/
		make fclean -C ./antman/
		make fclean -C ./giantman/
		rm *.o -f
		rm *~ -f
		rm *.a -f
		rm $(NAME) -f

re: fclean all
