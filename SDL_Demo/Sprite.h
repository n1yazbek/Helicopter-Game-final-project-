#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>

class Sprite{
private:
	SDL_Rect rectangle;
	SDL_Texture* texture;
	/*SDL_Rect image_rect;*/
	int frameWidth, frameHeight;
	int rows, cols;
	int texWidth, texHeight;
	int frameCount = rows * cols;
protected:
	int x_loc, y_loc;
	int animspeed;
public:
	
	Sprite(int x_loc, int y_loc, int w, int h,
		SDL_Texture* tex, int num_rows, int num_cols, int animspeed);
	void SetX(int n);
	void SetY(int n);
	double GetX()const;
	double GetY()const;
	int GetW_tex()const;
	int GetH_tex()const;
	SDL_Texture* GetTex() const;
	SDL_Rect getRect() const;
	virtual void move_Up();
	virtual void move_Down();
	virtual void move_Right();
	virtual void move_Left();
	void change_state();
	int getFrameW()const;
	int getFrameH()const;
	int getRows()const;
	int getCols()const;
	int getAnimSpeed()const;
	//friend bool operator== (const Car& c1, const Car& c2);
	friend bool operator==(const Sprite& helic, const Sprite& fire);
};

