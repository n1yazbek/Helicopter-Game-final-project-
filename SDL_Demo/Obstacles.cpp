#include "Obstacles.h"

Obstacles::Obstacles(double x_loc, double y_loc, double w, double h,
	SDL_Texture* tex, int num_rows, int num_cols) :Sprite(x_loc, y_loc, w, h, tex, num_rows, num_cols)
{}

void Obstacles::move_Left(){
	y_loc = -20;
}


void Obstacles::reset_Pos(const Obstacles &obj) {
	x_loc = 1280 - obj.getRect().w;
}

//
//void Sprite::move_Right() {
//	x_loc += 2;
//}
//
//void Sprite::move_Left(void) {
//	this->x_loc -= 2.0;
//}
//


