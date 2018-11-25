#pragma once
#include "Boost.h"
#include "engine.h"
#include "Ball.h"


Boost::Boost() {
	name = "Buff";
	buff.loadFromFile("heart_0.png");
	sprite_Boost.setTexture(buff);
	sprite_Boost.setTextureRect(IntRect(0, 0, 32, 32));
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
	name = "Spike";
	spike1.loadFromFile("SpikeUp_0.png");
	sprite_Spike.setTexture(spike1);
	sprite_Spike.setTextureRect(IntRect(0, 0, 32, 32));
	cout << "Сам пошёл нахер" << endl;
}

void Spike::find_spike() {
	for (int i = 0; i < WIDTH_MAP; i++) {
		for (int j = 0; j < HEIGHT_MAP; j++) {
			if (TileMap[i][j] == '^') {
				sprite_Spike.setPosition(i*32, j*32);
				x = sprite_Spike.getPosition().x;
				y = sprite_Spike.getPosition().y;
				coordinateX.push_back(x);
				coordinateY.push_back(y);
				cout << "Something" << endl;
			}
		}
	}
	for (auto iter = coordinateX.begin(); iter != coordinateX.end(); iter++) {
		cout << *iter << endl;
	}
	for (auto iter = coordinateY.begin(); iter != coordinateY.end(); iter++) {
		cout << *iter << endl;
	}
}

void Spike::draw_spike() {
	for (auto iter = coordinateX.begin(); iter != coordinateX.end(); iter++) {
		cout << *iter << endl;
	}
	for (auto iter = coordinateY.begin(); iter != coordinateY.end(); iter++) {
		cout << *iter << endl;
	}
	for (auto iterX = coordinateX.begin(); iterX != coordinateX.end(); iterX++) {
		for (auto iterY = coordinateY.begin(); iterY != coordinateY.end(); iterY++) {
			sprite_Spike.setPosition((*iterX) * 32, (*iterY) * 32);
			window.draw(sprite_Spike);
		}
	}
}

void Spike::interact(Texture sprite_ball) {
	
}

int Object::getX() {
	
}