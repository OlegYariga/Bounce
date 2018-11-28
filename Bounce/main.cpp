
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
#include <list>


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

		/* //музыка

		sf::Music Main_theme;
		Main_theme.openFromFile("Main_theme.WAV");
		Main_theme.setLoop(true);
		Main_theme.play();*/


		menu_item = startMenu();
		map_level1.loadLevelFromFile(2);

		
		Wasp wasp1("wasp1.png",'A',0,0,35,35);
		Spider spider1("spider1.png", 'T',0,0,44, 44);
		

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



				
				
				wasp1.move_wasp(time);
				window.draw(wasp1.killer_sprite);
				
				spider1.move_wasp(time);
				window.draw(spider1.killer_sprite);

					//wasp1.arr[1]->move_wasp(time);
					//window.draw(wasp1.arr[1]->killer_wasp);
				
				
				

				
				test.drawing_person();
				cam.changeCameraPosition(test.getcoorginateX(), test.getcoorginateY());

				
				test.drawing_person();



				window.draw(b1.sprite);

				window.display();//вывод всех изображений на экран
			}
		}
		if (menu_item == 2) {
			
		}
		if (menu_item == 3) {
			
		}

		//system("pause");
		// в дальнейшем, нужно переместить 
	}
	while (menu_item!=4);
	return 0;
}

