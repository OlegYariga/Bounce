
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "drawMaps.h"
#include "engine.h"
#include "Ball.h"
//В будущем вынести это из MAIN

#ifdef _DEBUG //здесь определяем, какой режим сборки включен (Debug или Release)
#pragma comment(lib, "sfml-audio-d.lib")//определяем файл библиотеки с музыкой для линковщика (для Debug)
#else
#pragma comment(lib, "sfml-audio.lib")//определяем файл библиотеки с музыкой для линковщика ( для Release)
#endif // 




//using namespace sf;
int main()
{
	/*Описание массива, содержащего карту уровня:
	//
	0 - красные кирпичи (смещение = 96пкс в файле с рисунками)
	' ' - коричневый "фон" (смещение = 0пкс)
	R - резиновые плитки
	b - "жуки" - место, которое должен занимать жук (в пределах которого он должен двигаться)
	A - место появления жука на карте
	*/

	drawMap map_level1; // объявление объекта "уровень" отвечающего за начальную загрузку карты
	Ball test;

	/* //музыка

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

		window.clear();//очищаем экран
		
		
		/////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////
		//методы для прорисовки изображения (для объектов какого-либо класса)
		/////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////

		map_level1.drawing_level();// вызываем метод вывода карты на экран (бесконечный цикл прорисовки)
		



		window.draw(test.sprite);

		if (Keyboard::isKeyPressed(Keyboard::Right))
			test.KeyRight();
		
		if (Keyboard::isKeyPressed(Keyboard::Left))
			test.KeyLeft();





		window.display();//вывод всех изображений на экран
	}



	system("pause");
	// в дальнейшем, нужно переместить 
	return 0;
}