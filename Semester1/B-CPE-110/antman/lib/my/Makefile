##
## EPITECH PROJECT, 2022
## makefile
## File description:
## good prog
##

SRC	= 	len_nbr.c 				\
		my_compute_power_rec.c			\
		my_compute_square_root.c		\
		my_find_prime_sup.c			\
		my_getnbr.c				\
		my_isneg.c				\
		my_is_prime.c				\
		my_putchar.c				\
		my_put_float.c				\
		my_put_float_condition.c		\
		my_put_float_condition_return_len.c	\
		my_put_float_return_len.c		\
		my_put_nbr.c				\
		my_putnbr_base_unsigned.c		\
		my_put_nbr_len.c			\
		my_putstr.c				\
		my_putstr1.c				\
		my_revstr.c				\
		my_showmem.c				\
		my_showstr.c				\
		my_show_word_array.c			\
		my_sort_int_array.c			\
		my_strcapitalize.c			\
		my_strcat.c				\
		my_strcmp.c				\
		my_strcpy.c				\
		my_strdup.c				\
		my_str_isalpha.c			\
		my_str_islower.c			\
		my_str_isnum.c				\
		my_str_isprintable.c			\
		my_str_isupper.c			\
		my_strlen.c				\
		my_strlowcase.c				\
		my_strncat.c				\
		my_strncmp.c				\
		my_strncpy.c				\
		my_strstr.c				\
		my_str_to_word_array.c			\
		my_strupcase.c				\
		my_swap.c				\
		str_to_word_array_condition.c 		\
		t_my_strncmp.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all: $(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp libmy.a ../
		mkdir -p ../../include
		cp my.h ../../include/

clean:
		rm *.o

fclean:
		rm *.o -f
		rm *.a -f
		rm ../*.a -f
		rm *~ -f

re: fclean all
