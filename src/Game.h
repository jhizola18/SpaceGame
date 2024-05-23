#pragma once
#include "Spaceship.h"
#include "Enemy.h"
#include "Collision.h"


class Game {
private:
	Player_Ship ship = Player_Ship();
	EnemyManager enemy = EnemyManager();
	collision_Check collision = collision_Check();
	BulletManager bullet = BulletManager();
	EnemyManager enemies = EnemyManager();

public:
	Game();
	~Game()noexcept;

	void resetGame();
	void userInput();
	void Draw(int colortype);
	void gameMechanics();
	int velocity;
	float positionY;
	float positionX;
};