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
		void drawing_level();//��������� ������
		void loadLevelFromFile(int num_level);//�������� ������ �� �����

private:
		Image image1;
		Texture map;//�������� �����
		Sprite s_map;//������ ������ ��� �����

};