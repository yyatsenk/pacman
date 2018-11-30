#include <ncurses.h>
#include "game.hpp"

int level = 1;
int scores = 0;
bool end_game = 0;

int main()
{
	initscr();
	cbreak();
	curs_set(0);
	
	int yMax, xMax;
	int speed = 0;
	int flag = 0;
	getmaxyx(stdscr, yMax, xMax);
	if (yMax < 28 || xMax < 50)
	{
		mvprintw(0, 0,"Too small terminal.\nIt must be at least 28 "
		"points of height per 50 points of width.\n");
		getch();
		endwin();
		return (0);
	}
	
	WINDOW *playwin = newwin(23, 40, (yMax/2) - 12 ,10);
	nodelay(playwin, true);
	refresh();
	wrefresh(playwin);

	Game game(playwin, PACMAN_Y_START, PACMAN_X_START,'Y');
	Nightmare **nightmares;
	
	nightmares = game.get_nightmares();
	nightmares[0] = new Nightmare(playwin, NIGHTMARE_Y_1, NIGHTMARE_X_1,'1');
	nightmares[1] = new Nightmare(playwin, NIGHTMARE_Y_2, NIGHTMARE_X_2,'2');
	nightmares[2] = new Nightmare(playwin, NIGHTMARE_Y_3, NIGHTMARE_X_3,'3');
	game.get_map()->dispay();
	mvprintw(0, 17,"Level %d       Scores: %d", level, scores);
	mvwaddch(playwin, BONUS_Y, BONUS_X, 'O');
	refresh();
	while (1)
	{	
		mvprintw(0, 17,"Level %d       Scores: %d", level, scores);
		refresh();
		if (end_game)
			break;
		if (level > 1)
			if (flag == 0)
			{
				wclear(playwin);
				game.get_map()->dispay();
				mvprintw(0, 17,"Level %d       Scores: %d", level, scores);
				mvwaddch(playwin, BONUS_Y - 10, BONUS_X + 25, 'O');
				game.get_pacman()->setyLoc(PACMAN_Y_START);
				game.get_pacman()->setxLoc(PACMAN_X_START);
				nightmares[0]->setyLoc(NIGHTMARE_Y_1);
				nightmares[0]->setxLoc(NIGHTMARE_X_1);
				nightmares[1]->setyLoc(NIGHTMARE_Y_2);
				nightmares[1]->setxLoc(NIGHTMARE_X_2);
				nightmares[2]->setyLoc(NIGHTMARE_Y_3);
				nightmares[2]->setxLoc(NIGHTMARE_X_3);
				refresh();
				wrefresh(playwin);
				flag = 1;
			}
		if (level == 3)
		{
			clear();
			mvprintw(0, 0, "You won!!!");
			getch();
			endwin();
			return (0);
		}
		game.get_pacman()->getmv();
		game.get_pacman()->display_chng();
		if (speed % 4000 == 0)
			for(int i = 0; i < 3; ++i)
			{
				nightmares[i]->find_way(game.get_pacman()->getyLoc(), game.get_pacman()->getxLoc());
				nightmares[i]->display_chng();
			}
		speed++;
		wrefresh(playwin);
	}
	endwin();
	return (0);
}
