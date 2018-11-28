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
				
				cout << "Added BOOST - coordinate" ;
				cout << x <<"==="<<y<< endl;
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

int Boost::interact_boost(float ballX, float ballY) {
	HealthBar ballhp;
	auto iterY = boost_Y.begin();
	for (auto iterX = boost_X.begin(); iterX != boost_X.end(); iterX++) {
		if (((ballX >= ((*iterX))) && (ballX <= ((*iterX) + 32))) && ((ballY >= (*iterY)) && (ballY <= (*iterY) + 32))) {
			cout << "Serdce" << endl;//Вызов метода убийства
			ballhp.hpcount++;
		}
		iterY++;
	}
	return ballhp.hpcount;
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
	for (int i = 0; i < HEIGHT_MAP; i++) {
		for (int j = 0; j < WIDTH_MAP; j++) {
			if (TileMap[i][j] == '^') {
				x = 0;
				y = 0;
				sprite_Spike.setPosition(i*32, j*32);
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

int Spike::interact(float ballX,float ballY) {
	int k;
	HealthBar ballhp;
	auto iterY = coordinateY.begin();
	for (auto iterX = coordinateX.begin(); iterX != coordinateX.end(); iterX++) {
		if (((ballX>=((*iterX))) && (ballX<=((*iterX)+32))) && ((ballY >= (*iterY)) && (ballY <= (*iterY)+32))) {
			cout << "Ship" << endl;//Вызов метода убийства
			ballhp.hpcount--;
			/*ballhp.update_hpbar(ballhp.hpcount--);
			ballhp.draw_hpbar(window);*/
		}
		iterY++;
	}
	return ballhp.hpcount;
}

Door::Door() {
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

void Door::interactDoor(float ballX,float ballY) {
	auto iterY = doorY.begin();
	for (auto iterX = doorX.begin(); iterX != doorX.end(); iterX++) {
		if (((ballX >= ((*iterX))) && (ballX <= ((*iterX) + 64))) && ((ballY >= (*iterY)) && (ballY <= (*iterY) + 32))) {
			cout << "Door" << endl;//Вызов метода убийства
			
		}
		iterY++;
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
		if (k < max) {
			switch (k)
			{
			case (1):
				sprite_hpbar.setTextureRect(IntRect(0, 0, 32, 32));
				break;
			case (2):
				sprite_hpbar.setTextureRect(IntRect(0, 0, 64, 32));
				break;
			case(3):
				sprite_hpbar.setTextureRect(IntRect(0, 0, 96, 32));
				break;
			case(4):
				sprite_hpbar.setTextureRect(IntRect(0, 0, 128, 32));
				break;
			}
		}
	}
	cout << "update srabotal" << endl;
}

void HealthBar::draw_hpbar(RenderWindow &window) {
	Vector2f center = window.getView().getCenter();
	Vector2f size = window.getView().getSize();

	sprite_hpbar.setPosition(center.x - size.x / 2 + 10, center.y - size.y / 2 + 10);

	window.draw(sprite_hpbar);

	//cout << "draw srabotal" << endl;
}