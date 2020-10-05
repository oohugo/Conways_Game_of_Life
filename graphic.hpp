#ifndef GRAPHIC_HPP
#define GRAPHIC_HPP

#include <SDL2/SDL.h> 
#include "Grid.hpp"

class Graphic{
public:
    Graphic();
    void main_loop();
    ~Graphic();
private:
    void visualizacao(Grid&);
    const int MAX_HEIGHT = 600;
    const int MAX_WIDTH = 800;
    SDL_Renderer* renderer;
    SDL_Window* window;
    void init_sdl();
};

#endif
