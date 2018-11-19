#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "drawMaps.h"
#include "engine.h"
#include "Ball.h"
#include "Boost.h"
#include "wasp.h"


//� ������� ������� ��� �� MAIN

#ifdef _DEBUG //����� ����������, ����� ����� ������ ������� (Debug ��� Release)
#pragma comment(lib, "sfml-audio-d.lib")//���������� ���� ���������� � ������� ��� ���������� (��� Debug)
#else
#pragma comment(lib, "sfml-audio.lib")//���������� ���� ���������� � ������� ��� ���������� ( ��� Release)
#endif // 

int startMenu();

Clock clock1;

//using namespace sf;  ������������ ����
int main()
{


	/*�������� �������, ����������� ����� ������:
	//
	0 - ������� ������� (�������� = 96��� � ����� � ���������)
	' ' - ���������� "���" (�������� = 0���)
	R - ��������� ������
	b - "����" - �����, ������� ������ �������� ��� (� �������� �������� �� ������ ���������)
	A - ����� ��������� ���� �� �����
	*/

	
	// Clock clock1;    //����� ����
	// int time,time_game;
	// time= clock1.getElapsedTime().asMicroseconds();
	// time = time / 800;
	// time_game += time;



	drawMap map_level1; // ���������� ������� "�������" ����������� �� ��������� �������� �����
	Ball test;
	Wasp wasp1;
	Boost b1;

	/* //������

	sf::Music Main_theme;
	Main_theme.openFromFile("Main_theme.WAV");
	Main_theme.setLoop(true);
	Main_theme.play();*/
	

	startMenu();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();//������� �����
		
		
		/////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////
		//������ ��� ���������� ����������� (��� �������� ������-���� ������)
		/////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////

		map_level1.drawing_level();// �������� ����� ������ ����� �� ����� (����������� ���� ����������)
		



		window.draw(test.sprite);
		window.draw(wasp1.killer_wasp);

		 
		wasp1.move_wasp();
		
		if (Keyboard::isKeyPressed(Keyboard::Right))
			test.KeyRight();
		   
		
		if (Keyboard::isKeyPressed(Keyboard::Left))
			test.KeyLeft();



		window.draw(b1.sprite);

		window.display();//����� ���� ����������� �� �����
	}



	//system("pause");
	// � ����������, ����� ����������� 
	return 0;
}

int startMenu() {
	Texture start_text;
	Sprite start_sprite;

	start_text.loadFromFile("screensaver.jpg");
	start_sprite.setTexture(start_text);
	//start_sprite.scale(1.0f, 1.0f);
	start_sprite.setPosition(0, 0);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Right)
			{
				break;
			}
		}

		window.clear();//������� �����

		window.draw(start_sprite);

		window.display();//����� ���� ����������� �� �����
	}





	return 0;
}