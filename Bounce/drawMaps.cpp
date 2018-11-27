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
			if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 32, 32)); //если встретили символ пробел, то рисуем 1й квадратик
			if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 32, 32));//если встретили символ s, то рисуем 2й квадратик
			if (TileMap[i][j] == '0') s_map.setTextureRect(IntRect(96, 0, 32, 32));//если встретили символ 0, то рисуем 3й квадратик
			if (TileMap[i][j] == 'F') s_map.setTextureRect(IntRect(96, 0, 32, 32));//если встретили символ 0, то рисуем 3й квадратик
			if (TileMap[i][j] == '+')  s_map.setTextureRect(IntRect(128, 0, 32, 32));//если встретили символ s, то рисуем 4й квадратик
			if (TileMap[i][j] == '-') s_map.setTextureRect(IntRect(160, 0, 32, 32));//если встретили символ 0, то рисуем 5й квадратик
			if (TileMap[i][j] == 'R') s_map.setTextureRect(IntRect(192, 0, 32, 32));//если встретили символ 0, то рисуем 5й квадратик

			if (TileMap[i][j] == 'b') s_map.setTextureRect(IntRect(64, 0, 32, 32));//!!!ЗАМЕНИТЬ НА ПОЛЕ ДЛЯ ЖУКА
			if (TileMap[i][j] == 'A') s_map.setTextureRect(IntRect(64, 0, 32, 32));//!!!ЗАМЕНИТЬ НА ПОЛЕ ДЛЯ ЖУКА
			s_map.setPosition(j * 32, i * 32);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один 
			
			window.draw(s_map);//рисуем квадратики на экран
		}
}

void drawMap::loadLevelFromFile(int num_level) {
	string line;
	ifstream myfile("level"+ to_string(num_level)+".level");
	//ifstream myfile("level1.level");
	int i = 0;
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			getline(myfile, line);
			TileMap[i] = line;
			//cout << TileMap[i] << endl;
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