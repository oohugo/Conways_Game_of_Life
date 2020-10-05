#ifndef TEXT_HPP
#define TEXT_HPP

#include <ncurses.h>
#include "Grid.hpp"

class Text{
public:
    Text();
    ~Text();
    void init();
    void framerate(int) const;
    void visualizacao(Grid const) const;
    int get_max_x() const;
    int get_max_y() const;

private:
    int max_col = 10;
    int max_row = 10;
};


#endif