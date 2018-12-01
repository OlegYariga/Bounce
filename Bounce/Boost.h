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

class Boost :public Object {
public:
	Boost();
	bool getBoost;
	Sprite sprite_Boost;
	void randomeBoostgenerator();
	void findBoost();
	void drawBoost();
	int interact_boost(float ballX, float ballY, Ball &ballhp);
private:
	int hpcount;
	list<float> boost_X;
	list<float> boost_Y;
	Image buff_im;
	Texture buff;
};

class Spike :public Object {
public:
	bool life;
	Sprite sprite_Spike;
	Spike();
	void find_spike();
	void draw_spike();
	int interact(float ballX, float ballY, Ball &ballhp);
	FloatRect rect_spike;
private:
	int hpcount;
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
	bool interactDoor(float ballX, float ballY);
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
};

class Key :public Object {
public:
	Key();
	Sprite sprite_Key;
	void findKey();
	void drawKey();
	void interactKey(float ballX, float ballY, Door &door);
private:
	int keycount;
	list<float> key_X;
	list<float> key_Y;
	Image key_im;
	Texture key_tx;
};

class GravityDown {
public:
	GravityDown();
	void findGD();
	void drawGD();
	void interactGD(float ballX, float ballY, Ball &ball);
	list<float> GD_X;
	list<float> GD_Y;
	Image GD_im;
	Texture GD_tx;
	Sprite GD_sp;
	int x, y;
};

class GravityUp {
public:
	GravityUp();
	void findGU();
	void drawGU();
	void interactGU(float ballX, float ballY, Ball &ball);
	list<float> GU_X;
	list<float> GU_Y;
	Image GU_im;
	Texture GU_tx;
	Sprite GU_sp;
	int x, y;
};