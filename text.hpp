#ifndef TEXT_HPP
#define TEXT_HPP

#include <ncurses.h>

class Text{
public:
    Text();
    ~Text();
    void init();
    void framerate(int) const;
    void visualizacao(Grid const) const;
    Point const get_max() const;
private:
    int max_col = 10;
    int max_row = 10;
};


#endif