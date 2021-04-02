#pragma once
#include "Sprite.h"

class Obstacle :public Sprite {
public:
	Obstacle(Uint32 color, int x_loc, int y_loc, int w, int h);
};