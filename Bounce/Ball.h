#pragma once
#include "engine.h" // ������ �� ��������
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball {
public:
	Sprite sprite;
	Ball();
	void drawing_person();
	void KeyRight();
	void KeyLeft();
private:
	Texture person;
	//Sprite sprite; �� �� ���������� engine.h
};
