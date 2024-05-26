##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## jesouisperdu
##

SRC	=	my_printf.c 	\
	    flags.c	\
	    flags2.c 	\
	    flags3.c 	\
	    flags4.c 	\
	    my_compute_power_rec.c	\
	    my_find_prime_sup.c	\
	    my_getnbr.c	\
	    my_putchar.c	\
	    my_isneg.c	\
	    my_is_prime.c	\
	    my_put_nbr.c	\
	    my_put_unnbr.c	\
	    my_putstr.c	\
	    my_strlen.c	\
	    my_revstr.c	\
	    my_showmem.c	\
	    my_showstr.c	\
	    my_sort_int_array.c	\
	    my_strcapitalize.c	\
	    my_strcat.c	\
		my_strcat_minis.c \
	    my_strcmp.c	\
	    my_strcpy.c	\
	    my_str_isalpha.c	\
	    my_str_islower.c	\
	    my_str_isnum.c	\
	    my_str_isprintable.c	\
	    my_str_isupper.c	\
	    my_strlowcase.c	\
	    my_strncat.c	\
	    my_strncmp.c	\
	    my_strncpy.c	\
	    my_strstr.c	\
	    my_strupcase.c	\
	    my_swap.c	\
	    my_rev_nbr.c 	\
	    my_nbrlen.c 	\
		my_compare.c	\
		my_str_to_word_array.c \
		my_str_to_word_array_minis.c \
		my_str_compare.c \
		my_str_rmenv.c \
		my_array_len.c \
		my_strdup.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	find -name "*~" -delete -or -name "#*#" -delete

fclean:	clean
	rm -f $(NAME)

re: fclean all clean

.PHONY: all clean fclean re
