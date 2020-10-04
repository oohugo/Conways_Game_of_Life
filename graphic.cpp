#include "graphic.hpp"

void Graphic::init_sdl(){
    SDL_Window* w = NULL;
	SDL_Renderer* r = NULL;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	else{
	    w = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, MAX_WIDTH, MAX_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL )
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		else{
			r = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
			if( r == NULL )
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
		}
	}
    window = w;
    renderer = r;
}

Graphic::Graphic() : Grid(MAX_HEIGHT, MAX_WIDTH) {
    init_sdl();
}

void Graphic::visualizacao(Grid const grid) const{
	SDL_RenderClear(renderer);
    for(int row = 0; row < MAX_HEIGHT; row++)
        for(int col = 0; col < MAX_WIDTH; col++)
            if(grid.get_element(row, col))
                SDL_RenderDrawPoint(renderer, row, col);
	SDL_RenderPresent(renderer);
	SDL_Delay(600);
}

Graphic::~Graphic(){
    SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

Point const Graphic::get_max() const{
	return {MAX_HEIGHT, MAX_WIDTH};
}
