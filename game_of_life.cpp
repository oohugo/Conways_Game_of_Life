
#include <ncurses.h>
#include "Grid.hpp"

int main(){

    Grid grid = Grid(5);
    

    initscr();			/* Start curses mode 		  */
    grid.visualizacao();
    noecho();
	refresh();			/* Print it on to the real screen */
	getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */
}

