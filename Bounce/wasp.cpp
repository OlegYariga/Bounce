#include "wasp.h"
#include "drawMaps.h"
#include "engine.h"
#include <iostream>
#include <vector>
#include <list>
using namespace std;

Killer::Killer() {};
Killer::Killer(String F, char A, int X, int Y, int W, int H) {
	File = F;
	a = A;
	w = W; h = H;
	x = X; y = Y;
	t.loadFromFile(File);
	killer_sprite.setTexture(t);
	killer_sprite.setTextureRect(IntRect(x, y, w, h));
	k_rect = FloatRect(610, 314, 0, 0);
};

 

Wasp::Wasp()  { k_rect = FloatRect(610, 314, 0, 0); };
Wasp::Wasp (String F,char A, int X, int Y, float W, float H) : Killer(F,A,X,Y, W, H){ // конструктор
	
	k_currentFrame = 0;
	x = 500;
	show_wasp();
	
}

Spider::Spider() { k_rect = FloatRect(610, 314, 0, 0); };
Spider::Spider(String F, char A, int X, int Y, float W, float H) : Killer(F, A, X, Y, W, H) { // конструктор

	k_currentFrame = 0;
	x = 400;
	show_wasp();

}

void Killer::show_wasp()
{
	
	int n = 0;
	for (int i = 0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			if (TileMap[i][j] == a)
			{
				killer_sprite.setTextureRect(IntRect(x, y, w, h));// нужный прямоугольник с осой
				killer_sprite.setPosition(j * 32, i * 32);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один 

				k_rect.left = j * 32;
				k_rect.top = i * 32;
				
				cout << k_rect.top << endl;
				//arr[n]=new Wasp;
				//arr[n]->k_rect; 
				//n++;
			
			};	
		};
}


void Killer::move_wasp(float time)
{
	

	k_rect.left += x * time; // X

	k_currentFrame += 5 * time; // для анимации 
	if (k_currentFrame > 4)  k_currentFrame -= 4;
	if (x < 0) killer_sprite.setTextureRect(IntRect(w * int(k_currentFrame), y, w, h));
	if (x > 0) killer_sprite.setTextureRect(IntRect(w * int(k_currentFrame) + w, y, -w, h));

	collision_K();
	killer_sprite.setPosition(k_rect.left, k_rect.top);
	
	//cout << x << endl;

}

void Killer::collision_K()
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


