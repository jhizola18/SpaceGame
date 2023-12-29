#pragma once
#include "raylib.h"




class Player_Ship {
private:
	Vector2 point_Top;
	Vector2 point_Left;
	Vector2 point_Right;

	struct Bullet {
		Rectangle rec;
		int bulletSpeed;
		int data;
		//int damage;

		Color color;

		Bullet* next;
		Bullet* prev;
	};

	Bullet* firstBullet;//head
	Bullet* lastBullet;//tail
	Bullet* thisBullet;
	Bullet* deadBullet;

	Bullet* NewBullet();

	int bulletVelocity;
	float gravity_Y;
	float gravity_X;
	float speed;
	void storeBullets();
	
public:
	
	Vector2 getPointTop();

	Player_Ship();
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

	
	void updateBullets(int posY, int posX);
	void fireBullets( int posY, int posX);
	void renderBullets();
	void deleteBullet();
	void reloadBullets();

	bool isActive();
	bool isDead();
};