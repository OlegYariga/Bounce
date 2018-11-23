#pragma once
#include "Boost.h"
#include "engine.h"

Boost::Boost() {
	buff.loadFromFile("food-icons-floating.png");
	sprite.setTexture(buff);
	sprite.setTextureRect(IntRect(0, 20, 15, 10));
	sprite.setPosition(50, 50);
}

Spike::Spike() {
	spike1.loadFromFile("Deadly_spikes1.jpg");
	sprite.setTexture(spike1);
	sprite.setTextureRect(IntRect(165, 185, 26, 20));
}

void Spike::draw_spike() {
	for (int i = 0; i < WIDTH_MAP; i++) {
		for (int j = 0; j < HEIGHT_MAP; j++) {
			if (TileMap[i][j] == '^') {
				sprite.setPosition(j * 32, i * 32);
				window.draw(sprite);
			}
		}
	}
}