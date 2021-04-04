#include "GameWindow.h"
#include "Helicopter.h"
#include "Obstacles.h"
#define fps 60
using namespace std;
const int window_width = 640; 
const int window_height = 480;

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
	GameWindow window("Helicopter Game", window_width, window_height);

	while (gameRun) {
		starting_tick = SDL_GetTicks();
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				gameRun = false;
		}
	
		cap_framerate(starting_tick);


	}

	window.~GameWindow();
	return 0;
}