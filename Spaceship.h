#pragma once
#include "raylib.h"
#include<vector>
#include "Bullet.h"



class Player_Ship {
private:
	Vector2 point_Top;
	Vector2 point_Left;
	Vector2 point_Right;

	float gravity_Y;
	float gravity_X;
	float speed;
	float health;

	
public:
	
	BulletManager bullet;
	Vector2 getPointTop() const;
	Vector2 getPointRight() const;
	Vector2 getPointLeft() const;

	float& getHealth();
	
	Player_Ship();
	~Player_Ship();
	void ResetShip();

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