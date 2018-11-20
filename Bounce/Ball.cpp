#pragma once
#include "Ball.h"


Ball::Ball(){
	pers.loadFromFile("person.png");
	pers.createMaskFromColor(pers.getPixel(0, 0));
	person.loadFromImage(pers);
	sprite.setTexture(person);
	sprite.setTextureRect(IntRect(0,0,30,30)); 
	sprite.setPosition(50, 300);


	//!!!!!!!!!!!!!!!�� �����!!!!!!!!!!!!!!!!!!!!!!
	//������ ������������� ���������� � ������
	//�������� ����� ������ ��������� ����� if. �������� �� ����
	//TileMap[0][0] = ' ';
}

void Ball::drawing_person() {

	window.draw(sprite);// ������� engine.h, ������� ������ ����������// ��������
}

void Ball::KeyRight() {

	sprite.move(0.1, 0);
}

void Ball::KeyLeft() {

	sprite.move(-0.1, 0);
}