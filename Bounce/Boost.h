#pragma once
#include <SFML/Graphics.hpp>
#include <list>

using namespace std;
using namespace sf;

class Object {
public:
	int getX();
	int getY();
private:
	int x, y;
};

class Boost:public Object {
public:
	Sprite sprite_Boost;
	void randomeBoostgenerator();
	void drawBoost();
	Boost();
private:
	Texture buff;
};

class Spike:public Object {
public:
	Sprite sprite_Spike;
	Spike();
	void draw_spike();
	void interact(Texture sprite_ball);
private:
	Texture spike1;
	list<int> coordinateX;
	list<int> coordinateY;
};