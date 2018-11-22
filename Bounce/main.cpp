
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "drawMaps.h"
#include "engine.h"
#include "Ball.h"
#include "Boost.h"
#include "wasp.h"


//В будущем вынести это из MAIN

#ifdef _DEBUG //здесь определяем, какой режим сборки включен (Debug или Release)
#pragma comment(lib, "sfml-audio-d.lib")//определяем файл библиотеки с музыкой для линковщика (для Debug)
#else
#pragma comment(lib, "sfml-audio.lib")//определяем файл библиотеки с музыкой для линковщика ( для Release)
#endif // 

int menu_item = 0;

int startMenu();//прототип функции меню
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
		Wasp wasp1;
		Boost b1;

		/* //музыка

		sf::Music Main_theme;
		Main_theme.openFromFile("Main_theme.WAV");
		Main_theme.setLoop(true);
		Main_theme.play();*/


		startMenu();

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

				window.clear();//очищаем экран


				/////////////////////////////////////////////////////////////////////
				/////////////////////////////////////////////////////////////////////
				/////////////////////////////////////////////////////////////////////
				//методы для прорисовки изображения (для объектов какого-либо класса)
				/////////////////////////////////////////////////////////////////////
				/////////////////////////////////////////////////////////////////////

				map_level1.drawing_level();// вызываем метод вывода карты на экран (бесконечный цикл прорисовки)




				window.draw(wasp1.killer_wasp);
				
				Clock clock;    //время игры
				
				float time = clock.getElapsedTime().asMicroseconds();
				clock.restart();
				time = time / 800;

				window.draw(wasp1.killer_wasp);
				window.draw(test.sprite);
				//wasp1.move_wasp(time);
				wasp1.show_wasp(time);
				
				
				
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

//функция вывода главного меню. 
//переменная menu_item - хранит выбранный параметр меню
int startMenu() {
	Image im_start, im_exit, im_option, im_info;
	Texture start_text,tx_start,tx_exit,tx_option,tx_info;
	Sprite start_sprite, sp_start, sp_exit, sp_option, sp_info;

	start_text.loadFromFile("screensaver.jpg");
	start_sprite.setTexture(start_text);
	start_sprite.setPosition(0, 0);

	//вывод пунктов меню

	im_start.loadFromFile("menu_start.png");
	im_start.createMaskFromColor(im_start.getPixel(0, 0));
	tx_start.loadFromImage(im_start);
	sp_start.setTexture(tx_start);
	sp_start.setPosition(100,50);



	im_option.loadFromFile("menu_options.png");
	im_option.createMaskFromColor(im_option.getPixel(0, 0));
	tx_option.loadFromImage(im_option);
	sp_option.setTexture(tx_option);
	sp_option.setPosition(100, 150);


	im_info.loadFromFile("menu_info.png");
	im_info.createMaskFromColor(im_info.getPixel(0, 0));
	tx_info.loadFromImage(im_info);
	sp_info.setTexture(tx_info);
	sp_info.setPosition(100, 250);

	im_exit.loadFromFile("menu_exit.png");
	im_exit.createMaskFromColor(im_exit.getPixel(0, 0));
	tx_exit.loadFromImage(im_exit);
	sp_exit.setTexture(tx_exit);
	sp_exit.setPosition(100, 350);


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
		//подкрашиваем пункты меню при наведении
		{
			if (IntRect(100, 50, 223, 50).contains(Mouse::getPosition(window)))
			{
				sp_start.setColor(Color::Blue);
			}
			else {
				sp_start.setColor(Color::White);
			}
			
			if (IntRect(100, 150, 266, 50).contains(Mouse::getPosition(window)))
			{
				sp_option.setColor(Color::Blue);
			}
			else {
				sp_option.setColor(Color::White);
			}

			if (IntRect(100, 250, 147, 50).contains(Mouse::getPosition(window)))
			{
				sp_info.setColor(Color::Blue);
			}
			else {
				sp_info.setColor(Color::White);
			}

			if (IntRect(100, 350, 163, 50).contains(Mouse::getPosition(window)))
			{
				sp_exit.setColor(Color::Blue);
			}
			else {
				sp_exit.setColor(Color::White);
			}

		}

		if (event.type == sf::Event::MouseButtonPressed)
		{

			if (IntRect(100, 50, 223, 50).contains(Mouse::getPosition(window))) 
			{ 
				//выходим в функцию main, чтобы запустить игру::
				menu_item = 1;
				break;
			}

			if (IntRect(100, 150, 266, 50).contains(Mouse::getPosition(window)))
			{
				//будем выполнять какую-то другую функцию. Пока просто подкрасим в красный цвет пункт
				sp_option.setColor(Color::Red);
				menu_item = 2;
				break;
			}

			if (IntRect(100, 250, 147, 50).contains(Mouse::getPosition(window)))
			{
				//будем выполнять какую-то другую функцию. Пока просто подкрасим в красный цвет пункт
				sp_info.setColor(Color::Yellow);
				menu_item = 3;
				break;
			}

			if (IntRect(100, 350, 163, 50).contains(Mouse::getPosition(window)))
			{
				//будем выполнять какую-то другую функцию. Пока просто подкрасим в красный цвет пункт
				sp_exit.setColor(Color::Green);
				menu_item = 4;
				break;
				//
				//
			}


			/*if (event.mouseButton.button == sf::Mouse::Right)
			{
				break;
			}*/
		}

		window.clear();//очищаем экран

		window.draw(start_sprite);

		window.draw(sp_start);
		window.draw(sp_option);
		window.draw(sp_info);
		window.draw(sp_exit);

		window.display();//вывод всех изображений на экран
	}




//выход из функции
	return 0;
}