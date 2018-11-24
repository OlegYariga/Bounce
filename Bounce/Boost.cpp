#pragma once
#include "Boost.h"
#include "engine.h"
#include "Ball.h"

using namespace std;

Boost::Boost() {
	buff.loadFromFile("sprCherry_1.png");
	sprite_Boost.setTexture(buff);
	sprite_Boost.setTextureRect(IntRect(0, 0, 21, 24));
}

void Boost::drawBoost() {
	for (int i = 0; i < HEIGHT_MAP; i++) {
		for (int j = 0; j < WIDTH_MAP; j++) {
			if (TileMap[j][i] == '*') {
				sprite_Boost.setPosition(i * 32, j * 32);
				window.draw(sprite_Boost);
			}
		}
	}
}

void Boost::randomeBoostgenerator() {
	int randomeX = 0;//случайный X
	int randomeY = 0;//случайный Y
	srand(time(0));
	int countBoost = 20;
	while (countBoost > 0) {
		randomeX = 1 + rand() % (WIDTH_MAP - 1);//рандомное по X от 1 до ширинакарты-1, чтобы не получать числа бордюра карты
		randomeY = 1 + rand() % (HEIGHT_MAP - 1);//аналогично по Y
		if (TileMap[randomeX][randomeY] == ' ') {
			TileMap[randomeX][randomeY] = '*';
			countBoost--;
		}
		else {
			countBoost--;
		}
	}
}

Spike::Spike() {
	spike1.loadFromFile("SpikeUp_0.png");
	sprite_Spike.setTexture(spike1);
	sprite_Spike.setTextureRect(IntRect(0, 0, 32, 32));

	for (int i = 0; i < HEIGHT_MAP; i++) {
		for (int j = 0; j < WIDTH_MAP; j++) {
			if (TileMap[j][i] == '^') {
				coordinateX.push_back(j*32);
				coordinateY.push_back(i*32);
			}
		}
	}
}

void Spike::draw_spike() {
	list<int>::iterator iterX;
	list<int>::iterator iterY;
	for (iterX = coordinateX.begin(); iterX != coordinateX.end(); iterX++) {
		for (iterY = coordinateY.begin(); iterY != coordinateY.end(); iterY++) {
			sprite_Spike.setPosition(iterX, iterY);
			window.draw(sprite_Spike);
		}
	}
}

void Spike::interact(Texture sprite_ball) {
	
}

int Object::getX() {
	
}