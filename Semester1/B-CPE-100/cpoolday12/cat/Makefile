##
## EPITECH PROJECT, 2022
## CPOOL_Day12
## File description:
## Makefile_task01
##

SRC		=	main.c		\
			my_cat.c

OBJ		=	$(SRC:.c=.o)

NAME		=	cat

CRIT_LIB_CMD	=	--coverage -lcriterion -L../lib/my/ -lmy

all:
	(cd ../lib/my/ && make && make clean)
	gcc -c $(SRC)
	gcc $(OBJ) -o $(NAME) -L../lib/my/ -lmy

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

tests_run:
	gcc -o unit_tests my_cat.c ../tests/test_my_cat.c $(CRIT_LIB_CMD)
	mv unit_tests ../
	mv *.gcno ../
	../unit_tests
	mv *.gcda ../
