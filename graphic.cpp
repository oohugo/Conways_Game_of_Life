#include "graphic.hpp"
#include <stdexcept>
#include <string>

void Graphic::init_sdl(){
    window = NULL;
	renderer = NULL;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
		throw std::runtime_error(SDL_GetError() );
	else{
	    window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, MAX_WIDTH, MAX_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL )
		    throw std::runtime_error(SDL_GetError() );
		else{
			renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
			if( renderer == NULL )
		    	throw std::runtime_error(SDL_GetError() );
		}
	}
}

Graphic::Graphic(){
    init_sdl();
}

void Graphic::visualizacao(Grid& grid){
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF );
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    for(int row = 0; row < MAX_WIDTH; row++){
    	for(int col = 0; col < MAX_HEIGHT; col++)
        	if(grid.get_element(row, col))
            	SDL_RenderDrawPoint(renderer, row, col);
	}
	SDL_RenderPresent(renderer);
	SDL_Delay(200);
}

Graphic::~Graphic(){
    SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Graphic::main_loop(){
	Grid grid = Grid(MAX_WIDTH,MAX_HEIGHT);
	visualizacao(grid);
	bool close = false;
	while (!close) { 
		SDL_Event event;  
		while (SDL_PollEvent(&event)) { 
			switch (event.type) { 
			case SDL_QUIT: 
				close = true; 
				break; 
			case SDL_KEYDOWN: 
				if(event.key.keysym.scancode == SDL_SCANCODE_Q) 
					close = true;
				break;
			}
		}
		grid.atualiza_grid();
		visualizacao(grid);
	}
}