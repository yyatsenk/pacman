#include "game.hpp"

Nightmare::~Nightmare(){}

Nightmare::Nightmare(WINDOW *win, int y, int x, char c)
{
    curwin = win;
    yLoc = y;
    xLoc = x;
    charecter = c;
    dir = 0;
    getmaxyx(curwin, yMax, xMax);
    keypad(curwin,true);
}
 
int Nightmare::find_way(int tar_y,int tar_x)
{
    if (yLoc == tar_y && yLoc == tar_x)
        return (0);
    if (yLoc < tar_y)
    {
        if (dir != UP && mvdown(this))
            dir = NONE;
        else if ((dir != RIGHT) && (xLoc > tar_x || xLoc == tar_x)&& mvleft(this))
            dir = LEFT;
        else if ((dir != LEFT) && mvright(this))
            dir = RIGHT;
        else if (mvup(this))
            dir = UP;
        else if (!mvdown(this) && !mvup(this))
        {
            mvleft(this);
            dir = LEFT;
        }
    }
    else if (yLoc > tar_y)
    {
        if (dir != DOWN && mvup(this))
            dir = NONE;
        else if ((dir != RIGHT) && (xLoc > tar_x || xLoc == tar_x) && mvleft(this))
            dir = LEFT;
        else if ((dir != LEFT) && mvright(this))
            dir = RIGHT;
        else if (mvdown(this))
            dir = DOWN;
        else if (!mvdown(this) && !mvup(this))
        {
            mvleft(this);
            dir = LEFT;
        }
    }
    else if (xLoc < tar_x)
    {
        if (dir != LEFT && mvright(this))
            dir = NONE;
        else if ((dir != DOWN) && mvup(this))
            dir = UP;
        else if ((dir != UP) && mvdown(this))
            dir = DOWN;
        else if (mvleft(this))
            dir = LEFT;
    }
    else if (xLoc > tar_x)
    {
        if (dir != RIGHT && mvleft(this))
            dir = NONE;
        else if ((dir != DOWN) && mvup(this))
            dir = UP;
        else if ((dir != UP) && mvdown(this))
            dir = DOWN;
        else if (mvright(this))
            dir = RIGHT;
    }
    return 0;
}

Nightmare & Nightmare::operator=(Nightmare const & copy)
{
	if (this != &copy)
	{
		this->xLoc = copy.xLoc;
        this->yLoc = copy.yLoc;
        this->xMax = copy.xMax;
        this->yMax = copy.yMax;
        this->charecter = copy.charecter;
        this->d_char = copy.d_char;
        this->curwin = copy.curwin;
	}
	return (*this);
}

void Nightmare::display_chng()
{
    mvwaddch(curwin, yLoc,xLoc, charecter);
}
