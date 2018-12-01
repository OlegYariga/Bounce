#pragma once
#include "engine.h" // ?????? ??? ????????
#include <SFML/Graphics.hpp>
using namespace sf;

class Ball {
public:

	Ball();
	void drawing_person();
	void KeyRight(float a);
	void KeyLeft(float a);
	void KeyUp(float a);
	void CollisionX();
	void CollisionY();
	void GetDefPos();
	void Damage();
	void Healing();
	float getcoorginateX();
	float getcoorginateY();
	void setInvertedGravity();
	void setNormalGravity();
	int getLife();
private:
	Image pers;
	Texture person;
	Sprite sprite;
	Clock clock;
	float time;
	int lifes;
	float dx, dy;
	FloatRect rect;
	FloatRect defrect;
	bool onGround;
	bool InvertedGravity;

};