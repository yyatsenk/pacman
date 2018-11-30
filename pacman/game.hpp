#ifndef GAME_HPP
#define GAME_HPP

#include <curses.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include "beast.hpp"
#include "map.hpp"
#include "nightmare.hpp"
#include "pacman.hpp"

#define NONE    0
#define UP      1
#define DOWN    2
#define LEFT    3
#define RIGHT   4

#define PACMAN_Y_START 11
#define PACMAN_X_START 1

#define NIGHTMARE_Y_1 18
#define NIGHTMARE_X_1 28

#define NIGHTMARE_Y_2 1
#define NIGHTMARE_X_2 21

#define NIGHTMARE_Y_3 11 
#define NIGHTMARE_X_3 28

#define BONUS_Y 15
#define BONUS_X 3

extern int level;
extern int scores;
extern bool end_game;


class Game
{
    Map *map;
    Pacman *pacman;
    Nightmare **nightmares;
    public:
        Game(WINDOW *win, int y, int x, char c);
        ~Game();
        Map *get_map() const;
        Pacman *get_pacman() const;
        Nightmare **get_nightmares() const;
};

#endif