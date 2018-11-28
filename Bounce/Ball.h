#pragma once
#include "engine.h" // теперь всё работает
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Ball {
public:
	FloatRect rect;
	Ball();
	void drawing_person();
	void KeyRight();
	void KeyLeft();
	void KeyUp();
	void CollisionX();
	void CollisionY();
	float getcoorginateX();
	float getcoorginateY();
	int damage();
private:
	Image pers;
	Texture person;
	Sprite sprite; 
	Clock clock;
	float time;
	int life;
	float dx, dy;
//	FloatRect rect;
	bool onGround;
	
};
	