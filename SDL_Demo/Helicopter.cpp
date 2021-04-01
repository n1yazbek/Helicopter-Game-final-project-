#include "Helicopter.h"

Helicopter::Helicopter(Uint32 color, int x_loc, int y_loc, int w = 64, int h = 48) {
	heli_image = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);//creation of the image
	SDL_FillRect(heli_image, NULL, color);
	heli_rect = heli_image->clip_rect;
	heli_rect.x = x_loc - origin_x;
	heli_rect.y = y_loc - origin_y;
}

void::Helicopter::update(SDL_Surface* dst) {
	//......
}

void::Helicopter::draw(SDL_Surface* dst) {
	SDL_BlitSurface(heli_image, NULL, dst, &heli_rect);
}

//void::Helicopter::move_right(SDL_Surface* dst) {
//	dst->clip_rect.x++;
//	dst->clip_rect.y++;
//}
