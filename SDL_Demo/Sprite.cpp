#include "Sprite.h"

Sprite::Sprite(double x_loc, double y_loc, double w, double h, SDL_Texture* tex, int num_rows, int num_cols)
:x_loc(x_loc), y_loc(y_loc), texture(tex){
	rectangle.x = 0;
	rectangle.y = 0;
	/*rectangle.w = w;
	rectangle.h = h;*/
	texHeight = h;
	texWidth = w;
	frameWidth = texWidth / num_cols;
	frameHeight = texHeight / num_rows;
	rectangle.w = frameWidth;
	rectangle.h = frameHeight;
}


int Sprite::GetW_tex() {
	return texWidth;
}
int Sprite::GetH_tex() {
	return texHeight;
}

Sprite::~Sprite() {
	SDL_DestroyTexture(texture);
}

double Sprite::GetX()const {
	return x_loc;
}

double Sprite::GetY()const{
	return y_loc;

}

SDL_Texture* Sprite::GetTex()const{
	return texture;
}
SDL_Rect Sprite::getRect() const{
	return rectangle;
}

void Sprite::move_Up(){
	y_loc -= 50;
}

void Sprite::move_Down() {
	y_loc += 50;
}

void Sprite::move_Right(){
	x_loc += 50;
}

void Sprite::move_Left(){
	x_loc -= 50;
}

void Sprite::change_state(){
	rectangle.x += frameWidth;
	if (rectangle.x >= rectangle.w)
		rectangle.x = 0;
	std::cout << "change state is working" << std::endl;

}

//void Sprite::draw(SDL_Surface* dst){
//	//.....
//}
//void Sprite::update_properties(){
//	origin_x = origin_y = 0;
//	set_position(rectangle.x, rectangle.y);
//}
//
//void Sprite::set_position(int x, int y){
//	rectangle.x = x - origin_x;
//	rectangle.y = y - origin_y;
//}
//
//void Sprite::set_image(const char filename[]=NULL) {
//	if (filename != NULL) {
//		SDL_Surface* loaded_image = NULL;
//		loaded_image = IMG_Load(filename);
//		if (loaded_image != NULL) {
//			image = loaded_image;
//			rectangle = image->clip_rect;
//			update_properties();
//		}
//	}
//}
