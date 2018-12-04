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

};

class bee : public enemy {
public:
	bee(int x, int y);
	void drawing();
	
};

class spider : public enemy {
public:


};