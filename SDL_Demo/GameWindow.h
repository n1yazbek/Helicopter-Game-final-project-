#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include "Sprite.h"
#include "Helicopter.h"
using namespace std;
class GameWindow
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	int width = 1280;
	int height = 720;
public:

	GameWindow(const char* title);
	SDL_Texture* loadTexture(const char* filename);
	void clear();
	void render(const Sprite& sprite);
	void renderScore( Helicopter& helic);
	void textCreator(TTF_Font* font, SDL_Color color, const char* text, Helicopter& helic);
	void display();
	int GetWidth()const;
	int GetHeight()const;
	SDL_Renderer* getRenderer()const;
	~GameWindow();

};