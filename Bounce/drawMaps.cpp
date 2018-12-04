#include "engine.h"
#include "drawMaps.h"
#include <fstream>
#include <string>

using namespace std;
//int num_level = 1;


RenderWindow window(sf::VideoMode(1200, 600), "Bounce", sf::Style::None);//инициализируется объект окна игры


drawMap::drawMap() {//конструктор класса

	image1.loadFromFile("map1.jpeg");// загружаем картинку из файла

	map.loadFromImage(image1);//заряжаем текстуру картинкой

	s_map.setTexture(map);//заливаем текстуру спрайтом

}
drawMap::~drawMap() {

}

void drawMap::drawing_level() {// функция отрисовки уровня

	for (int i = 0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			switch (TileMap[i][j])
			{
			case ' ': {
				s_map.setTextureRect(IntRect(0, 0, 32, 32));
				break;
			}
			case '0': {
				s_map.setTextureRect(IntRect(96, 0, 32, 32));
				break;
			}
			case 'F': {
				s_map.setTextureRect(IntRect(96, 0, 32, 32));
				break;
			}
			default:
				s_map.setTextureRect(IntRect(0, 0, 32, 32));
				break;
			}

			s_map.setPosition(j * 32, i * 32);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один 
			
			window.draw(s_map);//рисуем квадратики на экран
		}
}

void drawMap::loadLevelFromFile(int num_level) {
	string line;
	ifstream myfile("level"+ to_string(num_level)+".level");
	int i = 0;
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			getline(myfile, line);
			TileMap[i] = line;
			i++;
		}
		myfile.close();
	}
}


String TileMap[HEIGHT_MAP] = {// определение карты (В БУДУЩЕМ СДЕЛАТЬ ЗАГРУЗКУ ИЗ ФАЙЛА)
	"bbbbbbbbbbbbbbbbbbb0bbbbbbbbbbbbbbbbbbb0",
	"0000000000000000000++++++++            0",
	"0      000000000000                    0",
	"0      000000000000                    0",
	"0      000000000000                    0",
	"0                                      0",
	"0                                      0",
	"0                 0                    0",
	"0                 0                    0",
	"0               000          0         0",
	"0                 0 A        0         0",
	"0             00000----------0         0",
	"0000000RRRRR0000000000000000000000000000",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0000000000000000000000000000000000000000",
};