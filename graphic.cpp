#include "graphic.hpp"
#include <stdexcept>
#include <string>
#include <iostream>
void Graphic::init_sdl(){
    window = NULL;
    renderer = NULL;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	throw std::runtime_error(SDL_GetError() );
    window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, MAX_WIDTH, MAX_HEIGHT, SDL_WINDOW_SHOWN );
    if( window == NULL ){
      auto error = SDL_GetError();
      SDL_Quit();
      throw std::runtime_error(error);
    }
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
    if( renderer == NULL ){
        auto error = SDL_GetError();
	SDL_DestroyWindow(window);
	SDL_Quit();
	throw std::runtime_error(error);
    }
}

Graphic::Graphic(int l){
	if(l > 0 && l <= MAX_HEIGHT /2 && l <= MAX_WIDTH /2)
		length = l;
	else
		length = 1;
	try{
           init_sdl();
	}
        catch(const std::runtime_error& e){
	    std::cerr << "SDL error: " << e.what() << "\n";
	}
}

void Graphic::visualizacao(Grid& grid){
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF );
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    for(int row = 0; row < MAX_WIDTH / length; row++){
    	for(int col = 0; col < MAX_HEIGHT / length; col++)
        	if(grid.get_element(row, col))
				for(int i = 0; i < length; i++)
					for(int j = 0; j < length; j++)
            			SDL_RenderDrawPoint(renderer, row*length + i, col*length + j);
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
	Grid grid = Grid(MAX_WIDTH / length, MAX_HEIGHT / length);
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
				else if(event.key.keysym.scancode == SDL_SCANCODE_R)
					grid.reset_grid();
				break;
			}
		}
		grid.atualiza_grid();
		visualizacao(grid);
	}
}
