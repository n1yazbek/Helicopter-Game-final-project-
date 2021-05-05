#include "Sprite.h"

Sprite::Sprite(int x_loc, int y_loc, int w, int h,
	SDL_Texture* tex, int num_rows, int num_cols, int animspeed)
	:x_loc(x_loc), y_loc(y_loc), texture(tex), rows(num_rows),
	cols(num_cols), animspeed(animspeed) {
	rectangle.x = 0;
	rectangle.y = 0;
	texHeight = h;
	texWidth = w;
	frameWidth = texWidth / num_cols;
	frameHeight = texHeight / num_rows;
	rectangle.w = frameWidth;
	rectangle.h = frameHeight;
}

int Sprite::GetW_tex() const {
	return texWidth;
}
int Sprite::GetH_tex() const {
	return texHeight;
}

//Sprite::~Sprite() {
//	SDL_DestroyTexture(texture);
//}

void Sprite::SetX(int n) {
	this->x_loc = n;
}
void Sprite::SetY(int n) {
	this->y_loc = n;
}

double Sprite::GetX()const {
	return x_loc;
}

double Sprite::GetY()const {
	return y_loc;

}

SDL_Texture* Sprite::GetTex()const {
	return texture;
}
SDL_Rect Sprite::getRect() const {
	return rectangle;
}

void Sprite::move_Up() {
	y_loc -= 10;
	if (this->GetY() <= 0)
		y_loc = 0;
}

void Sprite::move_Down() {
	y_loc += 10;
	if (this->GetY() >= 720 - this->getFrameH())
		y_loc = 720 - this->getFrameH();
}

void Sprite::move_Right() {
	x_loc += 50;
	if (this->GetX() >= 1280 - this->getFrameW())
		x_loc = 1280 - this->getFrameW();

}

void Sprite::move_Left() {
	x_loc -= 50;
	if (this->GetX() <= 0)
		x_loc = 0;
}

void Sprite::change_state() {
	rectangle.y += frameHeight;
	if (rectangle.y >= rectangle.h)
		rectangle.y = 0;
	std::cout << "change state is working" << std::endl;
}

int Sprite::getFrameW()const {
	return frameWidth;
}

int Sprite::getFrameH()const {
	return frameHeight;
}
int Sprite::getRows()const {
	return rows;
}
int Sprite::getCols() const {
	return cols;
}

int Sprite::getAnimSpeed() const {
	return animspeed;
}

bool operator==(const Sprite& helic, const Sprite& fire) {
	bool x_pos = false, res = false;
	if((fire.GetX() <= helic.GetX() + helic.getFrameW()-80 && fire.GetX() + fire.getFrameW()
		>= helic.GetX()+200)){x_pos = true;}
	if(x_pos==true && (fire.GetY() + fire.getFrameH() >= helic.GetY() && fire.GetY()
		<= helic.GetY() + helic.getFrameH())) {
		res = true;
	}
	return res;
}
