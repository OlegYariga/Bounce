
#include "wasp.h"
#include "drawMaps.h"
#include "engine.h"



Wasp::Wasp(){ 

	Image_wasp.loadFromFile("wasp1.png"); //загружаем файл
    //Image_wasp.createMaskFromColor(Color(0,0,0)) - //маска - убирает цвет из картинки (создает прозрачность)
   
	killer_wasp.setTexture(Image_wasp);//заряжаем текстуру картинкой

	killer_wasp.setTextureRect(IntRect(0, 0, 35, 35));// нужный прямоугольник с осой
	killer_wasp.setPosition(610, 314);  // где поставили осу на карте  (ОЛЕГ НАРИСУЙ НА КАРТЕ УЛИЙ!!!)
	
}

void Wasp::show_wasp()
{
	
	 
	for (int i = 0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			if (TileMap[i][j] == 'A')
			{
				killer_wasp.setTextureRect(IntRect(0, 0, 35, 35));// нужный прямоугольник с осой
				killer_wasp.setPosition(j * 32, i * 32); ;//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один 
				window.draw(killer_wasp);//рисуем квадратики на экран
				
				 
			}; 
			while (TileMap[i][j+1] != '0') killer_wasp.move(0.1, 0);
		} 
	
	
}

void Wasp::move_wasp() {

	for (int i = 0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++) {
			while (TileMap[i][j] == 'A') killer_wasp.move(0.1, 0);
		}

}


	




