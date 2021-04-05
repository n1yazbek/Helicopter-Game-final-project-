#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Sprite.h"
using namespace std;
class GameWindow
{
	SDL_Window* window;
	SDL_Renderer* renderer;
public:
	GameWindow(const char* title, double w, double h);
	SDL_Texture* loadTexture(const char* filename);
	void clear();
	void render( Sprite& sprite);
	void display();
	void draw();
	~GameWindow();
};

