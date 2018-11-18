#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "drawMaps.h"
#include "engine.h"
#include "Ball.h"
#include "wasp.h"
//� ������� ������� ��� �� MAIN

#ifdef _DEBUG //����� ����������, ����� ����� ������ ������� (Debug ��� Release)
#pragma comment(lib, "sfml-audio-d.lib")//���������� ���� ���������� � ������� ��� ���������� (��� Debug)
#else
#pragma comment(lib, "sfml-audio.lib")//���������� ���� ���������� � ������� ��� ���������� ( ��� Release)
#endif // 


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

	/* //������

	sf::Music Main_theme;
	Main_theme.openFromFile("Main_theme.WAV");
	Main_theme.setLoop(true);
	Main_theme.play();*/
	
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





		window.display();//����� ���� ����������� �� �����
	}



	//system("pause");
	// � ����������, ����� ����������� 
	return 0;
}