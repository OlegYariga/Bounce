
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
 



//В будущем вынести это из MAIN

#ifdef _DEBUG //здесь определяем, какой режим сборки включен (Debug или Release)
#pragma comment(lib, "sfml-audio-d.lib")//определяем файл библиотеки с музыкой для линковщика (для Debug)
#else
#pragma comment(lib, "sfml-audio.lib")//определяем файл библиотеки с музыкой для линковщика ( для Release)
#endif // 

int menu_item = 0;
int level_number = 2;

Clock clock1;
 
//using namespace sf;  пространство имен
int main()
{
	sf::Music Main_theme;
	Main_theme.openFromFile("Main_theme.WAV");
	Main_theme.setLoop(true);
	Main_theme.play();

	do {

		drawMap map_level1; // объявление объекта "уровень" отвечающего за начальную загрузку карты
		Ball test;
		Boost b1;
	
		Camera cam;
		Spike spike_test;
		Door door_test;
		HealthBar hpbar_test;
		Key key;
		

		window.setView(window.getDefaultView());//устанавливаем стандартное положение экрана
		window.clear();//очищаем экран

		menu_item = startMenu();//выводим меню
		map_level1.loadLevelFromFile(level_number);

	
	Spider spider("spider1.png", 'S', 0, 0, 45, 35);
    Wasp wasp("wasp1.png", 'A', 0, 0, 35, 35);

		if (menu_item == 1) {

			 
		  
			spike_test.find_spike();
			b1.findBoost();
			door_test.findDoor();
			key.findKey();
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

				
				map_level1.drawing_level();// вызываем метод вывода карты на экран (бесконечный цикл прорисовки)



				Clock clock;    //время игры
				
				float time = clock.getElapsedTime().asMicroseconds();
				clock.restart();
				time = time / 800;

				wasp.drawWasp();
				wasp.move_wasp(time,test.getcoorginateX(), test.getcoorginateY(), test);
				
				spider.drawSpider();
				spider.move_spid(time, test.getcoorginateX(), test.getcoorginateY(), test);
				

				cam.changeCameraPosition(test.getcoorginateX(), test.getcoorginateY());

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

