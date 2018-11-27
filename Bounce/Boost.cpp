#pragma once
#include "Boost.h"
#include "engine.h"
#include "Ball.h"


Boost::Boost() {
	name = "Buff";
	buff_im.loadFromFile("heart_0.png");
	buff_im.createMaskFromColor(Color::White);
	buff.loadFromImage(buff_im);
	sprite_Boost.setTexture(buff);
	sprite_Boost.setTextureRect(IntRect(0, 0, 32, 32));
}

void Boost::findBoost() {
	for (int i = 0; i < WIDTH_MAP; i++) {
		for (int j = 0; j < HEIGHT_MAP; j++) {
			if (TileMap[i][j] == '*') {
				sprite_Boost.setPosition(i * 32, j * 32);
				x = sprite_Boost.getPosition().x;
				y = sprite_Boost.getPosition().y;
				boost_X.push_back(y);
				boost_Y.push_back(x);
				cout << "Something" << endl;
				cout << x << endl;
			}
		}
	}
}

void Boost::drawBoost() {
	auto iterY = boost_Y.begin();
	for (auto iter = boost_X.begin(); iter != boost_X.end(); iter++) {
		sprite_Boost.setPosition(*iter, *iterY);
		iterY++;
		window.draw(sprite_Boost);
	}
}

void Boost::interact_boost(float ballX, float ballY) {
	auto iterY = boost_Y.begin();
	for (auto iterX = boost_X.begin(); iterX != boost_X.end(); iterX++) {
		if (((ballX >= ((*iterX))) && (ballX <= ((*iterX) + 32))) && ((ballY >= (*iterY)) && (ballY <= (*iterY) + 32))) {
			cout << "Serdce" << endl;//Вызов метода убийства
			iterY++;
		}
	}
}

void Boost::randomeBoostgenerator() {
	int randomeX = 0;//случайный X
	int randomeY = 0;//случайный Y
	srand(time(0));
	int countBoost = 5;
	while (countBoost > 0) {
		randomeX = 1 + rand() % (WIDTH_MAP - 1);//рандомное по X от 1 до ширинакарты-1, чтобы не получать числа бордюра карты
		randomeY = 1 + rand() % (HEIGHT_MAP - 1);//аналогично по Y
		if (TileMap[randomeX][randomeY] == ' ') {
			TileMap[randomeX][randomeY] = '*';
			sprite_Boost.setPosition(randomeX * 32, randomeY * 32);
			x = sprite_Boost.getPosition().x;
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
	rect_spike = FloatRect(0, 0, 32, 32);
}

void Spike::find_spike() {
	for (int i = 0; i < WIDTH_MAP; i++) {
		for (int j = 0; j < HEIGHT_MAP; j++) {
			if (TileMap[i][j] == '^') {
				sprite_Spike.setPosition(i*32, j*32);
				x = sprite_Spike.getPosition().x;
				y = sprite_Spike.getPosition().y;
				coordinateX.push_back(y);
				coordinateY.push_back(x);
				cout << "Something" << endl;
				cout << x << endl;
				//rect_spike = FloatRect(i, j, 32, 32);
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
		sprite_Spike.setPosition(*iter, *iterY);
		iterY++;
		window.draw(sprite_Spike);
	}
}

void Spike::interact(float ballX,float ballY) {
	auto iterY = coordinateY.begin();
	for (auto iterX = coordinateX.begin(); iterX != coordinateX.end(); iterX++) {
		if (((ballX>=((*iterX))) && (ballX<=((*iterX)+32))) && ((ballY >= (*iterY)) && (ballY <= (*iterY)+32))) {
			cout << "Ship" << endl;//Вызов метода убийства
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

void Door::findDoor() {
	for (int i = 0; i < WIDTH_MAP; i++) {
		for (int j = 0; j < HEIGHT_MAP; j++) {
			if (TileMap[i][j] == 'D') {
				sprite_Door.setPosition(i * 32, j * 32);
				x = sprite_Door.getPosition().x;
				y = sprite_Door.getPosition().y;
				doorX.push_back(y);
				doorY.push_back(x);
				cout << "Door" << endl;
				cout << x << endl;
			}
		}
	}
}

void Door::drawDoor() {
	auto iterY = doorY.begin();
	for (auto iter = doorX.begin(); iter != doorX.end(); iter++) {
		sprite_Door.setPosition(*iter, *iterY);
		iterY++;
		window.draw(sprite_Door);
	}
}

void Door::interactDoor(float ballX,float ballY) {
	auto iterY = doorY.begin();
	for (auto iterX = doorX.begin(); iterX != doorX.end(); iterX++) {
		if (((ballX >= ((*iterX))) && (ballX <= ((*iterX) + 64))) && ((ballY >= (*iterY)) && (ballY <= (*iterY) + 32))) {
			cout << "Door" << endl;//Вызов метода убийства
			iterY++;
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