#pragma once
#include "Sprite.h"
class Helicopter :public Sprite {
	
public:
	int score=0;
	Helicopter(int x_loc, int y_loc, int w, int h,
		SDL_Texture* tex, int num_rows, int num_cols, int animspeed);
	 void move_Up();
	 void move_Down();
	 void move_Right();
	 void move_Left();
};