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
		Texture map;//�������� �����
		Sprite s_map;//������ ������ ��� �����
		
		
		drawMap();
		~drawMap();
		void drawing_level();

};