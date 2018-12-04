#include "engine.h"
#include "Camera.h"
#include <iostream>
using namespace std;
Camera::Camera() {
	ball_camera.reset(sf::FloatRect(0, 0, 1200, 600));
}
void Camera::changeCameraPosition(float x, float y) {
	float tempX = x; float tempY = y;//��������� ����� ������ � ��������� ��, ����� ������ ����
	if (x < 600) tempX = 600;//������� �� ���� ����� �������
	if (y < 240) tempY = 240;//������� �������
	if (y > 554) tempY = 554;//������ �������	
	ball_camera.setCenter(tempX, tempY);
}