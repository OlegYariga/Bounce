
#include <SFML/Graphics.hpp>

using namespace sf;

class Wasp {
public:
	//wasp();
	Sprite killer_wasp;
	Wasp();
	 

	//void kill();  
	void move_wasp();
	void show_wasp();
	
	
private:
	Texture Image_wasp;
};