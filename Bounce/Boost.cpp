#pragma once
#include "Boost.h"
#include "engine.h"
#include "Ball.h"

Boost::Boost() {
	buff.loadFromFile("sprCherry_1.png");
	sprite.setTexture(buff);
	sprite.setTextureRect(IntRect(0, 0, 21, 24));
	sprite.setPosition(100, 100);
}

void Boost::drawBoost() {
	for (int i = 0; i < HEIGHT_MAP; i++) {
		for (int j = 0; j < WIDTH_MAP; j++) {
			if (TileMap[j][i] == '*') {
				sprite.setPosition(i * 32, j * 32);
				window.draw(sprite);
			}
		}
	}
}

void Boost::randomeBoostgenerator() {
	int randomeX = 0;//��������� X
	int randomeY = 0;//��������� Y
	int countBoost = 5;
	srand(time(0));
	while (countBoost > 0) {
			randomeX = 1 + rand() % (WIDTH_MAP - 1);//��������� �� X �� 1 �� �����������-1, ����� �� �������� ����� ������� �����
			randomeY = 1 + rand() % (HEIGHT_MAP - 1);//���������� �� Y
			if (TileMap[randomeX][randomeY] == ' ') {
					TileMap[randomeX][randomeY] = '*';
			}
	}
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