
#include "Helicopter.h"
#include "Obstacles.h"
#define fps 60
using namespace std;
const int window_width = 640;   //screen dimensions
const int window_height = 480;

void cap_framerate(Uint32 starting_tick)  {	//function to limit the framerate
	if ((1000 / fps) > SDL_GetTicks() - starting_tick) {
		SDL_Delay(1000 / fps - (SDL_GetTicks() - starting_tick));
	}
}

int main(int argc, char* args[]) {   //the main parameter has to 
	SDL_Init(SDL_INIT_EVERYTHING);   //be like that-->SDL req...
	SDL_Window* window = NULL;		//Initializing all SDL stuff

	window = SDL_CreateWindow(      //creating window of the program
		"HELICOPTER",				//the title of the window
		SDL_WINDOWPOS_UNDEFINED,	//the pos of the window
		SDL_WINDOWPOS_UNDEFINED,
		window_width, window_height,	//the width and height of the window
		SDL_WINDOW_RESIZABLE);			//the window can be resized

	if (window == NULL) {  //checking whether the window created successfully or not
		cout << "There was an error while creating the window" << endl
			<< SDL_GetError() << endl;
	} 

	SDL_Surface* screen = SDL_GetWindowSurface(window);
	Uint32 white = SDL_MapRGB(screen->format, 0, 255, 255);
	Uint32 red = SDL_MapRGB(screen->format, 255, 0, 0);
	Uint32 choco = SDL_MapRGB(screen->format, 210, 105, 30);
	SDL_FillRect(screen, NULL, white);


	Helicopter helicopter1(red, window_width/2-34, window_height/2-24, 68, 48);
	helicopter1.draw(screen);

	Obstacle wall(choco, window_width/1.5, window_height/2.5, 56, 35);
	
	//wall.draw(screen);
	wall.set_image("image.bmp");
	wall.draw(screen);
	


	SDL_UpdateWindowSurface(window);
	Uint32 starting_tick;
	SDL_Event event;
	bool running = true;
	while (running) {
		starting_tick = SDL_GetTicks();//gets the milliseconds since the SDL initialized
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
				break;
			}
		}

		cap_framerate(starting_tick);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}