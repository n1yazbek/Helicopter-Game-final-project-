#pragma once
#include "Sprite.h"

class Obstacles :public Sprite {

	public:
		Obstacles(double x_loc, double y_loc, double w, double h, SDL_Texture* tex, int num_rows, int num_cols);
		//~Obstacles();
		void move_Left();
		void reset_Pos(const Obstacles &obj);
		
};