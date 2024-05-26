##
## EPITECH PROJECT, 2023
## my_csfml_container
## File description:
## Makefile
##

SRC	=	src/main.c \
		src/handle_dropdowns_buttons.c \
		src/game_utils.c \
		src/main_handlers.c \
		src/dropdown_tools.c \
		src/os.c \
		src/resize_elements.c \
		src/keyboard_shortcuts.c \
		src/savefile/savefile.c \
		src/savefile/buttons.c \
		src/savefile/events.c \
		src/savefile/field.c \
		src/savefile/destroy.c \
		src/openfile/buttons.c \
		src/openfile/openfile.c \
		src/openfile/events.c \
		src/openfile/destroy.c \
		src/openfile/file_explorer.c \
		src/openfile/events_utils.c \
		src/openfile/file_explorer_utils.c \
		src/openfile/file_utils.c \
		src/newfile/new_file.c \
		src/draw/drawing_area.c \
		src/draw/draw_utils.c \
		src/draw/array_of_color.c \
		src/draw/color_utils.c \
		src/draw/shapes.c \
		src/draw/custom_cursor.c \
		src/draw/shape_utils.c \
		src/side_menu/add_logo.c \
		src/side_menu/menu_utils.c \
		src/side_menu/slider.c \
		src/side_menu/switch_shape.c \
		src/about/about.c \
		src/about/about_utils.c \
		src/about/take_logname.c \
		src/help/help.c \
		src/help/help_utils.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_paint

LIB_FLAGS	=	-L./my_csfml/lib -lmy-csfml-lib \
                -L./my_csfml/button -lmy-button \
                -L./my_csfml/window -lmy-window

CSFML_FLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./my_csfml/lib/
	make -C ./my_csfml/button/
	make -C ./my_csfml/window/
	gcc $(OBJ) -o $(NAME) $(LIB_FLAGS) $(CSFML_FLAGS)

clean:
	make clean -C ./my_csfml/lib/
	make clean -C ./my_csfml/button/
	make clean -C ./my_csfml/window/
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./my_csfml/lib/
	make fclean -C ./my_csfml/button/
	make fclean -C ./my_csfml/window/
	rm -f $(NAME)

re: fclean all
