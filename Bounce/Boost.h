#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "drawMaps.h"
#include "Ball.h"

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
<<<<<<< HEAD
	int interact_boost(float ballX, float ballY);
private:
=======
	int interact_boost(float ballX, float ballY,Ball &ballhp);
private:
	int hpcount;
>>>>>>> 10281ce3d41539be4e2824611821b178204133a6
	list<float> boost_X;
	list<float> boost_Y;
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
	int interact(float ballX,float ballY,Ball &ballhp);
	FloatRect rect_spike;
private:
<<<<<<< HEAD
=======
	int hpcount;
>>>>>>> 10281ce3d41539be4e2824611821b178204133a6
	Texture spike1;
	list<float> coordinateX;
	list<float> coordinateY;
};

class Door :public Object {
public:
	bool isOpen;
	Sprite sprite_Door;
	Door();
	void findDoor();
	void drawDoor();
<<<<<<< HEAD
	void interactDoor(float ballX,float ballY);
=======
	bool interactDoor(float ballX,float ballY);
>>>>>>> 10281ce3d41539be4e2824611821b178204133a6
	void openDoor(float time);
private:
	list<float> doorX;
	list<float> doorY;
	Texture door1;
};

class HealthBar {
public:
	Image image_hpbar;
	Texture texture_hpbar;
	Sprite sprite_hpbar;
	int hpcount;
	int max;
	HealthBar();
	void update_hpbar(int k);
	void draw_hpbar(RenderWindow &window);
<<<<<<< HEAD
=======
};

class Key :public Object {
public:
	Key();
	Sprite sprite_Key;
	void findKey();
	void drawKey();
	void interactKey(float ballX, float ballY,Door &door);
private:
	int keycount;
	list<float> key_X;
	list<float> key_Y;
	Image key_im;
	Texture key_tx;
>>>>>>> 10281ce3d41539be4e2824611821b178204133a6
};