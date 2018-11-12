#pragma once
#include "engine.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
//#include <fstream>

using namespace sf;

class drawMap {
public:
		//static const int HEIGHT_MAP = 25;//размер карты высота
		//static const int WIDTH_MAP = 40;//размер карты ширина 
		Image image1;
		Texture map;//текстура карты
		Sprite s_map;//создаём спрайт для карты
		//String TileMap[]; //!!!!!!!!описание массива строк для хранения карты нужно перенести сюда
		
		


		drawMap() {//конструктор класса
			
			image1.loadFromFile("map1.jpeg");// загружаем картинку из файла

			map.loadFromImage(image1);//заряжаем текстуру картинкой

			s_map.setTexture(map);//заливаем текстуру спрайтом
			
			
		}
		~drawMap() {//деструктор 
		}

		void drawing_level() {// функция отрисовки уровня

			//RenderWindow window(sf::VideoMode(1200, 600), "Bounce");
			

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

};