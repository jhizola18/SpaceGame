#pragma once
#include "Spaceship.h"
#include "Enemy.h"
#include "Collision.h"
#include "MenuManager.h"
#include "Audio.h"


class Game {
private:
	Player_Ship ship = Player_Ship();
	EnemyManager enemy = EnemyManager();
	collision_Check collision = collision_Check();
	BulletManager bullet = BulletManager();
	EnemyManager enemies = EnemyManager();
	Menu menu = Menu();
	Audio* audio = new Audio();

public:
	Game();
	~Game()noexcept;

	void resetGame();
	void userInput();
	void Draw(int colortype);
	void gameMechanics();
	void MainGame();
	int velocity;
	float positionY;
	float positionX;
};