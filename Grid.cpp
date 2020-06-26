
#include "Grid.hpp"
#include <stdlib.h>
#include <ctime>

Grid::Grid(int t){
    bool *aux = new bool[t * t];
    grid = aux;
    tamanho = t;
    init_grid();
} 


void Grid::visualizacao() const{
    auto life = "#";
    auto dead = " ";
    for(int row = 0; row < tamanho; row++){
        for(int col = 0; col < tamanho; col++)
            if(grid[getSingleIndex(row, col)])
                printw(life);
            else
                printw(dead);
        move(row+1, 0);
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
    bool aleatorio;

    auto seed = time(nullptr);
    srand(seed);
    
    for(int row = 0; row < tamanho; row++)
        for(int col = 0; col < tamanho; col++){
            aleatorio = rand() % 2;
            grid[getSingleIndex(row, col)] = aleatorio;
        }
}
