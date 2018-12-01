#pragma once
#include "Ball.h"
#include <iostream>


Ball::Ball() {

	pers.loadFromFile("person.png");
	pers.createMaskFromColor(pers.getPixel(0, 0));
	person.loadFromImage(pers);
	sprite.setTexture(person);
	sprite.setTextureRect(IntRect(0, 0, 32, 32));
	sprite.setOrigin(15, 15);


	rect = FloatRect(0, 0, 0, 0);
	defrect = FloatRect(0, 0, 0, 0);
	onGround = false;
	InvertedGravity = false;
	dx = 0;
	dy = 0;
	lifes = 4;

	//!!!!!!!!!!!!!!!?? ?????!!!!!!!!!!!!!!!!!!!!!!
	//?????? ????????????? ?????????? ? ??????
	//???????? ????? ?????? ????????? ????? if. ???????? ?? ????
	//TileMap[0][0] = ' ';
}

void Ball::drawing_person() {


	int a, b;
	a = sprite.getPosition().x;
	b = sprite.getPosition().y;
	//std::cout << a << " " << b << " " << dy << std::endl;

	GetDefPos();


	time = clock.getElapsedTime().asMicroseconds();
	clock.restart();

	time = time / 400;

	sprite.setPosition(rect.left, rect.top);


	rect.left = rect.left + dx * time;
	CollisionX();

	if (!onGround)
	{
		if (InvertedGravity)
		{
			if (dy > -0.1)
				dy = dy - 0.0005*time;
		}
		else
		{
			if (dy < 0.1)
				dy = dy + 0.0005*time;
		}

	}

	rect.top = rect.top + dy * time;
	onGround = false;
	CollisionY();


	dx = 0;

	if (Keyboard::isKeyPressed(Keyboard::Right))
		KeyRight(0.1);


	if (Keyboard::isKeyPressed(Keyboard::Left))
		KeyLeft(-0.1);

	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		if (InvertedGravity)
		{
			KeyUp(0.4);
		}
		else
		{
			KeyUp(-0.4);
		}
	}




	if (Keyboard::isKeyPressed(Keyboard::D)) {
		//rect.left = defrect.left;
		//rect.top = defrect.top;
		setInvertedGravity();
	}
	if (Keyboard::isKeyPressed(Keyboard::R)) {
		rect.left = defrect.left;
		rect.top = defrect.top;
	}
	if (Keyboard::isKeyPressed(Keyboard::F)) {
		setNormalGravity();
	}
	window.draw(sprite);
}


void Ball::CollisionX() {
	for (int i = (rect.top - 15) / 32; i < (rect.top + 15) / 32; i++)
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
			if ((j > WIDTH_MAP) || (j < 0) || (i > HEIGHT_MAP) || (i < 0)) {
				dy = 0;
				rect.left = defrect.left;
				rect.top = defrect.top;

			}
			else {
				if (TileMap[i][j] == '0' || TileMap[i][j] == 'R' || TileMap[i][j] == '-' || TileMap[i][j] == '+')
				{
					if (dy > 0)
					{
						rect.top = i * 32 - 15;
						dy = 0;
						if (!InvertedGravity)
						{
							onGround = true;
						}
					}
					if (dy < 0)
					{
						rect.top = i * 32 + 47;
						dy = 0;
						if (InvertedGravity)
						{
							onGround = true;
						}
					}
				}
			}
		}
}


void Ball::GetDefPos() {
	for (int i = 0; i < HEIGHT_MAP; i++) {
		for (int j = 0; j < WIDTH_MAP; j++) {

			if (TileMap[i][j] == 'B') {
				defrect = FloatRect(j * 32, i * 32, 0, 0);
			}
		}
	}
}

void Ball::setInvertedGravity()
{
	InvertedGravity = true;
}

void Ball::setNormalGravity()
{
	InvertedGravity = false;
}

void Ball::Damage() {
	rect = defrect;
	lifes--;
	//std::cout << "WORK!";
}

void Ball::Healing() {
	lifes++;
}

void Ball::KeyRight(float a) {
	sprite.rotate(0.5);
	dx = a;
}

void Ball::KeyLeft(float a) {
	sprite.rotate(-0.5);
	dx = a;
}

void Ball::KeyUp(float a) {
	if (onGround) {
		dy = a;
		onGround = false;
	}
}

float Ball::getcoorginateX() {
	return sprite.getPosition().x;
}
float Ball::getcoorginateY() {
	return sprite.getPosition().y;
}

int Ball::getLife() {
	//std::cout << lifes;
	return lifes;
}