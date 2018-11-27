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
	int getX();
	int getY();
	float x, y;
	String name;
private:
};

class Boost:public Object {
public:
	Boost();
	bool getBoost;
	Sprite sprite_Boost;
	void randomeBoostgenerator();
	void findBoost();
	void drawBoost();
	void interact_boost(float ballX, float ballY);
private:
	list<int> boost_X;
	list<int> boost_Y;
	Image buff_im;
	Texture buff;
};

class Spike:public Object {
public:
	bool life;
	Sprite sprite_Spike;
	Spike();
	void find_spike();
	void draw_spike();
	void interact(float ballX,float ballY);
	FloatRect rect_spike;
private:
	Texture spike1;
	list<int> coordinateX;
	list<int> coordinateY;
};

class Door :public Object {
public:
	bool isOpen;
	Sprite sprite_Door;
	Door();
	void findDoor();
	void drawDoor();
	void interactDoor(float ballX,float ballY);
	void openDoor(float time);
private:
	list<int> doorX;
	list<int> doorY;
	Texture door1;
};