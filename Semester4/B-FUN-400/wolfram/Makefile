##
## EPITECH PROJECT, 2024
## Wolfram
## File description:
## Makefile
##

PROJECT_PATH	=	$(shell stack path --local-install-root)

GENERATE_NAME	=	Wolfram
NAME	=	wolfram

all:
	stack build
	cp $(PROJECT_PATH)/bin/$(GENERATE_NAME)-exe ./$(NAME)

clean:
	stack clean

fclean: clean
	rm -f $(NAME)

re: fclean all
