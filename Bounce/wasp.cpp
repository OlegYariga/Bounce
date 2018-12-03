#include "wasp.h"
#include "drawMaps.h"
#include "engine.h"
#include "Ball.h"
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
	k_rect = FloatRect(0, 0, 0, 0);
};




Wasp::Wasp(String F, char A, int X, int Y, float W, float H) : Killer(F, A, X, Y, W, H) { // конструктор

	k_currentFrame = 0;
	x = 500;
	show_wasp();
	
}


Spider::Spider(String F, char A, int X, int Y, float W, float H) : Killer(F, A, X, Y, W, H)
{ // конструктор

	k_currentFrame = 0;
	x = 400;
	show_wasp();
}


void Killer::show_wasp()
{
	
	for (int i = 0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			if (TileMap[i][j] == a)
			{
				
				killer_sprite.setTextureRect(IntRect(x, y, w, h));// нужный прямоугольник с осой
				killer_sprite.setPosition(j * 32, i * 32);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один 
				killer_sprite.setOrigin(15, 15);

				k_rect.left = j * 32;
				k_rect.top = i * 32;
				
				if (a == 'A')
				{
					wasp_X.push_back(k_rect.left);
					wasp_Y.push_back(k_rect.top);
					//List_X.push_back(x);
					
				}

				if (a == 'S')
				{
					spid_X.push_back(k_rect.left);
					spid_Y.push_back(k_rect.top);
					continue;
				}

				
			}
		}	
}
void Killer::drawWasp() {
	auto iterY = wasp_Y.begin();

	for (auto iter = wasp_X.begin(); iter != wasp_X.end(); iter++)
	{
		killer_sprite.setPosition(*iter, *iterY);

		iterY++;
		window.draw(killer_sprite);
	}
}

void Killer:: drawSpider() {
	auto iterY = spid_Y.begin();

	for (auto iter = spid_X.begin(); iter != spid_X.end(); iter++)
	{
		killer_sprite.setPosition(*iter, *iterY);

		iterY++;
		window.draw(killer_sprite);
	}
}



void Killer::move_wasp(float time, float ballX, float ballY, Ball &ballhp)
{
	
	auto iterY = wasp_Y.begin();

	for (auto iter = wasp_X.begin(); iter != wasp_X.end(); iter++)
	{
		killer_sprite.setPosition(*iter, *iterY);
		 
		*iter += x * time; // X

		//killer_sprite.setPosition(k_rect.left, k_rect.top);
		//k_rect.left += x * time; // X

		k_currentFrame += 5 * time; // для анимации 
		if (k_currentFrame > 4)  k_currentFrame -= 4;
		if (x < 0) killer_sprite.setTextureRect(IntRect(w * int(k_currentFrame), y, w, h));
		if (x > 0) killer_sprite.setTextureRect(IntRect(w * int(k_currentFrame) + w, y, -w, h));

		k_rect.left = *iter;
		k_rect.top = *iterY;
		collision_K();


		if (((k_rect.left >= ((ballX)) - 30) && (k_rect.left <= ((ballX)+20))) && ((k_rect.top >= (ballY)-40) && (k_rect.top <= (ballY)+30))) {
			cout << "k_rect.left=" << k_rect.left << endl;
			cout << "k_rect.ballX=" << ballX << endl;
			cout << "k_rect.top=" << k_rect.top << endl;
			cout << "k_rect.ballY=" << ballY << endl;
			cout << "kill" << endl;//Вызов метода убийства
			ballhp.Damage();
		}
		
		iterY++;
	}
}

void Killer::move_spid(float time, float ballX, float ballY, Ball &ballhp)
{

	auto iterY = spid_Y.begin();

	for (auto iter = spid_X.begin(); iter != spid_X.end(); iter++)
	{
		killer_sprite.setPosition(*iter, *iterY);

		*iter += x * time; // X

		//killer_sprite.setPosition(k_rect.left, k_rect.top);
		//k_rect.left += x * time; // X

		k_currentFrame += 5 * time; // для анимации 
		if (k_currentFrame > 4)  k_currentFrame -= 4;
		if (x < 0) killer_sprite.setTextureRect(IntRect(w * int(k_currentFrame), y, w, h));
		if (x > 0) killer_sprite.setTextureRect(IntRect(w * int(k_currentFrame) + w, y, -w, h));

		k_rect.left = *iter;
		k_rect.top = *iterY;
		collision_K();

		*iter = k_rect.left;
		*iterY = k_rect.top;

		if (((k_rect.left >= ((ballX))-30) && (k_rect.left <= ((ballX)+20))) && ((k_rect.top >= (ballY)-40) && (k_rect.top <= (ballY)+30))) {
			cout << "k_rect.left=" << k_rect.left << endl;
			cout << "k_rect.ballX=" << ballX << endl;
			cout << "k_rect.top=" << k_rect.top << endl;
			cout << "k_rect.ballY=" << ballY << endl;
			cout << "kill" << endl;//Вызов метода убийства
			ballhp.Damage();
		}

		iterY++;
	}
}



void Killer::collision_K()
{
	 
	for (int i = k_rect.top / 32; i < (k_rect.top + 15) / 32; i++)
		for (int j = k_rect.left / 32; j < (k_rect.left + 15) / 32; j++)
		{
			if (TileMap[int(k_rect.top / 32)][int((k_rect.left / 32) + 1)] == '0')
			{
				x *= -1; k_rect.left = k_rect.left - 20;

			}
			else if (TileMap[int(k_rect.top / 32)][int((k_rect.left / 32)-1)] == '0')
			{
				x *= -1; k_rect.left = k_rect.left + 10;
			}

		}
	
}

