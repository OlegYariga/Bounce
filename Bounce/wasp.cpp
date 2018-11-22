#include "wasp.h"
#include "drawMaps.h"
#include "engine.h"
#include <iostream>
#include <time.h>
#include <Windows.h>
using namespace std;

Wasp::Wasp() {

	Image_wasp.loadFromFile("wasp1.png"); //загружаем файл
	//Image_wasp.createMaskFromColor(Color(0,0,0)) - //маска - убирает цвет из картинки (создает прозрачность)

	killer_wasp.setTexture(Image_wasp);//заряжаем текстуру картинкой

	killer_wasp.setTextureRect(IntRect(0, 0, 35, 35));// нужный прямоугольник с осой
	killer_wasp.setPosition(610, 314);  // где поставили осу на карте  (ОЛЕГ НАРИСУЙ НА КАРТЕ УЛИЙ!!!)

}

void Wasp::show_wasp(float time)
{
	for (int i = 0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			if (TileMap[i][j] == 'A')
			{
				killer_wasp.setTextureRect(IntRect(0, 0, 35, 35));// нужный прямоугольник с осой
				killer_wasp.setPosition(j * 32, i * 32);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один 
				//window.draw(killer_wasp);//рисуем квадратики на экран
				
				x += dx;
				time_game += time;
				cout << "time" << time_game << endl;
				cout << "x" << x << endl;

				if (time_game > 2) { dx *= -1; time_game = 0; }
				killer_wasp.setPosition(x + j * 32, i * 32);
			};
		}	
	
}

void Wasp::move_wasp(float time)
{

	//x +=dx ;
	//time_game += time;
	//cout <<"time"<< time_game<<endl;
	//cout <<"x"<< x << endl;

	//if (time_game > 3) { dx *= -1; time_game = 0; }
	//killer_wasp.setPosition(x + 620, 314);

}









