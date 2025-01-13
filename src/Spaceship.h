#pragma once
#include "raylib.h"
#include<vector>
#include "Bullet.h"
#include "Enums.h"


class Player_Ship {
private:
	Texture2D ShipTexture;

	Vector2 point_Top;
	Vector2 point_Left;
	Vector2 point_Right;
	
	float gravity_Y;
	float gravity_X;
	float speed;
	Vector2 position;
	float health;
	int ship_colors;
	std::vector<Color> coloreds;
	
public:
	
	BulletManager bullet;
	Vector2 getPointTop() const;
	Vector2 getPointRight() const;
	Vector2 getPointLeft() const;
	int& getship_color();
	std::vector<Vector2> vertices;


	float& getHealth();
	
	Player_Ship();
	~Player_Ship();
	void ResetShip();


	void Draw(int colortype);

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