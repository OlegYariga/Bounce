#pragma once
#include "engine.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

using namespace sf;

class drawMap {
public:
		drawMap();
		~drawMap();
		void drawing_level();//отрисовка уровня
		void loadLevelFromFile(int num_level);//загрузка уровня из файла

private:
		Image image1;
		Texture map;//текстура карты
		Sprite s_map;//создаём спрайт для карты

};