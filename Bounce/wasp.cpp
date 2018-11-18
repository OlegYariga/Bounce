
#include "wasp.h"



Wasp::Wasp(){ 

	Image_wasp.loadFromFile("wasp1.png"); //загружаем файл
    //Image_wasp.createMaskFromColor(Color(0,0,0)) - //маска - убирает цвет из картинки (создает прозрачность)
   
	killer_wasp.setTexture(Image_wasp);//заряжаем текстуру картинкой

	killer_wasp.setTextureRect(IntRect(0, 0, 35, 35));// нужный прямоугольник с осой
	killer_wasp.setPosition(500, 180);  // где поставили осу на карте  (ОЛЕГ НАРИСУЙ НА КАРТЕ УЛИЙ!!!)
}

void Wasp::kill () {

	//window.draw(sprite); Инклужу engine.h, получаю ошибку компиляции
}

void Wasp::move_wasp() {
	 
	
	 
	}
	




