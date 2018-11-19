#pragma once
#include "Ball.h"


Ball::Ball(){
	person.loadFromFile("person.png");
	sprite.setTexture(person);
	sprite.setTextureRect(IntRect(20,110,100,80)); 
	sprite.setPosition(50, 300);

}

void Ball::drawing_person() {

	//window.draw(sprite); »нклужу engine.h, получаю ошибку компил€ции
}

void Ball::KeyRight() {

	sprite.move(0.1, 0);
}

void Ball::KeyLeft() {

	sprite.move(-0.1, 0);
}