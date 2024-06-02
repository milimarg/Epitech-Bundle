##
## EPITECH PROJECT, 2024
## B-CCP-400-STG-4-1-theplazza-noe.tritsch
## File description:
## Makefile
##

SRC	=	Src/main.cpp	\
		Src/Pizza/APizza.cpp	\
		Src/Pizza/Regina.cpp	\
		Src/Pizza/Margarita.cpp	\
		Src/Pizza/Americana.cpp	\
		Src/Pizza/Fantasia.cpp	\
		Src/Pizza/PizzaFactory.cpp	\
		Src/Error/Error.cpp	\
		Src/Reception/Reception.cpp	\
		Src/Reception/LineEditing.cpp	\
		Src/Process/Process.cpp	\
		Src/Kitchen/Kitchen.cpp	\
		Src/Threads/ConditionalVariable.cpp	\
		Src/Threads/ThreadPool.cpp \
		Src/Threads/Thread.cpp	\
		Src/Threads/Mutex.cpp	\
		Src/Threads/ScopedLock.cpp	\
		Src/Ipc/NamedPipe.cpp

OBJ	= $(patsubst Src/%.cpp,build/%.o,$(SRC))
DIRS	=	$(sort $(dir $(OBJ)))

NAME	=	plazza

CPPFLAGS	=	-g -std=c++20 -O3 -flto -lpthread

INCLUDES	:=	$(addprefix -I , $(wildcard $(shell find Includes/** -type d)))

all: build $(NAME)

build:
	mkdir -p $(DIRS)

$(NAME):	$(OBJ)
	g++ $^ -o $@ $(CPPFLAGS) $(INCLUDES)

build/%.o:	Src/%.cpp
	g++ -c $< -o $@ $(CPPFLAGS) $(INCLUDES)

clean:
	rm -rf build

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re build
