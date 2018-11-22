#include "engine.h"
#include "Camera.h"

Camera::Camera() {
	ball_camera.reset(sf::FloatRect(0, 0, 1200, 600));
}
void Camera::changeCameraPosition(float x, float y) {
	ball_camera.setCenter(x,y);
}