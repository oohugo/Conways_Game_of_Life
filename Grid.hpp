
#ifndef GRID_HPP
#define GRID_HPP

#include <ncurses.h>

class Grid{
public:
    Grid(int, int);
    void visualizacao() const;
    ~Grid();
    int getSingleIndex(int row, int col) const;
    void atualiza_grid();
private:
    bool * grid; 
    int row_max;
    int col_max;
    void init_grid();
    short conta_vizinhos(int row, int col) const;
    void logica_game() const;

};

#endif
