#include <SFML/Graphics.hpp>
#include <string.h>
#include "Ball.h"
#include <vector>
#include <list>
//#include <list>
using namespace std;
using namespace sf;

class Killer {
public:

	Killer(String F, char A, int X, int Y, int W, int H);
	Killer();
	String File;
	Sprite killer_sprite;
	Texture t;
	FloatRect k_rect;
	char a;

	float  w, h, x, y;  // ширина и высота спрайта
	float k_currentFrame = 0; // кадр
 
	float  dx = 0.8;  //ускорение
	
	list<float> wasp_X;
	list<float> wasp_Y;
	list<float> spid_X;
	list<float> spid_Y;

	void show_wasp();
	void collision_K();
    void drawWasp();
	void drawSpider();
    void move_wasp(float time, float ballX, float ballY, Ball &ballhp);
	void move_spid(float time, float ballX, float ballY, Ball &ballhp);
};


class Wasp : public Killer {
public:
	 
	Wasp(String F, char A, int X, int Y, float W, float H);
	
	

};

class Spider : public Killer {
public:

	Spider(String F, char A, int X, int Y, float W, float H);
	
	
	
	
};