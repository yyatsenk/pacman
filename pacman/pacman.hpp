#ifndef PACMAN_HPP
#define PACMAN_HPP

#include "game.hpp"

class Pacman:public Beast
{
    public:
        Pacman(WINDOW *win, int y, int x, char c);
        ~Pacman();
        int getmv();
        void display_chng();
};

#endif