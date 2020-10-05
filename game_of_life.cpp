
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
        auto x = graphic.get_max_x();
        auto y = graphic.get_max_y();
        Grid grid = Grid(x,y);
        graphic.visualizacao(grid);
        while(count < 500){
            grid.atualiza_grid();
            graphic.visualizacao(grid);
            count++;
        }
    }else{
        Graphic graphic = Graphic();
        auto x = graphic.get_max_x();
        auto y = graphic.get_max_y();
        Grid grid = Grid(x,y);
        graphic.visualizacao(grid);
        while(count < 250){
            grid.atualiza_grid();
            graphic.visualizacao(grid);
            count++;
        }
    }
    std::cout << count << "\n";
}

