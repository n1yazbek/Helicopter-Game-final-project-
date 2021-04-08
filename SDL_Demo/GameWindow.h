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
	int width = 1280;
	int height = 720;
public:
	GameWindow(const char* title);
	SDL_Texture* loadTexture(const char* filename);
	void clear();
	void render(Sprite& sprite);
	void display();
	int GetWidth()const;
	int GetHeight()const;
	~GameWindow();

};