
#include <ncurses.h>
#include "graphic.hpp"
#include "text.hpp"
#include <iostream>

int main(){
    char choice;
    std::cout << "Digite 'n' para ncurses e 's' para SDL visual: " << "\n";
    std::cin >> choice;
    int count = 0;
    if(choice == 'n'){
        Text graphic = Text();
        Grid grid = Grid(graphic.get_max().x,graphic.get_max().y);
        graphic.visualizacao(grid);
        while(count < 500){
            grid.atualiza_grid();
            graphic.visualizacao(grid);
            count++;
        }
    }
    else{
        Graphic graphic = Graphic();
        Grid grid = Grid(graphic.get_max().x,graphic.get_max().y);
        graphic.visualizacao(grid);
        while(count < 500){
            grid.atualiza_grid();
            graphic.visualizacao(grid);
            count++;
        }
    }
    std::cout << count << "\n";
}

