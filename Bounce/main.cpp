
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "drawMaps.h"
#include "engine.h"
#include "Ball.h"
#include "Boost.h"
#include "wasp.h"
#include "Camera.h"
#include "Menu.h"


//� ������� ������� ��� �� MAIN

#ifdef _DEBUG //����� ����������, ����� ����� ������ ������� (Debug ��� Release)
#pragma comment(lib, "sfml-audio-d.lib")//���������� ���� ���������� � ������� ��� ���������� (��� Debug)
#else
#pragma comment(lib, "sfml-audio.lib")//���������� ���� ���������� � ������� ��� ���������� ( ��� Release)
#endif // 

int menu_item = 0;

Clock clock1;

//using namespace sf;  ������������ ����
int main()
{
	
	do { //������ ���� ��������� (�� ������ ���� �� ���������� ����)

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
		Boost b1;
		Camera cam;

		/* //������

		sf::Music Main_theme;
		Main_theme.openFromFile("Main_theme.WAV");
		Main_theme.setLoop(true);
		Main_theme.play();*/


		menu_item = startMenu();
		map_level1.loadLevelFromFile(2);

		/*Wasp* arr_wasp[2];
		for (int i = 1; i < 3; i++) {
			arr_wasp[i] = new Wasp;
		}*/

		Wasp wasp1;


		//wasp1.show_wasp();//������� ��� � ��������� ���������

		if (menu_item == 1) {

			while (window.isOpen())
			{
				sf::Event event;
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed) {
						window.close();
						menu_item = 4;
					}
				}
				window.setView(cam.ball_camera);//������������� ������
				window.clear();//������� �����


				/////////////////////////////////////////////////////////////////////
				/////////////////////////////////////////////////////////////////////
				/////////////////////////////////////////////////////////////////////
				//������ ��� ���������� ����������� (��� �������� ������-���� ������)
				/////////////////////////////////////////////////////////////////////
				/////////////////////////////////////////////////////////////////////

				
				map_level1.drawing_level();// �������� ����� ������ ����� �� ����� (����������� ���� ����������)




				//window.draw(wasp1.killer_wasp);
				
				Clock clock;    //����� ����
				
				float time = clock.getElapsedTime().asMicroseconds();
				clock.restart();
				time = time / 800;




				
				/*arr_wasp[1]->move_wasp(time);
				window.draw(arr_wasp[1]->killer_wasp);*/

				wasp1.move_wasp(time);
				window.draw(wasp1.killer_wasp);

				test.drawing_person();
				cam.changeCameraPosition(test.getcoorginateX(), test.getcoorginateY());

				
				test.drawing_person();



				window.draw(b1.sprite);

				window.display();//����� ���� ����������� �� �����
			}
		}
		if (menu_item == 2) {
			
		}
		if (menu_item == 3) {
			showInfo();
		}

		//system("pause");
		// � ����������, ����� ����������� 
	}
	while (menu_item!=4);
	return 0;
}

