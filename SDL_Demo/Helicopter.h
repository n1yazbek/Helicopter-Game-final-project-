#pragma once
#include <iostream>
#include <SDL.h>

class Helicopter
{
	SDL_Surface* heli_image=NULL;
	SDL_Rect heli_rect;
	int origin_x = 0;
	int origin_y = 0;
public:
	
	Helicopter(Uint32 color, int x_loc, int y_loc, int w, int h);
	void update(SDL_Surface* dst);
	void draw(SDL_Surface* destination);
};

