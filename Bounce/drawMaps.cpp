#include "engine.h"
#include "drawMaps.h"

RenderWindow window(sf::VideoMode(1200, 600), "Bounce");//инициализируется объект окна игры


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
			if (TileMap[i][j] == '+')  s_map.setTextureRect(IntRect(128, 0, 32, 32));//если встретили символ s, то рисуем 4й квадратик
			if (TileMap[i][j] == '-') s_map.setTextureRect(IntRect(160, 0, 32, 32));//если встретили символ 0, то рисуем 5й квадратик
			if (TileMap[i][j] == 'R') s_map.setTextureRect(IntRect(192, 0, 32, 32));//если встретили символ 0, то рисуем 5й квадратик

			if (TileMap[i][j] == 'b') s_map.setTextureRect(IntRect(64, 0, 32, 32));//!!!ЗАМЕНИТЬ НА ПОЛЕ ДЛЯ ЖУКА
			if (TileMap[i][j] == 'A') s_map.setTextureRect(IntRect(64, 0, 32, 32));//!!!ЗАМЕНИТЬ НА ПОЛЕ ДЛЯ ЖУКА
			s_map.setPosition(j * 32, i * 32);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один 
			
			window.draw(s_map);//рисуем квадратики на экран
		}
}

String TileMap[HEIGHT_MAP] = {// определение карты (В БУДУЩЕМ СДЕЛАТЬ ЗАГРУЗКУ ИЗ ФАЙЛА)
	"0000000000000000000000000000000000000000",
	"0000000000000000000++++++++            0",
	"0      000000000000                    0",
	"0      000000000000                    0",
	"0      000000000000                    0",
	"0                                      0",
	"0                                      0",
	"0                 0  bb                0",
	"0                 0                    0",
	"0               000                    0",
	"0                 0Abbbbbbb  0         0",
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