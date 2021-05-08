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

void GameWindow::render(const Sprite& sprite) {
	SDL_Rect src;
	
	if (sprite.getRows() != 1 || sprite.getCols()!=1) {
		int cls = 1;
		int frameW = sprite.getFrameW(), frameH = sprite.getFrameH();
		SDL_QueryTexture(sprite.GetTex(), NULL, NULL, &frameW, &frameH);
		int time_r = (SDL_GetTicks() / sprite.getAnimSpeed()) % (sprite.getRows() );
		int time_c = (SDL_GetTicks() / sprite.getAnimSpeed()) % (sprite.getCols());
		src.y = sprite.getFrameH() * time_r;
		src.x = sprite.getFrameW() * time_c;
		src.w = sprite.getRect().w;
		src.h = sprite.getRect().h;
	}
	else{
		src.x = sprite.getRect().x;
		src.y = sprite.getRect().y;
		src.w = sprite.getRect().w;
		src.h = sprite.getRect().h;
	}

	SDL_Rect dst;
	dst.x = sprite.GetX();
	dst.y = sprite.GetY();
	dst.w = sprite.getRect().w;
	dst.h = sprite.getRect().h;

	SDL_Texture* txt = sprite.GetTex();
	SDL_RenderCopy(renderer, txt, &src, &dst);
}


void GameWindow::renderScore( Helicopter& helic) {
	
	SDL_QueryTexture(helic.scoreText, NULL, NULL, &helic.texW, &helic.texH);
	SDL_RenderCopy(renderer, helic.scoreText, NULL, &helic.scoreRect);
}

void GameWindow::textCreator(TTF_Font* font, SDL_Color color, const char* text, Helicopter&helic)
{
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, color);
	 helic.scoreText = SDL_CreateTextureFromSurface(renderer, textSurface);
}



void GameWindow::render_BestScore(Helicopter& helic) {

	SDL_QueryTexture(helic.BestScoreText, NULL, NULL, &helic.BestTexW, &helic.BestTexH);
	SDL_RenderCopy(renderer, helic.BestScoreText, NULL, &helic.BestScoreRect);
}

void GameWindow::BestScore_Creator(TTF_Font* font, SDL_Color color, const char* text, Helicopter& helic)
{
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, color);
	helic.BestScoreText = SDL_CreateTextureFromSurface(renderer, textSurface);
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

SDL_Renderer* GameWindow::getRenderer() const
{
	return this->renderer;
}

GameWindow::~GameWindow() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
}

