#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "drawMaps.h"
#include "engine.h"
#include "Ball.h"
#include "Boost.h"
//¬ будущем вынести это из MAIN

#ifdef _DEBUG //здесь определ€ем, какой режим сборки включен (Debug или Release)
#pragma comment(lib, "sfml-audio-d.lib")//определ€ем файл библиотеки с музыкой дл€ линковщика (дл€ Debug)
#else
#pragma comment(lib, "sfml-audio.lib")//определ€ем файл библиотеки с музыкой дл€ линковщика ( дл€ Release)
#endif // 




//using namespace sf;
int main()
{
	/*ќписание массива, содержащего карту уровн€:
	//
	0 - красные кирпичи (смещение = 96пкс в файле с рисунками)
	' ' - коричневый "фон" (смещение = 0пкс)
	R - резиновые плитки
	b - "жуки" - место, которое должен занимать жук (в пределах которого он должен двигатьс€)
	A - место по€влени€ жука на карте
	*/

	drawMap map_level1; // объ€вление объекта "уровень" отвечающего за начальную загрузку карты
	Ball test;
	Boost b1;
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
		//методы дл€ прорисовки изображени€ (дл€ объектов какого-либо класса)
		/////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////

		map_level1.drawing_level();// вызываем метод вывода карты на экран (бесконечный цикл прорисовки)
		


		
		window.draw(test.sprite);

		if (Keyboard::isKeyPressed(Keyboard::Right))
			test.KeyRight();
		
		if (Keyboard::isKeyPressed(Keyboard::Left))
			test.KeyLeft();


		//»Ћ№я
		window.draw(b1.sprite);

		window.display();//вывод всех изображений на экран
	}



	//system("pause");
	// в дальнейшем, нужно переместить 
	return 0;
}