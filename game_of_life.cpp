
#include <ncurses.h>
#include "Grid.hpp"
#include <chrono>
#include <iostream>

void framerate(){
    std::chrono::steady_clock::time_point tempo_inicial = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point tempo_final = std::chrono::steady_clock::now();
    auto diferenca_tempo = (std::chrono::duration_cast<std::chrono::milliseconds>(tempo_final - tempo_inicial));

    while( diferenca_tempo.count() < 600) {
        tempo_final = std::chrono::steady_clock::now();
        diferenca_tempo = (std::chrono::duration_cast<std::chrono::milliseconds>(tempo_final - tempo_inicial));
    }
}

int main(){

    

    initscr();			/* Start curses mode 		  */
    noecho();
    cbreak();

    int row=10,col=10;				
    getmaxyx(stdscr,row,col);		

    Grid grid = Grid(row, col);


    grid.visualizacao();

	refresh();			/* Print it on to the real screen */
    int count = 0;

    framerate();
    while(count < 500){
        clear();
        move(0,0);
        grid.atualiza_grid();
        grid.visualizacao();
        refresh();
        count++;
        framerate();
    }
	endwin();			/* End curses mode		  */
    std::cout << count << "\n";
}

