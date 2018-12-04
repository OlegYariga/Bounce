
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "drawMaps.h"
#include "engine.h"
#include "Ball.h"
#include "Boost.h"
#include "Camera.h"
#include "Menu.h"

#include "enemy.h"


//� ������� ������� ��� �� MAIN

#ifdef _DEBUG //����� ����������, ����� ����� ������ ������� (Debug ��� Release)
#pragma comment(lib, "sfml-audio-d.lib")//���������� ���� ���������� � ������� ��� ���������� (��� Debug)
#else
#pragma comment(lib, "sfml-audio.lib")//���������� ���� ���������� � ������� ��� ���������� ( ��� Release)
#endif // 

int menu_item = 0;
int level_number = 2;

Clock clock1;

//using namespace sf;  ������������ ����
int main()
{
	sf::Music Main_theme;
	Main_theme.openFromFile("Main_theme.WAV");
	Main_theme.setVolume(50);
	Main_theme.setLoop(true);
	Main_theme.play();

	do { //������ ���� ��������� (�� ������ ���� �� ���������� ����)

	/*�������� �������, ����������� ����� ������:
	//
	0 - ������� ������� (�������� = 96��� � ����� � ���������)
	' ' - ���������� "���" (�������� = 0���)
	R - ��������� ������
	A - ����� ��������� ��� �� �����
	7 - ���������
	8 - ������������ ����������
	2 - ������� �� ����. ����������
	^ - �����
	* - ������
	B - ��������� ������
	F - ����� ��������� ����� �� �����
	*/
		std::list<enemy*> enemys;//��� ������ � �������
		std::list<enemy*>::iterator bb;
		
		
		drawMap map_level1; // ���������� ������� "�������" ����������� �� ��������� �������� �����
		map_level1.loadLevelFromFile(level_number);
		
		
		Ball test;
		
		for (int i = 0; i < HEIGHT_MAP; i++) {
			for (int j = 0; j < WIDTH_MAP; j++) {

				if (TileMap[i][j] == 'A') {

					enemys.push_back(new bee(j, i));
					cout << i << "   " << j << endl;

				}
			}
		}
		
		
		Boost b1;
		Camera cam;
		Spike spike_test;
		Door door_test;
		HealthBar hpbar_test;
		Key key;
		GravityDown GD;
		GravityUp GU;
		SpeedUp SU;
		Spring spring;
		//������

		
		window.setView(window.getDefaultView());//������������� ����������� ��������� ������
		window.clear();//������� �����

		menu_item = startMenu();//������� ����

		//Spider spider("spider1.png", 'S', 0, 0, 43, 48);
		//Wasp wasp("wasp1.png", 'A', 0, 0, 35, 35);

		if (menu_item == 1) {
			spike_test.find_spike();
			b1.findBoost();
			door_test.findDoor();
			key.findKey();
			GD.findGD();
			GU.findGU();
			SU.findSU();
			spring.findSpring();
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
				if (Keyboard::isKeyPressed(Keyboard::Escape)) {//����� � ���� ��� ������� ������� Ecsape
					
					window.setView(window.getDefaultView());
					window.clear();
					window.display();
					break;
				}

				window.setView(cam.ball_camera);//������������� ������
				window.clear();//������� �����


				/////////////////////////////////////////////////////////////////////
				/////////////////////////////////////////////////////////////////////
				/////////////////////////////////////////////////////////////////////
				//������ ��� ���������� ����������� (��� �������� ������-���� ������)
				/////////////////////////////////////////////////////////////////////
				/////////////////////////////////////////////////////////////////////

				
				/*����*/map_level1.drawing_level();// �������� ����� ������ ����� �� ����� (����������� ���� ����������)
				/*����*/
				/*Clock clock;    //����� ����
				
				float time = clock.getElapsedTime().asMicroseconds();
				clock.restart();
				time = time / 800;


				wasp.drawWasp();
				wasp.move_wasp(time, test.getcoorginateX(), test.getcoorginateY(), test);

				spider.drawSpider();
				spider.move_spid(time, test.getcoorginateX(), test.getcoorginateY(), test);
*/
				/*����*/
				cam.changeCameraPosition(test.getcoorginateX(), test.getcoorginateY());

				
				/*����*/
				spike_test.draw_spike();
				
				door_test.drawDoor();
				bool doorIsOpen = door_test.interactDoor(test.getcoorginateX(), test.getcoorginateY());

				
				b1.drawBoost();
				b1.interact_boost(test.getcoorginateX(), test.getcoorginateY(), test);
				
				key.drawKey();
				key.interactKey(test.getcoorginateX(), test.getcoorginateY(), door_test);
				
				hpbar_test.update_hpbar(spike_test.interact(test.getcoorginateX(),test.getcoorginateY(),test));
				hpbar_test.update_hpbar(b1.interact_boost(test.getcoorginateX(), test.getcoorginateY(),test));
				hpbar_test.draw_hpbar(window);

				GD.drawGD();
				GD.interactGD(test.getcoorginateX(), test.getcoorginateY(), test);
				GU.drawGU();
				GU.interactGU(test.getcoorginateX(), test.getcoorginateY(), test);
				SU.drawSU();
				SU.interactSU(test.getcoorginateX(), test.getcoorginateY(), test);
				spring.drawSpring();
				spring.interactSpring(test.getcoorginateX(), test.getcoorginateY(), test);
				
				/*-----����----*/
				//����
				for (bb = enemys.begin(); bb != enemys.end(); bb++) {
					(*bb)->drawing();
					FloatRect ff = (*bb)->FL();
					bee::Bullet bullet(ff);
					bullet.drawing();
				}

				/*�����*/
				test.drawing_person();

				window.display();//����� ���� ����������� �� �����
				if (test.getLife() <= 0) {
					
					level_number = 2;
					break;
				}
				
				if (doorIsOpen) {
					level_number++;
					break;
				}
			}
		}
		if (menu_item == 2) {
			if (showOptions(Main_theme.getStatus())) {
				Main_theme.play();
			}
			else {
				Main_theme.stop();
			}

		}
		if (menu_item == 3) {
		}

		
	}
	while (menu_item!=4);
	return 0;
}

