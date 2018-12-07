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

spider::spider(int x, int y) {
	t.loadFromFile("spider1.png");
	sprite.setTexture(t);
	sprite.setTextureRect(IntRect(0, 0, 32, 32));
	rect = FloatRect(x * 32, y * 32, 0, 0);
	dx = -0.1;
	currentFrame = 0;
}

bee::bee(int x, int y) {
	t.loadFromFile("wasp1.png");
	sprite.setTexture(t);
	sprite.setTextureRect(IntRect(0, 0, 32, 32));
	rect = FloatRect(x*32, y*32, 0, 0);
	dx = -0.05;
	currentFrame = 0;
	
}

void enemy::drawing(float ballX, float ballY, Ball &ballhp) {
	time = clock.getElapsedTime().asMicroseconds();
	clock.restart();

	time = time / 400;

	sprite.setPosition(rect.left, rect.top);

	rect.left = rect.left + dx * time;
	collision();
	
	currentFrame += 0.005 * time; // для анимации 
	if (currentFrame > 4)  currentFrame -= 4;
	if (dx < 0) sprite.setTextureRect(IntRect(32 * int(currentFrame), 0, 32, 32));
	if (dx > 0) sprite.setTextureRect(IntRect(32 * int(currentFrame) + 32, 0, -32, 32));


	window.draw(sprite);



	if ((ballY>=(rect.top-15))&&(ballY<=(rect.top+32+15))&&(ballX>=(rect.left-15)&&(ballX<=(rect.left+32+15)))) {
		ballhp.Damage();
	}
}

FloatRect enemy::FL() {//передает в main положение врага
	return rect;
}
float enemy::DX() {//передает в main направление движения врага
	return dx;
}

enemy::Bullet::Bullet(FloatRect rect, float loc_dx) {
	bullet_rect = rect;//получает координату врага
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