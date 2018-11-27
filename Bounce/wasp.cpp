#include "wasp.h"
#include "drawMaps.h"
#include "engine.h"
#include <iostream>
#include <time.h>
#include <Windows.h>
using namespace std;




Wasp::Wasp() { // конструктор

	t.loadFromFile("wasp1.png");
	killer_wasp.setTexture(t);
	killer_wasp.setTextureRect(IntRect(0, 0, 35, 35));
	killer_wasp.setPosition(610, 314);

	k_rect = FloatRect(610, 314, 0, 0);
	k_currentFrame = 0;

}

void Wasp::show_wasp()
{
	for (int i = 0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			if (TileMap[i][j] == 'A')
			{
				killer_wasp.setTextureRect(IntRect(0, 0, 35, 35));// нужный прямоугольник с осой
				killer_wasp.setPosition(j * 32, i * 32);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один 
				
				k_rect.left = j * 32;
				k_rect.top = i * 32;
			}
		}
}




void Wasp::move_wasp(float time)
{

	k_rect.left += x * time; // X

	k_currentFrame += 5 * time; // для анимации 
	if (k_currentFrame > 4)  k_currentFrame -= 4;
	if (x < 0) killer_wasp.setTextureRect(IntRect(35 * int(k_currentFrame), 0, 34, 35));
	if (x > 0) killer_wasp.setTextureRect(IntRect(35 * int(k_currentFrame) + 35, 0, -34, 35));

	collision_K();
	killer_wasp.setPosition(k_rect.left, k_rect.top);

	//cout << x << endl;

}




void Wasp::collision_K()
{
	for (int i = k_rect.top / 32; i < (k_rect.top + 15) / 32; i++)
		for (int j = k_rect.left / 32; j < (k_rect.left + 15) / 32; j++)
		{
			if (TileMap[int(k_rect.top / 32)][int((k_rect.left / 32) + 1)] == '0')
			{
				x *= -1; k_rect.left = k_rect.left - 2;
			}
			else if (TileMap[int(k_rect.top / 32)][int((k_rect.left / 32))] == '0')
			{
				x *= -1; k_rect.left = k_rect.left + 2;
			}

			


		}

}