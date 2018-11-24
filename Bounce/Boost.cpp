#pragma once
#include "Boost.h"
#include "engine.h"
#include "Ball.h"

Boost::Boost() {
	buff.loadFromFile("food-icons-floating.png");
	sprite.setTexture(buff);
	sprite.setTextureRect(IntRect(0, 20, 15, 10));
	sprite.setPosition(50, 50);
}

Spike::Spike() {
	spike1.loadFromFile("SpikeUp_0.png");
	sprite_spike.setTexture(spike1);
	sprite_spike.setTextureRect(IntRect(0, 0, 32, 32));
}

void Spike::draw_spike() {
	for (int i = 0; i < HEIGHT_MAP; i++) {
		for (int j = 0; j < WIDTH_MAP; j++) {
			if (TileMap[j][i] == '^') {
				sprite_spike.setPosition(i * 32, j * 32);
				window.draw(sprite_spike);
			}
		}
	}
}

void Spike::interact(Texture sprite_ball) {
	
}