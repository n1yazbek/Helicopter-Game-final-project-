#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
using namespace std;
class GameWindow
{
	SDL_Window* window;
	SDL_Renderer* renderer;
public:
	GameWindow(const char* title, int w, int h);
	~GameWindow();
};

