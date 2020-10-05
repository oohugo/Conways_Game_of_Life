
#ifndef GRID_HPP
#define GRID_HPP

#include <vector>

class Grid{
public:
    Grid(int const, int const);
    bool get_element(int &row, int &col) const;
    void atualiza_grid();
private:
    int getSingleIndex(int row, int col) const;
    std::vector<bool> grid; 
    short conta_vizinhos(int row, int col) const;
    int row_max;
    int col_max;
    void init_grid();
    void logica_game() const;

};

#endif
