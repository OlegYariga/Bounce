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
	life = true;
	rect_spike = FloatRect(0, 0, 32, 32);
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
				cout << x << endl;
				rect_spike = FloatRect(i, j, 32, 32);
			}
		}
	}

	auto iterY = coordinateY.begin();
	for (auto iter = coordinateX.begin(); iter != coordinateX.end(); iter++) {
		cout << *iter <<" ; "<<*iterY<< endl;
		iterY++;
	}
}

void Spike::draw_spike() {
	auto iterY = coordinateY.begin();
	for (auto iter = coordinateX.begin(); iter != coordinateX.end(); iter++) {
		sprite_Spike.setPosition(*iterY, *iter);
		iterY++;
		window.draw(sprite_Spike);
	}
}

void Spike::interact(float ballX,float ballY) {
	/*Spike spike_test;
	Ball ball_test;
	if (spike_test.rect_spike.intersects(ball_test.rect)) {
		cout << "-Ball" << endl;
	}*/
	auto iterY = coordinateY.begin();
	for (auto iterX = coordinateX.begin(); iterX != coordinateX.end(); iterX++) {
		if ((ballX < (*iterX)) && (ballY < (*iterY)) && (name == "Spike")) {
			cout << "-Ball" << endl;
			iterY++;
		}
	}
}

Door::Door() {
	name = "Door";
	door1.loadFromFile("door.png");
	sprite_Door.setTexture(door1);
	sprite_Door.setTextureRect(IntRect(0, 0, 64, 32));
}

void Door::drawDoor() {
	for (int i = 0; i < HEIGHT_MAP; i++) {
		for (int j = 0; j < WIDTH_MAP; j++) {
			if (TileMap[j][i] == 'D') {
				sprite_Door.setPosition(i * 32, j * 32);
				window.draw(sprite_Door);
			}
		}
	}
}

void Door::openDoor(float time) {

	float CurrentFrame = 0;
	if ((Keyboard::isKeyPressed(Keyboard::U))) {
		CurrentFrame += 0.005*time;
		if (CurrentFrame > 3) CurrentFrame = -3;
		sprite_Door.setTextureRect(IntRect(0, 32 * int(CurrentFrame), 64, 32));
	}
}