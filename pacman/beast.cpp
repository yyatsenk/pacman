#include "game.hpp"

extern int level;
extern int scores;
extern bool end_game;

Beast::Beast(){}
Beast::~Beast(){}

int Beast::mvup(Beast *beast)
{
    d_char = mvwinch(curwin, yLoc - 1, xLoc);
    if (d_char != '#' && !end_game)
    {
        if (check_end_game(beast))
            return (0);
        mvwaddch(curwin, yLoc,  xLoc, ' ');
        --yLoc;
        if(yLoc < 1)
            yLoc = 1;
        return (1);
    }
    return (0);
}

int Beast::mvdown(Beast *beast)
{
    d_char = mvwinch(curwin, yLoc + 1,  xLoc);
    if (d_char != '#' && !end_game)
    {
        if (check_end_game(beast))
            return (0);
        mvwaddch(curwin, yLoc,  xLoc, ' ');
        ++yLoc;
        if(yLoc > yMax - 2)
            yLoc = yMax - 2;
        return (1);
    }
    return (0);
}

int Beast::mvleft(Beast *beast)
{
    d_char = mvwinch(curwin, yLoc,  xLoc - 1);
    if (d_char != '#' && !end_game)
    {
        if (check_end_game(beast))
            return (0);
        mvwaddch(curwin, yLoc,  xLoc, ' ');
        --xLoc;
        if(yLoc < 1)
            xLoc= 1;
        return (1);
    }
    return (0);
}

int Beast::mvright(Beast *beast)
{
    d_char = mvwinch(curwin, yLoc,  xLoc + 1);
    if (d_char != '#' && !end_game)
    {
        if (check_end_game(beast))
            return (0);
        mvwaddch(curwin, yLoc,  xLoc, ' ');
        ++xLoc;
        if(xLoc > xMax - 2)
            xLoc= xMax - 2;
        return(1);
    }
    return(0);
}

int Beast::check_end_game(Beast *beast)
{
    Pacman *pcmn;
    pcmn = dynamic_cast<Pacman *>(beast);
    if (pcmn)
    {
        switch((char)d_char)
        {
            case 'E':
                level++;
                scores += 100;
                break;
            case 'O':
                scores += 50;
                break;
            default:
                break;
        }
    }
    else if (d_char == 'Y')
    {
        clear();
        mvprintw(0, 0,"You lost!!!");
        getch();
        end_game = 1;
        return(1);
    }
    return (0);
}

void Beast::setxLoc(int val)
{
    xLoc = val;
}

void Beast::setyLoc(int val)
{
    yLoc = val;
}

int Beast::getxLoc() const
{
    return xLoc;
}

int Beast::getyLoc() const
{
    return yLoc;
}