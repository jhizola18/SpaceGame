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

		Color color;

		bool deadBullet;
		bool firedBullet;

		Bullet* next;
		Bullet* prev;
	};

	Bullet* firstBullet;//head
	Bullet* lastBullet;//tail

	Bullet* NewBullet(Bullet* head, float pos_X, float pos_Y);

	int clipSize;

public:

	Vector2 getPointTop();

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

	void renderBullets(int posX,int posY);
	void updateBullets(float velocity, float posY);
	void reloadBullets();
	void fireBullets(float velocity, float posY);
	
	float getVelocity();
};