#pragma once
#include "Spaceship.h"
#include "Enemy.h"
#include "Collision.h"

class Game {
private:
	Player_Ship ship = Player_Ship();
	EnemyManager enemy = EnemyManager();
	collision_Check collision = collision_Check();
	BulletManager bullet;
	EnemyManager enemies;
public:
	Game();
	void userInput();
	void Draw();
	void gameMechanics();
	int velocity;
	int positionY;
	int positionX;
};