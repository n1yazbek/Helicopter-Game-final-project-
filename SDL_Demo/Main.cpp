#include "GameWindow.h"
#include "Helicopter.h"
#include "Obstacles.h"

using namespace std;
const int window_width = 640; 
const int window_height = 480;

int main(int argc, char* args[]) {
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		cerr << "SDL_INIT has failed. ERROR: " << SDL_GetError() << endl;
	if (!((IMG_Init(IMG_INIT_PNG)||(IMG_Init(IMG_INIT_JPG)))))
		cerr << "IMG_INIT has failed. ERROR: " << SDL_GetError() << endl;
	else
		cout << "PNG SUCCESS KRASAVA" << endl;
	SDL_Event event;
	bool gameRun = true;

	GameWindow window("Helicopter Game", window_width, window_height);

	while (gameRun) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				gameRun = false;}
	}

	window.~GameWindow();
	return 0;
}