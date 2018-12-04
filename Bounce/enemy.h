#pragma once
#include <SFML/Graphics.hpp>
#include <string.h>
#include "Ball.h"
#include "drawMaps.h"
#include "engine.h"

using namespace sf;

class enemy {
public:
	FloatRect rect;
	float dx, dy;
	Texture t;
	Sprite sprite;
	Clock clock;
	float time;
	virtual void drawing() = 0;
	void collision();
	FloatRect FL();
	class bee;

	class Bullet {//класс пули
	public:
		bool life;
		Clock clock;
		float time;
		FloatRect bullet_rect;
		Texture t;
		Sprite sprite;
		int direction;//направление пули
		float dx, dy;
		Bullet(FloatRect rect);
		~Bullet();
		void collisionBullet();
		void drawing();
	};

};

class bee : public enemy {
public:
	bee(int x, int y);
	void drawing();

	
	
};

class spider : public enemy {
public:


};

