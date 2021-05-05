#include "GameWindow.h"
#include "Helicopter.h"
#include "Sprite.h"
#include "Obstacles.h"
#include <SDL_ttf.h>

#define fps 60
using namespace std;

void cap_framerate(Uint32 starting_tick) {
	if ((1000 / fps) > SDL_GetTicks() - starting_tick) {
		SDL_Delay(1000 / fps - (SDL_GetTicks() - starting_tick));
	}
}

 int control_type(){
	int control;
	cout << "Choose how to control: " << endl << "1) UP&DOWN keys\n2) MOUSE\n";
	cin >> control;
	return control;
}

int main(int argc, char* args[]) {

	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		cerr << "SDL_INIT has failed. ERROR: " << SDL_GetError() << endl;
	if (TTF_Init() < 0)
		cerr << "TTF failed : " << TTF_GetError() << endl;
	if (!((IMG_Init(IMG_INIT_PNG) || (IMG_Init(IMG_INIT_JPG)))))
		cerr << "IMG_INIT has failed. ERROR: " << SDL_GetError() << endl;
	else
		cout << "PNG SUCCESS KRASAVA" << endl;
	SDL_Event event;
	bool gameRun = true;
	Uint32 starting_tick;
	
	GameWindow window("Helicopter Game");
	SDL_Texture* background = window.loadTexture("images\\clouds_f.jpg");
	SDL_Texture* heli = window.loadTexture("images\\helico_f.png");
	SDL_Texture* wall = window.loadTexture("images\\fire_image.png");
	Sprite platform(0, 0, 7680, 720, background, 1, 6, 1000);
	Helicopter helic(100, 100, 423, 600, heli, 4, 1, 80);
	Obstacles fire(900, 300, 738, 50, wall, 1, 5, 500);

	while(gameRun) 
	{
		starting_tick = SDL_GetTicks();
		unsigned int lastTime = 0;
		
		while (SDL_PollEvent(&event)) 
		{
			if (event.type == SDL_QUIT){ gameRun = false; }
			if (event.type == SDL_KEYDOWN) {
				if(event.key.keysym.sym == SDLK_ESCAPE) 
					gameRun = false;
					if (event.key.keysym.sym == SDLK_UP)
						helic.move_Up();
					if (event.key.keysym.sym == SDLK_DOWN)
						helic.move_Down();
					if (event.key.keysym.sym == SDLK_RIGHT)
						helic.move_Right();
					if (event.key.keysym.sym == SDLK_LEFT)
						helic.move_Left();
			}
		}
		if (starting_tick > lastTime) {
			fire.move_Left();
			helic.score = starting_tick / 1000;
			cout << "\n" << helic.score << endl;
			lastTime = starting_tick;
		}
		if (helic == fire) {
			cout << "Operationoverloading is working" << endl;
			gameRun = false;

		}

		window.clear();
		window.render(platform);
		window.render(helic);
		window.render(fire);
		window.display();
		cap_framerate(starting_tick);
	}
	window.~GameWindow();
	return 0;
}