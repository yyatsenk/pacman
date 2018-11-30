#ifndef MAP_HPP
#define MAP_HPP

#include "game.hpp"

class Map
{
    int xMax;
    int yMax;
    WINDOW *playwin;
    public:
        Map();
        Map(WINDOW * playarea);
        ~Map();
        void dispay();
};
#endif