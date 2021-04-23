#include "Sprite.h"

Sprite::Sprite(double x_loc, double y_loc, double w, double h, SDL_Texture* tex, int num_rows, int num_cols, int animspeed)
:x_loc(x_loc), y_loc(y_loc), texture(tex), rows(num_rows), cols(num_cols), animspeed(animspeed){
	rectangle.x = 0;
	rectangle.y = 0;
	texHeight = h;
	texWidth = w;
	frameWidth = texWidth / num_cols;
	frameHeight = texHeight / num_rows;
	rectangle.w = frameWidth;
	rectangle.h = frameHeight;
	//SDL_QueryTexture(this->GetTex(), NULL, NULL, &this->texWidth, &this->texHeight);
}


int Sprite::GetW_tex() {
	return texWidth;
}
int Sprite::GetH_tex() {
	return texHeight;
}

Sprite::~Sprite() {
	SDL_DestroyTexture(texture);
}

double Sprite::GetX()const {
	return x_loc;
}

double Sprite::GetY()const{
	return y_loc;

}

SDL_Texture* Sprite::GetTex()const{
	return texture;
}
SDL_Rect Sprite::getRect() const{
	return rectangle;
}

void Sprite::move_Up(){
	y_loc -= 50;
}

void Sprite::move_Down() {
	y_loc += 50;
}

void Sprite::move_Right(){
	x_loc += 50;
}

void Sprite::move_Left(){
	x_loc -= 50;
}

void Sprite::change_state(){
	rectangle.y += frameHeight;
	if (rectangle.y >= rectangle.h)
		rectangle.y = 0;
	std::cout << "change state is working" << std::endl;
}

double Sprite::getFrameW()
{
	return frameWidth;
}

double Sprite::getFrameH()
{
	return frameHeight;
}
int Sprite::getRows() {
	return rows;
}
int Sprite::getCols() {
	return cols;
}
