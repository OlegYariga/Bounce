#include <SFML/Graphics.hpp>
#include <string.h>

using namespace sf;

class Killer  {
public:
	
	Killer(String F,char A, int X, int Y, int W, int H);
	Killer();
	String File;
	Sprite killer_sprite;
	Texture t;
	FloatRect k_rect;
	char a;
	
	float  w, h,x,y;  // ширина и высота спрайта
	float k_currentFrame = 0; // кадр
	//float  x = 500;
	float  dx = 0.8;  //ускорение

	void move_wasp(float a);
	void show_wasp();
	void collision_K();
};


class Wasp : public Killer {
public:
	Wasp* arr[2];
	Wasp(String F,char A, int X, int Y,float W,float H);
	Wasp();
	
				
	//FloatRect k_rect;  // для координат 
	//bool k_onGroung;   // стена ли?

};

class Spider : public Killer {
public:
	
	Spider(String F, char A, int X, int Y, float W, float H);
	Spider();
	

	//FloatRect k_rect;  // для координат 
	//bool k_onGroung;   // стена ли?

};

 