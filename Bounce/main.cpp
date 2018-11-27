
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

Clock clock1;

//using namespace sf;  пространство имен
int main()
{
	sf::Music Main_theme;
	Main_theme.openFromFile("Main_theme.WAV");
	Main_theme.setLoop(true);
	Main_theme.play();

	do { //глвный цикл программы (от вывода меню до завершения игры)

	/*Описание массива, содержащего карту уровня:
	//
	0 - красные кирпичи (смещение = 96пкс в файле с рисунками)
	' ' - коричневый "фон" (смещение = 0пкс)
	R - резиновые плитки
	b - "жуки" - место, которое должен занимать жук (в пределах которого он должен двигаться)
	A - место появления жука на карте
	*/


	// Clock clock1;    //время игры
	// int time,time_game;
	// time= clock1.getElapsedTime().asMicroseconds();
	// time = time / 800;
	// time_game += time;



		drawMap map_level1; // объявление объекта "уровень" отвечающего за начальную загрузку карты
		Ball test;
		Boost b1;
		Camera cam;
		Spike spike_test;
		Door door_test;

		//музыка

		

		menu_item = startMenu();
		map_level1.loadLevelFromFile(2);

		/*Wasp* arr_wasp[2];
		for (int i = 1; i < 3; i++) {
			arr_wasp[i] = new Wasp;
		}*/

		Wasp wasp1;


		//wasp1.show_wasp();//выводим осу в начальное положение

		if (menu_item == 1) {
			spike_test.find_spike();
			b1.findBoost();
			door_test.findDoor();
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
				//методы для прорисовки изображения (для объектов какого-либо класса)
				/////////////////////////////////////////////////////////////////////
				/////////////////////////////////////////////////////////////////////

				
				map_level1.drawing_level();// вызываем метод вывода карты на экран (бесконечный цикл прорисовки)




				//window.draw(wasp1.killer_wasp);
				
				Clock clock;    //время игры
				
				float time = clock.getElapsedTime().asMicroseconds();
				clock.restart();
				time = time / 800;




				
				/*arr_wasp[1]->move_wasp(time);
				window.draw(arr_wasp[1]->killer_wasp);*/

				wasp1.move_wasp(time);
				window.draw(wasp1.killer_wasp);

				
				cam.changeCameraPosition(test.getcoorginateX(), test.getcoorginateY());

				
				test.drawing_person();

				spike_test.draw_spike();
				spike_test.interact(test.getcoorginateX(), test.getcoorginateY());

				door_test.drawDoor();
				door_test.interactDoor(test.getcoorginateX(), test.getcoorginateY());

				
				b1.drawBoost();
				b1.interact_boost(test.getcoorginateX(), test.getcoorginateY());

				test.drawing_person();


				window.display();//вывод всех изображений на экран
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
			//showInfo();
		}

		//system("pause");
		// в дальнейшем, нужно переместить 
	}
	while (menu_item!=4);
	return 0;
}

