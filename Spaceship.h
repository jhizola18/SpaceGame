#pragma once
#include "raylib.h"

class Player_Ship {
private:
	Vector2 point_Top;
	Vector2 point_Left;
	Vector2 point_Right;

	int playerBullet;

	struct Bullet {
		float posX;
		float posY;
		
		bool deadBullet = false;

		Bullet* next;
		Bullet* prev;
	};

public:
	Bullet* bullet;

	Player_Ship();
	
	float gravity_Y;
	float gravity_X;
	float speed;
	
	void Draw();

	void moveForward();
	void gravityForward();

	void moveBackward();
	void gravityBackward();

	void moveLeft();
	void gravityLeft();

	void moveRight();
	void gravityRight();

	void gravityReset();
};