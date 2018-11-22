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
	//добавил
	bool check;
	int coordinateX = 0;
	int coordinateY = 0;

private:
	Texture Image_wasp;
};