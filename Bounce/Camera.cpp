#include "engine.h"
#include "Camera.h"
#include <iostream>
using namespace std;
Camera::Camera() {
	ball_camera.reset(sf::FloatRect(0, 0, 1200, 600));
	coordinateY = 0;
}
void Camera::changeCameraPosition(float x, float y) {
	float tempX = x; float tempY = y;//считываем коорд игрока и проверяем их, чтобы убрать края
	tempY=createCoordinateY(y);
	if (x < 600) tempX = 600;//убираем из вида левую сторону
	if (y < 240) tempY = 240;//верхнюю сторону
	if (y > 554) tempY = 554;//нижнюю сторону	
	ball_camera.setCenter(tempX, tempY);
}

float Camera::createCoordinateY(float y) {
	if (coordinateY == 0) coordinateY = y;
	if (y-coordinateY>500||coordinateY-y>500) {
		coordinateY = y;
		//cout <<"!!!!!"<< coordinateY<<endl;
		return y;
	}
	else {
		//cout << coordinateY << endl;
		return coordinateY;
	}
}