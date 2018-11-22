#include <SFML/Graphics.hpp>

using namespace sf;

class Wasp {
public:
	//wasp();
	Sprite killer_wasp;
	Wasp();
	float  x = 32;
	float  dx = 0.08;
	float time_game = 0;
	//  void kill(); апвап 

	void move_wasp(float a);
	void show_wasp(float a);


<<<<<<< HEAD
=======
	//void kill();  
	void move_wasp();
	void show_wasp();
	
	
>>>>>>> a8c959fa613a8a22bc5cfd9f438d8660d1136da1
private:
	Texture Image_wasp;
};