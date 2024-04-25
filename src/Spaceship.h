#pragma once
#include "raylib.h"
#include<vector>
#include "Bullet.h"
#include "Enums.h"


class Player_Ship {
private:
	Vector2 point_Top;
	Vector2 point_Left;
	Vector2 point_Right;
	
	float gravity_Y;
	float gravity_X;
	float speed;
	Vector2 position;
	float health;

	
public:
	
	BulletManager bullet;
	Vector2 getPointTop() const;
	Vector2 getPointRight() const;
	Vector2 getPointLeft() const;
	std::vector<Vector2> vertices;
	Vector2 rotatePos(Vector2 position,Vector2 origin, float angle_degrees);

	float& getHealth();
	
	Player_Ship();
	~Player_Ship();
	void ResetShip();

	void Draw();
	
	void rotationShip(Vector2 Top, Vector2 Right, Vector2 Left);

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