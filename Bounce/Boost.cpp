#pragma once
#include "Boost.h"


Boost::Boost() {
	buff.loadFromFile("food-icons-floating.png");
	sprite.setTexture(buff);
	sprite.setTextureRect(IntRect(191, 35 , 32, 32));
	sprite.setPosition(50, 70);
}