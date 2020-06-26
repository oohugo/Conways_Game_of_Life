
#include "Grid.hpp"

Grid::Grid(int t){
    bool *aux = new bool[t * t];
    grid = aux;
    tamanho = t;
    init_grid();
} 


void Grid::visualizacao() const{
    for(int row = 0; row < tamanho; row++){
        for(int col = 0; col < tamanho; col++)
            if(grid[getSingleIndex(row, col)])
                printw("#");
            else
                printw(" ");
        move(row, 0);
    }
}

int Grid::getSingleIndex(int row, int col) const
{
     return (row * tamanho) + col;
}

Grid::~Grid(){
    delete [] grid;
}

void Grid::init_grid(){
    for(int row = 0; row < tamanho; row++)
        for(int col = 0; col < tamanho; col++)
            grid[getSingleIndex(row, col)] = true;
}
