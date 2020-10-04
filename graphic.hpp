#ifndef GRAPHIC_HPP
#define GRAPHIC_HPP

#include <SDL2/SDL.h> 
#include "Grid.hpp"

class Graphic: public Grid{
public:
    Graphic();
    void visualizacao(Grid const) const;
    Point const get_max() const;
    ~Graphic();
private:
    const int MAX_HEIGHT = 800;
    const int MAX_WIDTH = 600;
    SDL_Renderer* renderer;
    SDL_Window* window;
    void init_sdl();
};

#endif
