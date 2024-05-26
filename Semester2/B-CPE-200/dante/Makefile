##
## EPITECH PROJECT, 2023
## B-CPE-200-STG-2-1-dante-noam.nedjar
## File description:
## Makefile
##

all:
	make -C ./generator/
	make -C ./solver/

clean:
	make clean -C ./generator/
	make clean -C ./solver/

fclean: clean
	make fclean -C ./generator/
	make fclean -C ./solver/

re: fclean all

.PHONY: all clean fclean re
