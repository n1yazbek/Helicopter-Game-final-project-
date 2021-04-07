#pragma once
#include "Sprite.h"

class Obstacles :public Sprite {

	public:
		Obstacles(double x_loc, double y_loc, double w, double h, SDL_Texture* tex);
		void move_Right();
		void move_Left();
};