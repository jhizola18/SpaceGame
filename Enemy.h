#pragma once
#include "raylib.h"
#include <queue>
#include <vector>
#include <iostream>
#include "Enums.h"

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
	void enemyUpdate();
	void resetEnemy();
	void addingEnemyObj();
	std::vector<enemy> getEnemy();
	std::vector <enemy> enemyPooling();
	std::vector <enemy> handlers;
	std::vector <enemy> extractor;
};
