#pragma once
#include "engine.h" // теперь всё работает
#include <SFML/Graphics.hpp>
using namespace sf;

class Ball {
public:

	Ball();
	void drawing_person();
	void KeyRight();
	void KeyLeft();
	void KeyUp();
	void CollisionX();
	void CollisionY();
private:
	Image pers;
	Texture person;
	Sprite sprite; 
	Clock clock;
	float time;

	float dx, dy;
	FloatRect rect;
	bool onGround;
	
};
	