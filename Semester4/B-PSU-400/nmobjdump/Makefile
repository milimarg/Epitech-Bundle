##
## EPITECH PROJECT, 2024
## nm/objdump
## File description:
## Makefile
##

SRC_NM	=	src/nm/main.c \
			src/nm/x64/display_sections.c \
			src/nm/x64/calculate_sections.c \
			src/nm/x64/get_data_header.c \
			src/nm/x64/get_type.c \
			src/nm/x64/truncated.c \
			src/nm/x86/display_sections.c \
			src/nm/x86/calculate_sections.c \
			src/nm/x86/get_data_header.c \
			src/nm/x86/get_type.c
OBJ_NM	=	$(SRC_NM:.c=.o)
NAME_NM	=	my_nm

SRC_OBJDUMP	=	src/objdump/main.c \
				src/objdump/x64/display_header.c \
				src/objdump/x64/get_data_header.c \
				src/objdump/x64/calculate_sections.c \
				src/objdump/x64/display_sections.c \
				src/objdump/x64/truncated.c \
				src/objdump/x86/display_header.c \
				src/objdump/x86/get_data_header.c \
				src/objdump/x86/calculate_sections.c

OBJ_OBJDUMP	=	$(SRC_OBJDUMP:.c=.o)
NAME_OBJDUMP	=	my_objdump

CFLAGS	=	-Wall -Wextra

nm: $(NAME_NM)

$(NAME_NM): $(OBJ_NM)
	gcc $(OBJ_NM) -o $(NAME_NM)

objdump: $(NAME_OBJDUMP)

$(NAME_OBJDUMP): $(OBJ_OBJDUMP)
	gcc $(OBJ_OBJDUMP) -o $(NAME_OBJDUMP)

all: nm objdump

clean:
	rm -f $(OBJ_NM)
	rm -f $(OBJ_OBJDUMP)

fclean: clean
	rm -f $(NAME_NM)
	rm -f $(NAME_OBJDUMP)

re: fclean all

.PHONY: all clean fclean re nm objdump
