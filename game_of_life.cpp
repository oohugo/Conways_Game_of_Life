
#include <ncurses.h>
#include "graphic.hpp"
#include "text.hpp"
#include <iostream>

int main(){
    char choice;
    std::cout << "Digite 'n' para ncurses e 's' para SDL visual: " << "\n";
    std::cin >> choice;
    if(choice == 'n'){
        Text graphic = Text();
        graphic.main_loop();
        
    }else{
        Graphic graphic = Graphic();
        graphic.main_loop();
    }
}

