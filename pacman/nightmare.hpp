#ifndef NIGHTMARE_HPP
#define NIGHTMARE_HPP

#include "game.hpp"


class Nightmare:public Beast
{
    int dir;
    public:
        Nightmare(WINDOW *win, int y, int x, char c);
        ~Nightmare();
        Nightmare & operator=(Nightmare const & copy);
        int find_way(int tar_y, int tar_x);
        void display_chng();
};
#endif