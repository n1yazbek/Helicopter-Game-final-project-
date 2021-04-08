#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>


class Sprite{
private:
	SDL_Rect rectangle;
	SDL_Texture* texture;
protected:
	double x_loc, y_loc;
public:
	Sprite(double x_loc, double y_loc, double w, double h, SDL_Texture* tex);
	~Sprite();
	double GetX()const;
	double GetY()const;

	SDL_Texture* GetTex() const;
	SDL_Rect getRect() const;
	void move_Up();
	void move_Down();
	void move_Right();
	void move_Left();
};

