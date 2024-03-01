#pragma once
#include "raylib.h"
#include <vector>
#include <iostream>
#include "Enums.h"
#include "Spaceship.h"
#include <math.h>

using namespace varHolder;

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
		enemy(Vector2 position,float rotation,float scale, Color color, bool active, int check);

		
	};
	
	enemy enemies;
	
	
public:
	EnemyManager();
	void Draw();
	void enemyUpdate(Player_Ship& getShip);
	//void resetEnemy(enemy getEnemy);
	//void addingEnemyObj();
	std::vector<enemy> getEnemy();
	void resetEnemy(enemy& getEnemy);
	void enemyMovement(enemy& getEnemy, Player_Ship& getShip);
	std::vector <enemy> enemyPooling();
	std::vector <enemy> extractor;
	std::vector <enemy> handlers;
	enemy enemyMove;
};
