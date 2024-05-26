##
## EPITECH PROJECT, 2022
## CPOOL_my_printf
## File description:
## Makefile
##

SRC	=	char_alpha.c					\
		my_char_isprintable.c			\
		my_compute_power_rec.c			\
		my_putchar.c					\
		my_put_nbr.c					\
		my_putstr.c						\
		my_str_isprintable.c			\
		my_strlen.c						\
		my_intlen.c						\
		my_putstr_full.c				\
		my_putnbr_base.c				\
		my_put_float.c					\
		my_put_science.c				\
		my_printf.c						\
		flags_manager.c					\
		pflags_b.c						\
		pflags_d_i_s_c_perc.c			\
		pflags_eup_g_gup_a_aup.c		\
		pflags_sup_o_x_xup_e.c			\
		pflags_u_p_n_f_fup.c			\
		my_putnbr_base_helper.c			\
		my_put_science_helper.c			\
		my_put_int_helper.c				\
		my_putstr_helper.c				\
		my_putchar_helper.c				\
		my_put_float_helper.c			\
		fflags_symbols_int.c			\
		fflags_symbols_float.c			\
		fflags_symbols_putnbr_base.c

OBJ		=	$(SRC:.c=.o)

NAME 	=	libmy.a

all: libmy.a

libmy.a:
	(cd ./lib/my/ && gcc -c $(SRC) && ar rc $(NAME) $(OBJ))
	(cd ./lib/my/ && mv libmy.a ../../)

clean:
	(cd ./lib/my/ && rm -f $(OBJ))

fclean: clean
	(rm -f $(NAME))

re:	fclean all
