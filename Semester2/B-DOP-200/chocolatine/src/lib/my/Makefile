##
## EPITECH PROJECT, 2023
## my
## File description:
## Makefile
##

SRC	=	my_put_nbr.c \
		my_swap.c	\
		my_strlen.c	\
		my_getnbr.c	\
		my_strcpy.c	\
		my_strncpy.c	\
		my_strncmp.c	\
		my_strstr.c	\
		my_strcmp.c	\
		my_strcat.c	\
		my_strncat.c \
		my_str_to_word_array.c \
		my_str_to_word_array_separator.c \
		my_strdup.c \
		my_strndup.c \
		my_char_isalphanum.c \
		my_char_memset.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-Wall -Wextra

all:
	gcc $(SRC) $(CFLAGS) -c
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
