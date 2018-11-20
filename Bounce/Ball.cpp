#pragma once
#include "Ball.h"


Ball::Ball(){
	person.loadFromFile("person.png");
	sprite.setTexture(person);
	sprite.setTextureRect(IntRect(20,110,100,80)); 
	sprite.setPosition(50, 300);


	//!!!!!!!!!!!!!!!ОТ ОЛЕГА!!!!!!!!!!!!!!!!!!!!!!
	//пример использования переменной с картой
	//значение нужно только проверять через if. ИЗМЕНЯТЬ НЕ НАДО
	TileMap[0][0] = ' ';
}

void Ball::drawing_person() {

	window.draw(sprite);// Инклужу engine.h, получаю ошибку компиляции// ИСПРАВИЛ
}

void Ball::KeyRight() {

	sprite.move(0.1, 0);
}

void Ball::KeyLeft() {

	sprite.move(-0.1, 0);
}