#pragma once
#include "raylib.h"
#include <vector>
#include <iostream>
#include "Spaceship.h"
#include <math.h>

class EnemyManager {
private:
	class enemy {
	public:
		Texture2D spriteTexture;
		Vector2 spritePosition;
		float spriteRotation;
		float spriteScale;
		bool spriteActive;
		Color spriteColor;
		int checker;
		int spriteSpeed;
		float health;
		float damage;
		enemy(float dmg, Vector2 position,float rotation,float scale, Color color, bool active, int check);
	};
	
	enemy enemies;
	
public:
	EnemyManager();
	~EnemyManager() noexcept;

	void resetEnemy();
	void Draw();
	void enemyUpdate(Player_Ship& getShip);
	std::vector<enemy> getEnemy();
	void resetEnemy(enemy& getEnemy);
	void resetFullEnemy();
	void enemyMovement(enemy& getEnemy, Player_Ship& getShip);
	std::vector <enemy> enemyPooling();
	std::vector <enemy> extractor;
	std::vector <enemy> handlers;
	
};
