#include "enemy.h"
#include<iostream>  


void enemy::collision() {
 
	for (int i = (rect.top) / 32; i < (rect.top + 32) / 32; i++)
		for (int j = (rect.left) / 32; j < (rect.left + 32) / 32; j++)
		{
			if (TileMap[i][j] == '0')
			{
				if (dx > 0) { rect.left = j * 32 - 32; }
				if (dx < 0) { rect.left = j * 32 + 32; }
				dx = dx * -1;
			}
		}
			
}



bee::bee(int x, int y) {
	t.loadFromFile("wasp1.png");
	sprite.setTexture(t);
	sprite.setTextureRect(IntRect(0, 0, 32, 32));
	rect = FloatRect(x*32, y*32, 0, 0);
	dx = -0.05;
	
}

void bee::drawing() {
	time = clock.getElapsedTime().asMicroseconds();
	clock.restart();

	time = time / 400;

	sprite.setPosition(rect.left, rect.top);

	rect.left = rect.left + dx * time;
	collision();
	
	window.draw(sprite);
}

FloatRect enemy::FL() {
	return rect;
}
float enemy::DX() {
	return dx;
}

enemy::Bullet::Bullet(FloatRect rect, float loc_dx) {
	bullet_rect = rect;
	//std::cout << bullet_rect.left<< bullet_rect.top;
	life = true;
	im.loadFromFile("bullet.png");
	im.createMaskFromColor(Color::Black);
	t.loadFromImage(im);
	sprite.setTexture(t);
	dx = loc_dx*(-3);
}

void enemy::Bullet::drawing() {
	time = clock.getElapsedTime().asMicroseconds();
	clock.restart();
	time = time / 400;
	sprite.setPosition(bullet_rect.left, bullet_rect.top);
	bullet_rect.left = bullet_rect.left + dx * time;
	collisionBullet();

	window.draw(sprite);
}

void enemy::Bullet::collisionBullet() {

	for (int i = (bullet_rect.top) / 32; i < (bullet_rect.top + 32) / 32; i++)
		for (int j = (bullet_rect.left) / 32; j < (bullet_rect.left + 32) / 32; j++)
		{
			if (TileMap[i][j] == '0')
			{
				life = false;
			}
		}

}

enemy::Bullet::~Bullet() {
	
}

void enemy::Bullet::destroyBall(Ball &ball) {
		if ((((ball.getcoorginateX()) >= ((bullet_rect.left))) && ((ball.getcoorginateX()) <= ((bullet_rect.left)+10))) && (((ball.getcoorginateY()) >= (bullet_rect.top)) && ((ball.getcoorginateY()) <= (bullet_rect.top) + 32))) {
			life = false;
			ball.Damage();
			return;
		}
	}