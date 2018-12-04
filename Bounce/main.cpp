
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


//¬ будущем вынести это из MAIN

#ifdef _DEBUG //здесь определ€ем, какой режим сборки включен (Debug или Release)
#pragma comment(lib, "sfml-audio-d.lib")//определ€ем файл библиотеки с музыкой дл€ линковщика (дл€ Debug)
#else
#pragma comment(lib, "sfml-audio.lib")//определ€ем файл библиотеки с музыкой дл€ линковщика ( дл€ Release)
#endif // 

int menu_item = 0;
int level_number = 2;

Clock clock1;

//using namespace sf;  пространство имен
int main()
{
	sf::Music Main_theme;
	Main_theme.openFromFile("Main_theme.WAV");
	Main_theme.setVolume(50);
	Main_theme.setLoop(true);
	Main_theme.play();

	do { //глвный цикл программы (от вывода меню до завершени€ игры)

	/*ќписание массива, содержащего карту уровн€:
	//
	0 - красные кирпичи (смещение = 96пкс в файле с рисунками)
	' ' - коричневый "фон" (смещение = 0пкс)
	R - резиновые плитки
	A - место по€влени€ осы на карте
	7 - ускорение
	8 - переключение гравитации
	2 - возврат на норм. гравитацию
	^ - шипик
	* - сердце
	B - по€вление шарика
	F - место по€влени€ паука на карте
	*/
		std::list<enemy*> enemys;//для списка с врагами
		std::list<enemy*>::iterator bb;
		
		
		drawMap map_level1; // объ€вление объекта "уровень" отвечающего за начальную загрузку карты
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
		//музыка

		
		window.setView(window.getDefaultView());//устанавливаем стандартное положение экрана
		window.clear();//очищаем экран

		menu_item = startMenu();//выводим меню

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
				if (Keyboard::isKeyPressed(Keyboard::Escape)) {//выход в меню при нажатии клавиши Ecsape
					
					window.setView(window.getDefaultView());
					window.clear();
					window.display();
					break;
				}

				window.setView(cam.ball_camera);//устанавливаем камеру
				window.clear();//очищаем экран


				/////////////////////////////////////////////////////////////////////
				/////////////////////////////////////////////////////////////////////
				/////////////////////////////////////////////////////////////////////
				//методы дл€ прорисовки изображени€ (дл€ объектов какого-либо класса)
				/////////////////////////////////////////////////////////////////////
				/////////////////////////////////////////////////////////////////////

				
				/*ќЋ≈√*/map_level1.drawing_level();// вызываем метод вывода карты на экран (бесконечный цикл прорисовки)
				/* ј“я*/
				/*Clock clock;    //врем€ игры
				
				float time = clock.getElapsedTime().asMicroseconds();
				clock.restart();
				time = time / 800;


				wasp.drawWasp();
				wasp.move_wasp(time, test.getcoorginateX(), test.getcoorginateY(), test);

				spider.drawSpider();
				spider.move_spid(time, test.getcoorginateX(), test.getcoorginateY(), test);
*/
				/*ќЋ≈√*/
				cam.changeCameraPosition(test.getcoorginateX(), test.getcoorginateY());

				
				/*»Ћ№я*/
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
				
				/*-----»Ћ№я----*/
				// ј“я
				for (bb = enemys.begin(); bb != enemys.end(); bb++) {
					(*bb)->drawing();
					FloatRect ff = (*bb)->FL();
					bee::Bullet bullet(ff);
					bullet.drawing();
				}

				/*јЌ“ќЌ*/
				test.drawing_person();

				window.display();//вывод всех изображений на экран
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

