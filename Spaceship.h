#pragma once
#include "raylib.h"

class Player_Ship {
private:
	Vector2 point_Top;
	Vector2 point_Left;
	Vector2 point_Right;

public:
	Player_Ship();

	float velocity;
	float speed;
	void Draw();
	void moveForward();
	void moveBackward();
};