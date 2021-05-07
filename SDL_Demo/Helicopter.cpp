#include "Helicopter.h"

Helicopter::Helicopter(int x_loc, int y_loc, int w,
	int h, SDL_Texture* tex, int num_rows, int num_cols, int animspeed)
	:Sprite(x_loc, y_loc, w, h, tex, num_rows, num_cols, animspeed) {
	score = 0;
	scoreRect.x = scoreRect.y = 0;
	scoreRect.w = 1280; scoreRect.h = 75;
	int texW = 0;
	int texH = 0;
}

void Helicopter::move_Up() {
	y_loc-=25;
	if (this->GetY() <= scoreRect.h + scoreRect.y)
		SetY(scoreRect.h + scoreRect.y);
}

void Helicopter::move_Down() {
	y_loc += 25;
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
