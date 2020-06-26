
#ifndef GRID_HPP
#define GRID_HPP

#include <ncurses.h>

class Grid{
public:
    Grid(int t);
    void visualizacao() const;
    ~Grid();
    int getSingleIndex(int row, int col) const;
private:
    bool * grid; 
    int tamanho;
    void init_grid();

};

#endif
