#pragma once
#include "engine.h"
#include <SFML/Graphics.hpp>

class Camera {
public:
	View ball_camera;
	Camera();
	void changeCameraPosition(float x, float y);
};