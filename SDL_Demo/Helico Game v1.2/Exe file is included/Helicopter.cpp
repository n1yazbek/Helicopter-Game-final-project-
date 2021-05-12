#include "Helicopter.h"

Helicopter::Helicopter()
{
}

Helicopter::Helicopter(int x_loc, int y_loc, int w,
	int h, SDL_Texture* tex, int num_rows, int num_cols, int animspeed)
	:Sprite(x_loc, y_loc, w, h, tex, num_rows, num_cols, animspeed) {
	score = 0;
	scoreRect.x = scoreRect.y = 0;
	scoreRect.w = 400; scoreRect.h = 60;
	int texW = 0;
	int texH = 0;
	BestScoreRect.x =680, BestScoreRect.y = 0;
	BestScoreRect.w = 600; BestScoreRect.h = 60;
	int BestTexW = 0;
	int BestTexH = 0;
}

Helicopter::~Helicopter()
{
}

void Helicopter::move_Up() {
	y_loc-=35;
	if (this->GetY() <= scoreRect.h + scoreRect.y)
		SetY(scoreRect.h + scoreRect.y);
}

void Helicopter::move_Down() {
	y_loc += 35;
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

void Helicopter::Score()
{
	score++;;
}

int Helicopter::getScore() const
{
	return this->score;
}

int Helicopter::operator++(int)
{
	Helicopter temp;
	temp.score = score++;
	return temp.score;
}
