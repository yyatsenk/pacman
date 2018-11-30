#ifndef BEAST_HPP
#define BEAST_HPP

#include "game.hpp"

class Beast
{
    protected:
    int xLoc;
    int yLoc;
    int xMax,yMax;
    char charecter;
    chtype d_char;
    WINDOW *curwin;
    public:
        Beast();
        virtual ~Beast();
        virtual int mvup(Beast *beast);
        virtual int mvdown(Beast *beast);
        virtual int mvleft(Beast *beast);
        virtual int mvright(Beast *beast);
        virtual int check_end_game(Beast *beast);
        virtual void setxLoc(int val);
        virtual void setyLoc(int val);
        virtual int getxLoc() const;
        virtual int getyLoc() const;
};
#endif