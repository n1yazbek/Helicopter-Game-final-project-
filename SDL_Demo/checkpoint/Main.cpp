#include "GameWindow.h"
#include "Helicopter.h"
#include "Sprite.h"
#include "Obstacles.h"

#define fps 60
 int frameTime = 0;
using namespace std;


void update(Sprite &obj, int speed) {
	if (fps / frameTime == speed) {
		frameTime = 0;
		obj.change_state();
	}
}

void cap_framerate(Uint32 starting_tick) {
	if ((1000 / fps) > SDL_GetTicks() - starting_tick) {
		SDL_Delay(1000 / fps - (SDL_GetTicks() - starting_tick));
	}
}

int main(int argc, char* args[]) {
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		cerr << "SDL_INIT has failed. ERROR: " << SDL_GetError() << endl;
	if (!((IMG_Init(IMG_INIT_PNG) || (IMG_Init(IMG_INIT_JPG)))))
		cerr << "IMG_INIT has failed. ERROR: " << SDL_GetError() << endl;
	else
		cout << "PNG SUCCESS KRASAVA" << endl;
	SDL_Event event;
	bool gameRun = true;
	Uint32 starting_tick;

	GameWindow window("Helicopter Game");
	SDL_Texture* background = window.loadTexture("citty.jpg");
	SDL_Texture* heli = window.loadTexture("helico_f.png");
	SDL_Texture* wall = window.loadTexture("eifel.png");
	Sprite platform(0, 0, window.GetWidth(), window.GetHeight(), background, 1, 1);
	Helicopter helic(100, 100, 423, 600, heli, 4, 1);
	//Obstacles eifel(800, window.GetWidth() - 400, 220, 400, wall);
	//SDL_QueryTexture(helic.GetTex(), NULL, NULL, &helic.texWidth, &helic.texHeight);


	cout<<"The location of the helicopter is : "<<helic.GetX()<<" "<<helic.GetY()<<endl;

	while(gameRun) 
	{
		starting_tick = SDL_GetTicks();
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

		frameTime++;
		
		window.clear();
		window.render(platform);
		window.render(helic);
		window.display();
		cap_framerate(starting_tick);
	}
	window.~GameWindow();
	return 0;
}