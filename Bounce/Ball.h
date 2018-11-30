#pragma once
#include "engine.h" // ������ �� ��������
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
	void damage();
	void heal();
	int getLife();
private:

	int life;
	Image pers;
	Texture person;
	Sprite sprite; 
	Clock clock;
	float time;
	float dx, dy;
//	FloatRect rect;
	bool onGround;
	
};
	