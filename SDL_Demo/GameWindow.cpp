#include "GameWindow.h"

GameWindow::GameWindow(const char* title, int w, int h)
	:window(NULL), renderer(NULL){	
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, 
	SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
	if (window == NULL) { 
		cerr << "There was an error while creating the window" << endl
			<< SDL_GetError() << endl;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

GameWindow::~GameWindow() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
