#include "game.hpp"

Map::Map(){}
Map::~Map(){}

Map::Map(WINDOW * playarea)
{
    playwin = playarea;
    getmaxyx(playwin, yMax, xMax);
}

void Map::dispay()
{
	wborder(this->playwin, (int)'#', (int)'#', (int)'#',\
	(int)'#', (int)'#', (int)'#', (int)'#', (int)'#');
    if (has_colors() != 0)
    {
        start_color();
        init_pair(1, COLOR_GREEN, COLOR_BLACK);
        wattron(this->playwin, COLOR_PAIR(1));
    }
	mvwprintw(this->playwin, 11, 0,"B");
	mvwprintw(this->playwin, 11, 39,"E");
    wattroff(this->playwin, COLOR_PAIR(1));
    mvwprintw(this->playwin, 1, 19,                "##");
	mvwprintw(this->playwin, 2, 2,"###### ######### ## ######### ######");
	mvwprintw(this->playwin, 3, 2,"###### ######### ## ######### ######");
	mvwprintw(this->playwin, 4, 2,"###### ######### ## ######### ######");
	mvwprintw(this->playwin, 6, 2,"######    ################    ######");
	mvwprintw(this->playwin, 7, 2,"       ##        ##        ##       ");
    mvwprintw(this->playwin, 8, 1,"####### ######### ## ######### #######");
    mvwprintw(this->playwin, 9, 1,"      # ##                  ## #     ");
    mvwprintw(this->playwin, 10, 1,"####### ## ################ ## #######");
    mvwprintw(this->playwin, 11, 2,"          #              #          ");
    mvwprintw(this->playwin, 12, 1,"####### ## ################ ## #######");
    mvwprintw(this->playwin, 13, 1,"      # ##                  ## #     ");
    mvwprintw(this->playwin, 14, 1,"####### ## ################ ## #######");
    mvwprintw(this->playwin, 15, 1,"                  ##                 ");
    mvwprintw(this->playwin, 16, 1," ###### ######### ## ######### ###### ");
    mvwprintw(this->playwin, 17, 1,"     ##                        ##     ");
	mvwprintw(this->playwin, 18, 1,"#### ## ## ################ ## ## ####");
    mvwprintw(this->playwin, 19, 1,"        ##        ##        ##        ");
    mvwprintw(this->playwin, 20, 1," ################ ## ################ ");
    wrefresh(this->playwin);
}
