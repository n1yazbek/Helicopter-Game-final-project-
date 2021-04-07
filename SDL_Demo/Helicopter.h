#pragma once
#include "Sprite.h"
class Helicopter :public Sprite {
	int score;
public:
	Helicopter(double x_loc, double y_loc, double w, double h, SDL_Texture* tex);

};