#include <curses.h>
#include "game.hpp"

Game::Game(WINDOW *win, int y, int x, char c)
{
    map = new Map(win);
    pacman = new Pacman(win, y, x, c);
    nightmares = new Nightmare *[3];
}

Game::~Game()
{
    if (map)
        delete map;
    if (pacman)
        delete pacman;
    for(int i = 0; i < 3; ++i)
        if (nightmares[i])
            delete nightmares[i];
}

Nightmare **Game::get_nightmares() const
{
    return nightmares;
}

Map *Game::get_map() const
{
    return map;
}

Pacman *Game::get_pacman() const
{
    return pacman;
}

