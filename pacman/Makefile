NAME = pacman
NCURSES_LIB = ncurs/wincon/pdcurses.a
NCURSES_HEADERS = ncurs/
FLAGS = -Wall -Werror -Wextra
CC = g++
SRC = beast.cpp game.cpp main.cpp map.cpp nightmare.cpp pacman.cpp 

all : $(NAME)

$(NAME) : 
	$(CC) $(FLAGS) $(SRC) -o $(NAME) $(NCURSES_LIB) -I $(NCURSES_HEADERS)

del_name : 
	rm -rf $(NAME)

re : del_name all