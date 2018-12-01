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
<<<<<<< HEAD
	int damage();
=======
	void setInvertedGravity();
	void setNormalGravity();
	int getLife();
>>>>>>> 10281ce3d41539be4e2824611821b178204133a6
private:
	Image pers;
	Texture person;
	Sprite sprite; 
	Clock clock;
	float time;
<<<<<<< HEAD
	int life;
	float dx, dy;
//	FloatRect rect;
=======
	int lifes;
	float dx, dy;
	FloatRect rect;
	FloatRect defrect;
>>>>>>> 10281ce3d41539be4e2824611821b178204133a6
	bool onGround;
	bool InvertedGravity;
	
};
	