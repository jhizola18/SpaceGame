#pragma once
#include "raylib.h"

class Player_Ship {
private:
	Vector2 point_Top;
	Vector2 point_Left;
	Vector2 point_Right;

	struct Bullet {
		float posX;
		float posY;
		
		Rectangle rec;
		Color color;

		bool deadBullet;

		Bullet* next;
		Bullet* prev;
	};

	Bullet* firstBullet;//head
	Bullet* lastBullet;//tail

	Bullet* NewBullet(float posX, float posY);

public:

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

	void fireBullets();
	
};