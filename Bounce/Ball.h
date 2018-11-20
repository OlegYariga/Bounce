#pragma once
#include "engine.h" // теперь всё работает
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball {
public:
	Sprite sprite;
	Ball();
	void drawing_person();
	void KeyRight();
	void KeyLeft();
private:
	Texture person;
	//Sprite sprite; но не инклудится engine.h
};
