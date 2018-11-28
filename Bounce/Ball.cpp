#pragma once
#include "Ball.h"
#include <iostream>


Ball::Ball(){
	
	pers.loadFromFile("person.png");
	pers.createMaskFromColor(pers.getPixel(0, 0));
	person.loadFromImage(pers);
	sprite.setTexture(person);
	sprite.setTextureRect(IntRect(0,0,32,32)); 
	sprite.setOrigin(15, 15);
	onGround = false;
	rect = FloatRect(465, 320, 0, 0);
	dx = 0;
	dy = 0;
	life = 4;

	//!!!!!!!!!!!!!!!ОТ ОЛЕГА!!!!!!!!!!!!!!!!!!!!!!
	//пример использования переменной с картой
	//значение нужно только проверять через if. ИЗМЕНЯТЬ НЕ НАДО
	//TileMap[0][0] = ' ';
}

void Ball::drawing_person() {


	int a, b;
	a = sprite.getPosition().x;
	b = sprite.getPosition().y;
	//std::cout << a << " " << b << " " << dy << std::endl;


	time = clock.getElapsedTime().asMicroseconds();
	clock.restart();

	time = time / 400;

	sprite.setPosition(rect.left, rect.top);


	rect.left = rect.left + dx * time;
	CollisionX();

	if (!onGround) {
		
		dy = dy + 0.0005*time;
	}
	rect.top = rect.top + dy * time;
	onGround = false;
	CollisionY();


	
	dx = 0;
	
	if (Keyboard::isKeyPressed(Keyboard::Right))
		KeyRight();


	if (Keyboard::isKeyPressed(Keyboard::Left))
		KeyLeft();

	if (Keyboard::isKeyPressed(Keyboard::Up))
		KeyUp();

	

	if (Keyboard::isKeyPressed(Keyboard::D)) {
		rect.left = 50;
		rect.top = 250;
	}
	window.draw(sprite);
}


void Ball::CollisionX() {
	for (int i = (rect.top - 15)/32; i < (rect.top + 15) / 32; i++)
		for (int j = (rect.left - 15) / 32; j < (rect.left + 15) / 32; j++)
		{
			if (TileMap[i][j] == '0' || TileMap[i][j] == 'R' || TileMap[i][j] == '-' || TileMap[i][j] == '+')
			{
				if (dx > 0) rect.left = j * 32 - 15;
				if (dx < 0) rect.left = j * 32 + 47;
				
			}

		}
}

void Ball::CollisionY() {
	for (int i = (rect.top - 15) / 32; i < (rect.top + 15) / 32; i++)
		for (int j = (rect.left - 15) / 32; j < (rect.left + 15) / 32; j++)
		{
			if ((j > WIDTH_MAP) || (i > HEIGHT_MAP)) {
				rect.left = 50;
				rect.top = 250;
			}
			else {
				if (TileMap[i][j] == '0'|| TileMap[i][j] == 'R'|| TileMap[i][j] == '-'|| TileMap[i][j] == '+')
				{
					if (dy > 0)
					{
						rect.top = i * 32 - 15;
						dy = 0;
						onGround = true;
					}
					if (dy < 0)
					{
						rect.top = i * 32 + 47;
						dy = 0;
					}
				}
			}
		}
}


void Ball::KeyRight() {
	sprite.rotate(0.5);
	dx = 0.1;
}

void Ball::KeyLeft() {
	sprite.rotate(-0.5);
	dx = -0.1;
}

void Ball::KeyUp() {
	if (onGround) {
		dy = -0.4;
		onGround = false;
	}
}

float Ball::getcoorginateX() {
	return sprite.getPosition().x;
}
float Ball::getcoorginateY() {
	return sprite.getPosition().y;
}

int Ball::damage() {
	cout << "Bol'no" << endl;
	return life--;
}