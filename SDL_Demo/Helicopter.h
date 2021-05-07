#pragma once
#include "Sprite.h"
class Helicopter :public Sprite {
	
public:
	SDL_Texture* scoreText;
	SDL_Rect scoreRect;
	int score = 0;
	int texW;
	int texH;
	Helicopter(int x_loc, int y_loc, int w, int h,
		SDL_Texture* tex, int num_rows, int num_cols, int animspeed);
	 void move_Up();
	 void move_Down();
	 void move_Right();
	 void move_Left();
	 /*void loadFont(const char* filename, int size);*/
};