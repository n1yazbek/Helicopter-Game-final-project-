#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>


class Sprite{
private:
	SDL_Rect rectangle;
	SDL_Texture* texture;
	SDL_Rect image_rect;
	int frameWidth, frameHeight;
	
protected:
	double x_loc, y_loc;
public:
	int texWidth, texHeight;


	Sprite(double x_loc, double y_loc, double w, double h, SDL_Texture* tex, int num_rows, int num_cols);
	~Sprite();
	double GetX()const;
	double GetY()const;
	int GetW_tex();
	int GetH_tex();
	SDL_Texture* GetTex() const;
	SDL_Rect getRect() const;
	void move_Up();
	void move_Down();
	void move_Right();
	void move_Left();
	void change_state();
};

