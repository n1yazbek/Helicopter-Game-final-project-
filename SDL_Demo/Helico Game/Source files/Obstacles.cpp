#include "Obstacles.h"


Obstacles::Obstacles(int x_loc, int y_loc, int w, int h,
	SDL_Texture* tex, int num_rows, int num_cols, int animspeed)
	:Sprite(x_loc, y_loc, w, h, tex, num_rows, num_cols, animspeed){}

Obstacles::Obstacles()
{
}

Obstacles::~Obstacles()
{
}

void Obstacles::move_Up() {
	y_loc -= 5;
	if (this->GetY() <= - this->getFrameH())
		y_loc = 720 + this->getFrameH();
}

void Obstacles::move_Down() {
	y_loc += 5;
	if (this->GetY() >= 720 + this->getFrameH()) 
		y_loc =  - this->getFrameH();
}

void Obstacles::move_Right() {
	x_loc += 5;
	if (this->GetX() >= 1280 + this->getFrameW())
		x_loc = - this->getFrameW();
}

void Obstacles::move_Left() {
	x_loc -= 12;
	if (this->GetX() <= -this->getFrameW()) {
		x_loc = 1280 + this->getFrameW();  //the 75 is the height of the score text
		y_loc = rand() % (720 - (this->getFrameH()+75)) + (this->getFrameH()+75);
	}
}
