#pragma once
#include "Boost.h"

Boost::Boost() {
	buff.loadFromFile("food-icons-floating.png");
	sprite.setTexture(buff);
	sprite.setTextureRect(IntRect(0, 20, 15, 10));
	sprite.setPosition(50, 50);
}