#include "text.hpp"
#include <chrono>


void Text::framerate(int time) const{
    std::chrono::steady_clock::time_point tempo_inicial = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point tempo_final = std::chrono::steady_clock::now();
    auto diferenca_tempo = (std::chrono::duration_cast<std::chrono::milliseconds>(tempo_final - tempo_inicial));

    while( diferenca_tempo.count() < time) {
        tempo_final = std::chrono::steady_clock::now();
        diferenca_tempo = (std::chrono::duration_cast<std::chrono::milliseconds>(tempo_final - tempo_inicial));
    }
}

Text::Text(){
    init();
    getmaxyx(stdscr,max_row, max_col);		
}

void Text::init(){
    initscr();			/* Start curses mode 		  */
    noecho();
    cbreak();
    keypad(stdscr, TRUE);		/* I need that nifty F1 	*/
    nodelay(stdscr, TRUE);
}

void Text::visualizacao(Grid const grid) const{
    auto life = "#";
    auto dead = " ";
    clear();
    move(0,0);
    for(int row = 0; row < max_row; row++){
        for(int col = 0; col < max_col; col++)
            if(grid.get_element(row, col))
                printw(life);
            else
                printw(dead);
        move(row+1, 0);
    }
    refresh();
}

Text::~Text(){
    endwin();
}

void Text::main_loop(){
        Grid grid = Grid(max_row, max_col);
        visualizacao(grid);
        int ch;
        while((ch = getch()) != KEY_F(1)){
            grid.atualiza_grid();
            visualizacao(grid);
            framerate(500);
        }
}