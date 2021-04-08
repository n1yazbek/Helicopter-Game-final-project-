#include "GameWindow.h"

GameWindow::GameWindow(const char* title)
	:window(NULL), renderer(NULL){	
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, 
	SDL_WINDOWPOS_UNDEFINED, GetWidth(), GetHeight(), SDL_WINDOW_SHOWN);
	if (window == NULL) { 
		cerr << "There was an error while creating the window" << endl
			<< SDL_GetError() << endl;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
}

SDL_Texture* GameWindow::loadTexture(const char* filename) {
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, filename);
	if (texture == NULL)
		cout << "Failed to load texture: " << SDL_GetError() << endl;
	return texture;
}

void GameWindow::clear() {
	SDL_RenderClear(renderer);
}

void GameWindow::render(Sprite& sprite) {
	SDL_Rect src;
	src.x = sprite.getRect().x;
	src.y = sprite.getRect().y;
	src.w = sprite.getRect().w;
	src.h = sprite.getRect().h;

	SDL_Rect dst;
	dst.x = sprite.GetX();
	dst.y = sprite.GetY();
	dst.w = sprite.getRect().w ;
	dst.h = sprite.getRect().h;

	SDL_RenderCopy(renderer, sprite.GetTex(), &src, &dst);
}

void GameWindow::display() {
	SDL_RenderPresent(renderer);
}

int GameWindow::GetWidth()const{
	return width;
}

int GameWindow::GetHeight() const{
	return height;
}

GameWindow::~GameWindow() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
