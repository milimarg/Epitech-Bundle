##
## EPITECH PROJECT, 2024
## B-FUN-400-STG-4-1-bswolfram-corentin.metz-dubois
## File description:
## Makefile
##

BINARY_PATH    :=   $(shell stack path --local-install-root)
NAME 			= 	imageCompressor

all:
	stack build
	cp $(BINARY_PATH)/bin/$(NAME)-exe ./$(NAME)

clean:
	stack clean

fclean:
	stack clean --full
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
