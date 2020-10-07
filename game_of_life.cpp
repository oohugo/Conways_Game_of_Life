
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
        std::cout << "Digite o tamanho da celula em pixels: " << "\n";
        int input;
        std::cin >> input;
        Graphic graphic = Graphic(input);
        graphic.main_loop();
    }
}

