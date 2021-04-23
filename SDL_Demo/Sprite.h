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
	int rows, cols;
	
	
protected:
	double x_loc, y_loc;
public:
	int texWidth, texHeight;
	int animspeed;
	int frameCount = rows * cols;


	Sprite(double x_loc, double y_loc, double w, double h, SDL_Texture* tex, int num_rows, int num_cols, int animspeed=0);
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
	double getFrameW();
	double getFrameH();
	int getRows();
	int getCols();
};

