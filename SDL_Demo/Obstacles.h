#pragma once
#include <SDL.h>
class Obstacle
{
	SDL_Surface* image=NULL;
	SDL_Rect rectangle;
	int origin_x, origin_y;
public:
	Obstacle(Uint32 color, int x_loc, int y_loc, int w, int h);
	void draw(SDL_Surface* dst);
	void update_properties();
	void set_position(int x, int y);
	void set_image(const char filename[]);
};

