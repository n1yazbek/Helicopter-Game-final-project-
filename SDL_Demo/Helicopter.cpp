#include "Helicopter.h"

Helicopter::Helicopter(int x_loc, int y_loc, int w,
	int h, SDL_Texture* tex, int num_rows, int num_cols, int animspeed)
	:Sprite(x_loc, y_loc, w, h, tex, num_rows, num_cols, animspeed){}

void Helicopter::move_Up() {
	y_loc-=10;
	if (this->GetY() <= 0)
		SetY(0);
}

void Helicopter::move_Down() {
	y_loc += 10;
	if (this->GetY() >= 720 - this->getFrameH())
		y_loc = 720 - this->getFrameH();
}

void Helicopter::move_Right() {
	x_loc += 3;
	if (this->GetX() >= 1280 - this->getFrameW())
		x_loc = 1280 - this->getFrameW();

}

void Helicopter::move_Left() {
	x_loc -= 3;
	if (this->GetX() <= 0)
		x_loc = 0;
}
