#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "drawMaps.h"

using namespace std;
using namespace sf;

class Object {
public:
	list<Object> objects;
	list<Object>::iterator it;
	int getX();
	int getY();
	float x, y;
	String name;
private:
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
	void find_spike();
	void draw_spike();
	void interact(Texture sprite_ball);
private:
	list<char*> spikes_coordinate;
	Texture spike1;
	list<int> coordinateX;
	list<int> coordinateY;
};

class Door :public Object {
public:
	bool isOpen;
	Sprite sprite_Door;
	Door();
	void drawDoor();
	void openDoor(float time);
private:
	Texture door1;
};