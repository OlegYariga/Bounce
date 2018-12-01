#pragma once
#include "Boost.h"
#include "engine.h"
#include "Ball.h"
#include <vector>
#include <list>

Boost::Boost() {
	name = "Buff";
	buff_im.loadFromFile("heart_0.png");
	buff_im.createMaskFromColor(Color::White);
	buff.loadFromImage(buff_im);
	sprite_Boost.setTexture(buff);
	sprite_Boost.setTextureRect(IntRect(0, 0, 32, 32));
}

void Boost::findBoost() {
	for (int i = 0; i < HEIGHT_MAP; i++) {
		for (int j = 0; j < WIDTH_MAP; j++) {
			if (TileMap[i][j] == '*') {
				x = 0;
				y = 0;
				sprite_Boost.setPosition(i * 32, j * 32);
				x = sprite_Boost.getPosition().x;
				y = sprite_Boost.getPosition().y;
				boost_X.push_back(y);
				boost_Y.push_back(x);

				cout << "Added BOOST - coordinate";
				cout << x << "===" << y << endl;
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

int Boost::interact_boost(float ballX, float ballY, Ball &ballhp) {
	int hpcount = ballhp.getLife();
	int x, y;
	if (hpcount < 4) {
		auto iterY = boost_Y.begin();
		for (auto iterX = boost_X.begin(); iterX != boost_X.end(); iterX++) {
			//std::cout << "X===" << *iterX << "Y===" << *iterY<<endl;
			if (((ballX >= ((*iterX))) && (ballX <= ((*iterX) + 32))) && ((ballY >= (*iterY)) && (ballY <= (*iterY) + 32))) {
				cout << "Serdce" << endl;//????? ?????? ????????
				//hpcount=ballhp.life++;
				ballhp.Healing();
				boost_X.remove(*iterX);
				boost_Y.remove(*iterY);
				return hpcount;
			}
			iterY++;
		}
	}
	//cout << "K v interact_boost = " << hpcount << endl;
	return hpcount;
}

void Boost::randomeBoostgenerator() {
	int randomeX = 0;//????????? X
	int randomeY = 0;//????????? Y
	srand(time(0));
	int countBoost = 5;
	while (countBoost > 0) {
		randomeX = 1 + rand() % (WIDTH_MAP - 1);//????????? ?? X ?? 1 ?? ???????????-1, ????? ?? ???????? ????? ??????? ?????
		randomeY = 1 + rand() % (HEIGHT_MAP - 1);//?????????? ?? Y
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
	for (int i = 0; i < HEIGHT_MAP; i++) {
		for (int j = 0; j < WIDTH_MAP; j++) {
			if (TileMap[i][j] == '^') {
				x = 0;
				y = 0;
				sprite_Spike.setPosition(i * 32, j * 32);
				x = sprite_Spike.getPosition().x;
				y = sprite_Spike.getPosition().y;
				coordinateX.push_back(y);
				coordinateY.push_back(x);

				cout << "Added SPIKE - coordinate";
				cout << x << endl;
				//rect_spike = FloatRect(i, j, 32, 32);
			}
		}
	}

}

void Spike::draw_spike() {
	auto iterY = coordinateY.begin();
	for (auto iter = coordinateX.begin(); iter != coordinateX.end(); iter++) {
		sprite_Spike.setPosition(*iter, *iterY);

		window.draw(sprite_Spike);
		iterY++;

	}
}

int Spike::interact(float ballX, float ballY, Ball &ballhp) {
	int hpcount = ballhp.getLife();
	auto iterY = coordinateY.begin();
	for (auto iterX = coordinateX.begin(); iterX != coordinateX.end(); iterX++) {
		if (((ballX >= ((*iterX))) && (ballX <= ((*iterX) + 32))) && ((ballY >= (*iterY)) && (ballY <= (*iterY) + 32))) {
			//std::cout << hpcount;
			ballhp.Damage();
			return hpcount;
		}
		iterY++;
	}
	//cout <<"K v interact_spike = " <<hpcount << endl;
	return hpcount;
}

Door::Door() {
	isOpen = false;
	name = "Door";
	door1.loadFromFile("door.png");
	sprite_Door.setTexture(door1);
	sprite_Door.setTextureRect(IntRect(0, 0, 64, 32));
}

void Door::findDoor() {
	for (int i = 0; i < HEIGHT_MAP; i++) {
		for (int j = 0; j < WIDTH_MAP; j++) {
			if (TileMap[i][j] == 'D') {
				x = 0;
				y = 0;
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

bool Door::interactDoor(float ballX, float ballY) {
	auto iterY = doorY.begin();
	for (auto iterX = doorX.begin(); iterX != doorX.end(); iterX++) {
		if (((ballX >= ((*iterX))) && (ballX <= ((*iterX) + 64))) && ((ballY >= (*iterY)) && (ballY <= (*iterY) + 32))) {
			if (isOpen) {
				cout << "Door" << endl;//????? ?????? ????????
				return true;
			}
		}
		iterY++;
	}
	return false;
}

void Door::openDoor(float time) {

	float CurrentFrame = 0;
	if ((Keyboard::isKeyPressed(Keyboard::U))) {
		CurrentFrame += 0.005*time;
		if (CurrentFrame > 3) CurrentFrame = -3;
		sprite_Door.setTextureRect(IntRect(0, 32 * int(CurrentFrame), 64, 32));
	}
}

HealthBar::HealthBar() {
	image_hpbar.loadFromFile("health_bar.png");
	image_hpbar.createMaskFromColor(Color::White);
	texture_hpbar.loadFromImage(image_hpbar);
	sprite_hpbar.setTexture(texture_hpbar);
	sprite_hpbar.setTextureRect(IntRect(0, 0, 128, 32));
	max = 4;
	hpcount = max;
}

void HealthBar::update_hpbar(int k) {
	if (k > 0) {
		if (k <= max) {
			switch (k)
			{
			case (1):
				sprite_hpbar.setTextureRect(IntRect(0, 0, 32, 32));
				//cout << "update srabotal" << endl;
				break;
			case (2):
				sprite_hpbar.setTextureRect(IntRect(0, 0, 64, 32));
				//cout << "update srabotal" << endl;
				break;
			case(3):
				sprite_hpbar.setTextureRect(IntRect(0, 0, 96, 32));
				//cout << "update srabotal" << endl;
				break;
			case(4):
				sprite_hpbar.setTextureRect(IntRect(0, 0, 128, 32));
				//cout << "update srabotal" << endl;
				break;
			}
		}
	}
}

void HealthBar::draw_hpbar(RenderWindow &window) {
	Vector2f center = window.getView().getCenter();
	Vector2f size = window.getView().getSize();

	sprite_hpbar.setPosition(center.x - size.x / 2 + 10, center.y - size.y / 2 + 10);

	window.draw(sprite_hpbar);

	//cout << "draw srabotal" << endl;
}

Key::Key() {
	name = "Key";
	key_im.loadFromFile("key.png");
	//key_im.createMaskFromColor(Color::White);
	key_tx.loadFromImage(key_im);
	sprite_Key.setTexture(key_tx);
	sprite_Key.setTextureRect(IntRect(0, 0, 32, 32));
}

void Key::findKey() {
	for (int i = 0; i < HEIGHT_MAP; i++) {
		for (int j = 0; j < WIDTH_MAP; j++) {
			if (TileMap[i][j] == 'K') {
				x = 0;
				y = 0;
				sprite_Key.setPosition(i * 32, j * 32);
				x = sprite_Key.getPosition().x;
				y = sprite_Key.getPosition().y;
				key_X.push_back(y);
				key_Y.push_back(x);

				cout << "Added BOOST - coordinate";
				cout << x << "===" << y << endl;
			}
		}
	}

}

void Key::drawKey() {
	auto iterY = key_Y.begin();
	for (auto iter = key_X.begin(); iter != key_X.end(); iter++) {
		sprite_Key.setPosition(*iter, *iterY);
		iterY++;
		window.draw(sprite_Key);
	}
}

void Key::interactKey(float ballX, float ballY, Door &door) {
	int x, y;
	auto iterY = key_Y.begin();
	for (auto iterX = key_X.begin(); iterX != key_X.end(); iterX++) {
		if (((ballX >= ((*iterX))) && (ballX <= ((*iterX) + 32))) && ((ballY >= (*iterY)) && (ballY <= (*iterY) + 32))) {
			cout << "Key" << endl;//????? ?????? ????????
			door.isOpen = true;
			key_X.remove(*iterX);
			key_Y.remove(*iterY);
			return;
		}
		iterY++;
	}
	//cout << "K v interact_boost = " << door.isOpen << endl;
}

GravityDown::GravityDown() {
	GD_im.loadFromFile("sprGravityDown_0.png");
	GD_tx.loadFromImage(GD_im);
	GD_sp.setTexture(GD_tx);
	GD_sp.setTextureRect(IntRect(0, 0, 32, 32));
}

void GravityDown::findGD() {
	for (int i = 0; i < HEIGHT_MAP; i++) {
		for (int j = 0; j < WIDTH_MAP; j++) {
			if (TileMap[i][j] == '2') {
				x = 0;
				y = 0;
				GD_sp.setPosition(i * 32, j * 32);
				x = GD_sp.getPosition().x;
				y = GD_sp.getPosition().y;
				GD_X.push_back(y);
				GD_Y.push_back(x);

				cout << "Added BOOST - coordinate";
				cout << x << "===" << y << endl;
			}
		}
	}
}

void GravityDown::drawGD() {
	auto iterY = GD_Y.begin();
	for (auto iter = GD_X.begin(); iter != GD_X.end(); iter++) {
		GD_sp.setPosition(*iter, *iterY);
		iterY++;
		window.draw(GD_sp);
	}
}

void GravityDown::interactGD(float ballX, float ballY, Ball &ball) {
	auto iterY = GD_Y.begin();
	for (auto iterX = GD_X.begin(); iterX != GD_X.end(); iterX++) {
		if (((ballX >= ((*iterX))) && (ballX <= ((*iterX) + 32))) && ((ballY >= (*iterY)) && (ballY <= (*iterY) + 32))) {
			cout << "GravityDown" << endl;//????? ?????? ????????
			ball.setNormalGravity();
			return;
		}
		iterY++;
	}
	//cout << "K v interact_boost = " << door.isOpen << endl;
}

GravityUp::GravityUp() {
	GU_im.loadFromFile("sprGravityUp_0.png");
	GU_tx.loadFromImage(GU_im);
	GU_sp.setTexture(GU_tx);
	GU_sp.setTextureRect(IntRect(0, 0, 32, 32));
}

void GravityUp::findGU() {
	for (int i = 0; i < HEIGHT_MAP; i++) {
		for (int j = 0; j < WIDTH_MAP; j++) {
			if (TileMap[i][j] == '8') {
				x = 0;
				y = 0;
				GU_sp.setPosition(i * 32, j * 32);
				x = GU_sp.getPosition().x;
				y = GU_sp.getPosition().y;
				GU_X.push_back(y);
				GU_Y.push_back(x);

				cout << "Added BOOST - coordinate";
				cout << x << "===" << y << endl;
			}
		}
	}
}

void GravityUp::drawGU() {
	auto iterY = GU_Y.begin();
	for (auto iter = GU_X.begin(); iter != GU_X.end(); iter++) {
		GU_sp.setPosition(*iter, *iterY);
		iterY++;
		window.draw(GU_sp);
	}
}

void GravityUp::interactGU(float ballX, float ballY, Ball &ball) {
	auto iterY = GU_Y.begin();
	for (auto iterX = GU_X.begin(); iterX != GU_X.end(); iterX++) {
		if (((ballX >= ((*iterX))) && (ballX <= ((*iterX) + 32))) && ((ballY >= (*iterY)) && (ballY <= (*iterY) + 32))) {
			cout << "GravityUp" << endl;//????? ?????? ????????
			ball.setInvertedGravity();
			return;
		}
		iterY++;
	}
	//cout << "K v interact_boost = " << door.isOpen << endl;
}