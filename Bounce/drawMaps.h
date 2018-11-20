#pragma once
#include "engine.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
//#include <fstream>

using namespace sf;




class drawMap {
public:
	
		Image image1;
		Texture map;//текстура карты
		Sprite s_map;//создаём спрайт для карты
		
		
		drawMap();
		~drawMap();
		void drawing_level();

};