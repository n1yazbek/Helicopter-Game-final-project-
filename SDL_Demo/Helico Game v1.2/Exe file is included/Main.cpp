#include <fstream>
#include <sstream>
#include <string>
#include "GameWindow.h"
#include "Helicopter.h"
#include "Sprite.h"
#include "Obstacles.h"
#include "Vector.h"
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
	bool gameRun = true, retry = false, menu = true;
	Uint32 starting_tick;
	
	GameWindow window("Helicopter Game");
	SDL_Texture* background = window.loadTexture("images\\clouds_f.jpg");
	SDL_Texture* heli = window.loadTexture("images\\helico_f.png");
	SDL_Texture* wall = window.loadTexture("images\\fire_image.png");
	SDL_Texture* explosionn = window.loadTexture("images\\explosion_1.png");
	TTF_Font* font = TTF_OpenFont("fonts\\Mosangen.ttf", 75);
	SDL_Color color = { 0, 0, 0, 0 };
	Sprite platform(0, 0, 7680, 720, background, 1, 6, 1000);
	Sprite explosion(250, 150, 6000, 389, explosionn, 1, 15, 50);
	Helicopter helic(100, 100, 423, 600, heli, 4, 1, 80);
	Obstacles fire(900, 300, 738, 50, wall, 1, 5, 250);
	Vector scoreV;
	fstream scoreFile;
	int cnt = 0;
	

	while(gameRun) 
	{
		starting_tick = SDL_GetTicks();
		unsigned int lastTime = 0;
		
		while (SDL_PollEvent(&event)) 
		{
			cap_framerate(starting_tick);
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
			if (fire.GetX() <= 20 && fire.GetX()>=0) {
				helic.Score();
			}
			lastTime = starting_tick;	
		}
		
cap_framerate(starting_tick);


		if (helic == fire) {//operator overloading-> if the helic crashes

			int length;
			ifstream filestr;

			scoreFile.open("Scores.txt", ios::binary); 
			scoreFile.seekg(0, ios::end);
			length = scoreFile.tellg();
			scoreFile.close();

			if (length == 0) {
				scoreFile.open("Scores.txt", ios::out);
				if (scoreFile.is_open()) {
					scoreFile << helic.getScore() << endl;
					scoreFile.close();
				}
			}
			else {
				scoreFile.open("Scores.txt", ios::app);
				if (scoreFile.is_open()) {
					scoreFile << helic.getScore() << endl;
					scoreFile.close();
				}
			}
			
			gameRun = false;
		}
		
		scoreFile.open("Scores.txt", ios::in);
		if (scoreFile.is_open()) {
			string line; int temp = cnt=0;
			while (getline(scoreFile, line)) {
				stringstream score(line);
				score >> temp;
				scoreV.insert(cnt, temp);
				cnt++;
			}
		}

		cap_framerate(starting_tick);
		string score_str = "score ";
		string num = to_string(helic.getScore());
		score_str.append(num);
		const char* score = score_str.c_str();

		string best_score_str = "top score ";
		string num1 = to_string(scoreV.max());
		best_score_str.append(num1);
		const char* best_score = best_score_str.c_str();


		window.BestScore_Creator(font, color, best_score, helic);
		window.textCreator(font, color, score, helic);
		window.clear();
		window.render(platform);
		window.render(helic);
		window.render(fire);
		window.renderScore(helic);
		window.render_BestScore(helic);
		window.display();
		cap_framerate(starting_tick);
	}

	scoreV.~Vector();
	helic.~Helicopter();
	fire.~Obstacles();
	window.~GameWindow();

	return 0;
}