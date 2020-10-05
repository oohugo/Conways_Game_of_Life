
#include "Grid.hpp"
#include <stdlib.h>
#include <ctime>

Grid::Grid(int const row, int const col){
    grid.resize(row * col, false);
  //  grid = aux;
    row_max = row;
    col_max = col;
    init_grid();
} 

int Grid::getSingleIndex(int row, int col) const
{
     return (row * col_max) + col;
}

void Grid::init_grid(){
    bool aleatorio;

    auto seed = time(nullptr);
    srand(seed);
    
    for(int row = 0; row < row_max; row++)
        for(int col = 0; col < col_max; col++){
            aleatorio = rand() % 2;
            grid[getSingleIndex(row, col)] = aleatorio;
        }
}

void Grid::atualiza_grid(){
    short *nova_grid = new short[row_max * col_max];
    for(int row = 0; row < row_max; row++)
        for(int col = 0; col < col_max; col++)
            nova_grid[getSingleIndex(row,col)] = conta_vizinhos(row,col);

    for(int row = 0; row < row_max; row++)
        for(int col = 0; col < col_max; col++)
           
            if( grid[getSingleIndex(row,col)]){
                
                if(nova_grid[getSingleIndex(row,col)] < 2)
                    grid[getSingleIndex(row,col)] = false;
                
                else if(nova_grid[getSingleIndex(row,col)] > 3 )
                    grid[getSingleIndex(row,col)] = false;
           
            }else if(nova_grid[getSingleIndex(row,col)] == 3 )
                    grid[getSingleIndex(row,col)] = true;
        
    delete[] nova_grid;
}

short Grid::conta_vizinhos(int row, int col) const{
    short sum = 0;

    if(row != 0){
        if(col != 0)
            if(grid[getSingleIndex(row-1, col-1)])
                sum++;

        if(grid[getSingleIndex(row-1, col)])
            sum++;
        
        if(col != col_max-1)
            if(grid[getSingleIndex(row-1, col+1)])
                sum++;
    }


    if(col != 0)
        if(grid[getSingleIndex(row, col-1)])
            sum++;

    if(col != col_max-1)
        if(grid[getSingleIndex(row, col+1)])
            sum++;

    if(row != row_max){
        if(col != 0)
            if(grid[getSingleIndex(row+1, col-1)])
                sum++;
    
        if(grid[getSingleIndex(row+1, col)])
            sum++;
    
        if(col != col_max-1)
            if(grid[getSingleIndex(row+1, col+1)])
                sum++;
    }
    return sum;
}

bool Grid::get_element(int &row, int &col) const{
    return grid[getSingleIndex(row, col)];
}