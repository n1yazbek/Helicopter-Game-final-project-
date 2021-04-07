#include "Obstacles.h"

Obstacles::Obstacles(double x_loc, double y_loc, double w, double h,
	SDL_Texture* tex) :Sprite(x_loc, y_loc, w, h, tex)
{}

void Sprite::move_Right() {
	x_loc += 2;
}

void Sprite::move_Left(void) {
	this->x_loc -= 2.0;
}

void Sprite::reset_Pos() {
	x_loc = 1280 - rectangle.w;
	y_loc = rectangle.w;
}

