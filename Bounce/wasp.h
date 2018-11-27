#include <SFML/Graphics.hpp>
#include <string.h>
using namespace sf;
 

class Wasp {
public:

	Wasp();
	
	//float  dx, dy;
	FloatRect k_rect;  // для координат 
	bool k_onGroung;   // стена ли?
	float  x=0;
	float  dx = 0.8;
	Sprite killer_wasp;
	Texture t;
	
	
	float k_currentFrame = 0;  // для анимации номер текущего кадра
	float time_game = 0;
<<<<<<< HEAD
	//  void kill(); апвап 
	
	void move_wasp(float a);
	void show_wasp(float a);
	//добавил
	bool check;
	int coordinateX = 0;
	int coordinateY = 0;

private:
	Texture Image_wasp;
=======

	void move_wasp(float a);
	void show_wasp(float a);
	void collision_K();
>>>>>>> dev_Katia
};