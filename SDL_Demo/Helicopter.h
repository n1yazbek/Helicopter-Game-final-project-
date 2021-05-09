#pragma once
#include "Sprite.h"
class Helicopter :public Sprite {
	int score = 0;
	int BestScore = 0;
public:
	SDL_Texture* scoreText, *BestScoreText;
	SDL_Rect scoreRect, BestScoreRect;
	int texW, texH, BestTexW, BestTexH;
	Helicopter();
	Helicopter(int x_loc, int y_loc, int w, int h,
		SDL_Texture* tex, int num_rows, int num_cols, int animspeed);
	~Helicopter();
	 void move_Up();
	 void move_Down();
	 void move_Right();
	 void move_Left();
	 void Score();
	 int getScore()const;
	 int operator++(int);
};