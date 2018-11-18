#pragma once
#include "Boost.h"


Boost::Boost() {
	buff.LoadFromFile("food-icons-floating.png");
	sprite.SetTexture(buff);
	sprite.SetTextureRect(IntRect(0, 20, 15, 10));
	sprite.SetPosition(60, 350);
}