#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Boost {
public:
	Sprite sprite;
	Boost();
private:
	Texture buff;
};

class Spike {
public:
	Sprite sprite_spike;
	Spike();
	void draw_spike();
	void interact(Texture sprite_ball);
private:
	Texture spike1;
};