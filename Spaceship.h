#pragma once
#include "raylib.h"
#include "Enums.h"
#include<vector>
#include "Bullet.h"

using namespace varHolder;

class Player_Ship {
private:
	Vector2 point_Top;
	Vector2 point_Left;
	Vector2 point_Right;

	float gravity_Y;
	float gravity_X;
	float speed;

	
public:
	
	BulletManager bullet;
	Vector2 getPointTop();
	Vector2 getPointRight();
	Vector2 getPointLeft();

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

	
	//std::vector<Bullet> handler;
	
	
	
};