#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "engine.h"
#include "Menu.h"
#include <iostream>
using namespace sf;
//функция вывода главного меню. 
//переменная menu_item - хранит выбранный параметр меню
int startMenu() {
	Image im_start, im_exit, im_option, im_info;
	Texture start_text, tx_start, tx_exit, tx_option, tx_info;
	Sprite start_sprite, sp_start, sp_exit, sp_option, sp_info;

	start_text.loadFromFile("screensaver.jpg");
	start_sprite.setTexture(start_text);
	start_sprite.setPosition(0, 0);

	//вывод пунктов меню

	im_start.loadFromFile("menu_start.png");
	im_start.createMaskFromColor(im_start.getPixel(0, 0));
	tx_start.loadFromImage(im_start);
	sp_start.setTexture(tx_start);
	sp_start.setPosition(100, 50);


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
				return 4;
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
				//std::cout << "CHF<JNFHJ";
				//выходим в функцию main, чтобы запустить игру::
				return 1;
				break;
			}

			if (IntRect(100, 150, 266, 50).contains(Mouse::getPosition(window)))
			{
				//будем выполнять какую-то другую функцию. Пока просто подкрасим в красный цвет пункт
				sp_option.setColor(Color::Red);
				return 2;
				break;
			}

			if (IntRect(100, 250, 147, 50).contains(Mouse::getPosition(window)))
			{
				//будем выполнять какую-то другую функцию. Пока просто подкрасим в красный цвет пункт
				sp_info.setColor(Color::Yellow);
				showInfo();
				return 3;
				break;
			}

			if (IntRect(100, 350, 163, 50).contains(Mouse::getPosition(window)))
			{
				//будем выполнять какую-то другую функцию. Пока просто подкрасим в красный цвет пункт
				sp_exit.setColor(Color::Green);
				return 4;
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

int showInfo() {
	Image im_start;
	Texture start_text;
	Sprite start_sprite;

	start_text.loadFromFile("Info.jpg");
	start_sprite.setTexture(start_text);
	start_sprite.setPosition(0, 0);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
				return 4;
			}
		}
		//подкрашиваем пункты меню при наведении
		
		if (event.type == sf::Event::MouseButtonPressed)
		{
			return 0;
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			return 0;
		}

			/*if (event.mouseButton.button == sf::Mouse::Right)
			{
			break;
			}*/
		

		window.clear();//очищаем экран

		window.draw(start_sprite);


		window.display();//вывод всех изображений на экран
	}
	return 0;
}

bool showOptions(bool playing) {

	Image im_start, im_check_on, im_check_off;
	Texture start_text, tx_check_on, tx_check_off;
	Sprite start_sprite, sp_check_on, sp_check_off;

	start_text.loadFromFile("check.jpg");
	start_sprite.setTexture(start_text);
	start_sprite.setPosition(0, 0);

	im_check_on.loadFromFile("check_on.png");
	//im_check_on.createMaskFromColor(Color::White);
	tx_check_on.loadFromImage(im_check_on);
	sp_check_on.setTexture(tx_check_on);
	sp_check_on.setPosition(580, 187);
	
	im_check_off.loadFromFile("check_off.png");
	//im_check_off.createMaskFromColor(Color::White);
	tx_check_off.loadFromImage(im_check_off);
	sp_check_off.setTexture(tx_check_off);
	sp_check_off.setPosition(580, 187);


	bool check_stats=playing;

	while (window.isOpen())
	{
		window.clear();//очищаем экран

		window.draw(start_sprite);
		if (check_stats) {
			window.draw(sp_check_on);
		}
		else {
			window.draw(sp_check_off);
		}
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
				return false;
			}
		}
		//подкрашиваем пункты меню при наведении

		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (IntRect(580, 187, 50, 50).contains(Mouse::getPosition(window)))
			{
				if (check_stats) {
					check_stats = false;
				}
				else {
					check_stats = true;
				}
				//window.draw(sp_check_on);
				//check_stats = true;

			}
			window.display();
			
			return check_stats;

		}
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			return check_stats;
		}
		/*if (event.mouseButton.button == sf::Mouse::Right)
		{
		break;
		}*/
		
		window.display();
		//вывод всех изображений на экран
	}
	return 0;
}

