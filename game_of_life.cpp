
#include <ncurses.h>
#include "Grid.hpp"
#include "graphic.hpp"
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
    char choice;
    std::cout << "Digite 'n' para ncurses e 's' para SDL visual: " << "\n";
    std::cin >> choice;
    if(choice == 'n'){
        initscr();			/* Start curses mode 		  */
        noecho();
        cbreak();

        int row=10,col=10;				
        getmaxyx(stdscr,row,col);		

        Grid game = Grid(row, col);
        game.visualizacao();

	    refresh();			/* Print it on to the real screen */
        int count = 0;

        framerate();
        while(count < 500){
            clear();
            move(0,0);
            game.atualiza_grid();
            game.visualizacao();
            refresh();
            count++;
            framerate();
        }
	    endwin();			/* End curses mode		  */
        std::cout << count << "\n";
    }else{

        int count = 0;
        while (count < 500)
        {
        Graphic game = Graphic();
        game.atualiza_grid();
        game.visualizacao();
        count++;
        SDL_Delay(1000);
        }
    
    }
    
}

