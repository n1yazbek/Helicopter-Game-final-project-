#pragma once
#include "Sprite.h"

class Obstacles :public Sprite {
	public:
		Obstacles(int x_loc, int y_loc, int w, int h,
			SDL_Texture* tex, int num_rows, int num_cols, int animspeed);
		/*Obstacles() {}*/
		void move_Up();
		void move_Down();
		void move_Right();
		void move_Left();
		
};