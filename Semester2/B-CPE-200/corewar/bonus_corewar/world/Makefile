##
##EPITECH PROJECT, 2023
##B-CPE-200-STG-2-1-corewar-florent.guittre
##File description:
##Makefile
##

COREWAR =	corewar
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f
MKDIR	=	mkdir -p
LIBFT	=	-L../../libft -lft -lcurses
LIBFT_PATH	=	../../libft
INC_COREWAR	= ../../srcs/vm.h
SRCS	=		../../corewar/srcs/main_vm.c \
				../../corewar/srcs/files_to_strings.c \
				../../corewar/srcs/init_e.c \
				../../corewar/srcs/error.c	\
				../../corewar/srcs/parsing.c \
				../../corewar/srcs/parsing_second.c \
				../../corewar/srcs/ft_print_arena.c \
				../../corewar/srcs/ft_print_arena_second.c \
				../../corewar/srcs/ft_build_arena.c \
				../../corewar/srcs/op.c \
				../../corewar/srcs/ft_check_args.c	\
				../../corewar/srcs/init_cursors.c	\
				../../corewar/srcs/move_cursors.c	\
				../../corewar/srcs/add_cycle.c	\
				../../corewar/srcs/adjust_cycles.c	\
				../../corewar/srcs/init_ncurses.c	\
				../../corewar/srcs/declare_winner.c \
				../../corewar/srcs/ft_cp_int.c	\
				../../corewar/funcs/ft_fork.c \
				../../corewar/funcs/ft_lfork.c \
				../../corewar/funcs/ft_live.c \
				../../corewar/funcs/ft_add.c \
				../../corewar/funcs/ft_and.c \
				../../corewar/funcs/ft_or.c	\
				../../corewar/funcs/ft_or_plus.c \
				../../corewar/funcs/ft_xor.c	\
				../../corewar/funcs/ft_xor_plus.c \
				../../corewar/funcs/ft_sub.c \
				../../corewar/funcs/ft_zjmp.c \
				../../corewar/funcs/ft_aff.c \
				../../corewar/funcs/ft_lld.c \
				../../corewar/funcs/ft_lldi.c \
				../../corewar/funcs/ft_ld.c	\
				../../corewar/funcs/ft_sti.c \
				../../corewar/funcs/ft_funcs_tools.c \
				../../corewar/funcs/ft_funcs_tools_two.c \
				../../corewar/funcs/ft_ldi.c \
				../../corewar/funcs/ft_ldi_plus.c \
				../../corewar/funcs/ft_st.c	\
				../../corewar/srcs/init_reg.c \
				../../corewar/srcs/parse_flags.c \
				../../corewar/srcs/parse_flags_second.c \
				world.c

GREEN		= \033[32m
RED			= \033[31m
DEFAULT		= \033[37m
CYAN		= \x1b[36m
OBJS	=	$(SRCS:.c=.o)
VPATH	=	srcs/:funcs/:funcs_tests:
GRAPHICS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lGL -lGLU
MY_IDT1	=	../my_idt1
LIBS	=	$(LIBFT) -L$(MY_IDT1) -lmy-idt1 $(GRAPHICS) -lm

all:	$(COREWAR)

#Executables
$(COREWAR): $(OBJS)
	@make -C $(MY_IDT1)
	@$(CC) -o $(COREWAR) -g $(OBJS) $(CFLAGS) -include $(INC_COREWAR) $(LIBS)
	@echo "Compiling [$@]"

#Cleaning rules
clean:
	@rm -f $(OBJS)
	@echo "Cleaning [$(OBJS)]"

fclean:
	@rm -f $(OBJS)
	@rm -f $(COREWAR)
	@echo "Cleaning [libft corewar]"

re: fclean all
.PHONY: clean fclean re libft all
