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
	dx = -0.1;
	
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