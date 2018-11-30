#include "game.hpp"

Pacman::Pacman(WINDOW *win, int y, int x, char c)
{
    curwin = win;
    yLoc = y;
    xLoc = x;
    charecter = c;
    getmaxyx(curwin, yMax, xMax);
    keypad(curwin,true);
}


int Pacman::getmv()
{
    int choice = wgetch(curwin);
    switch(choice)
    {
        case KEY_UP:
            mvup(this);
            break;
        case KEY_DOWN:
            mvdown(this);
            break;
        case KEY_LEFT:
            mvleft(this);
            break;
        case KEY_RIGHT:
            mvright(this);
            break;
        default:
            break;
    }
    return choice;
}
void Pacman::display_chng()
{
    mvwaddch(curwin, yLoc,xLoc, charecter);
}

Pacman::~Pacman(){}
