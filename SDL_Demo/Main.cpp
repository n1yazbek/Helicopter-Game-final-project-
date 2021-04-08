#include "GameWindow.h"
#include "Helicopter.h"
#include "Sprite.h"
#include "Obstacles.h"

#define fps 60
using namespace std;

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
	SDL_Texture* heli = window.loadTexture("helico_orig.png");
	SDL_Texture* wall = window.loadTexture("eifel.png");
	Sprite platform(0, 0, window.GetWidth(), window.GetHeight(), background);
	Helicopter helic(100, 100, 453, 150, heli);
	Obstacles eifel(800, window.GetWidth() - 400, 220, 400, wall);

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

		window.clear();
		window.render(platform);
		window.render(helic);
		window.render(eifel);
		
		window.display();
		cap_framerate(starting_tick);
	}
	window.~GameWindow();
	return 0;
}