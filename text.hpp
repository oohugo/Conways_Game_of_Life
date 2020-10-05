#ifndef TEXT_HPP
#define TEXT_HPP

#include <ncurses.h>
#include "Grid.hpp"

class Text{
public:
    Text();
    ~Text();
    void main_loop();
private:
    void init();
    void visualizacao(Grid const) const;
    void framerate(int) const;
    int max_col = 10;
    int max_row = 10;
};


#endif