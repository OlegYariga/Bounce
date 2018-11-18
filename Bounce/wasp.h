
#include <SFML/Graphics.hpp>

using namespace sf;

class Wasp {
public:
	//wasp();
	Sprite killer_wasp;
	Wasp();
	 

	void kill(); //прорисовка спрайта
	void move_wasp();
	
	
private:
	Texture Image_wasp;
};