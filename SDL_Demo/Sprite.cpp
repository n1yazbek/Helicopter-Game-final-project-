#include "Sprite.h"

Sprite::Sprite(Uint32 color, int x_loc, int y_loc, int w, int h){
	image = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
	SDL_FillRect(image, NULL, color);
	rectangle = image->clip_rect;
	origin_x = origin_y = 0;
	rectangle.x = x_loc - origin_x;
	rectangle.y = y_loc - origin_y;
}

void Sprite::draw(SDL_Surface* dst){
	SDL_BlitSurface(image, NULL, dst, &rectangle);
}
void Sprite::update_properties(){
	origin_x = origin_y = 0;
	set_position(rectangle.x, rectangle.y);
}

void Sprite::set_position(int x, int y){
	rectangle.x = x - origin_x;
	rectangle.y = y - origin_y;
}

void Sprite::set_image(const char filename[]=NULL) {
	if (filename != NULL) {
		SDL_Surface* loaded_image = NULL;
		loaded_image = IMG_Load(filename);
		if (loaded_image != NULL) {
			image = loaded_image;
			rectangle = image->clip_rect;
			update_properties();
		}
	}
}
