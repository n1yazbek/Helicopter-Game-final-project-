#pragma once
#include <SDL.h>
#include <SDL_image.h>
class Sprite
{
	SDL_Surface* image;
	SDL_Rect rectangle;
	int origin_x=0, origin_y=0;
public:
	Sprite(Uint32 color, int x_loc, int y_loc, int w, int h);
	void draw(SDL_Surface* dst);
	void set_image(const char filename[]);
	void update_properties();
	void set_position(int x, int y);
};

