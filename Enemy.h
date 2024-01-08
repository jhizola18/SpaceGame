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
		enemy(Vector2 position, float rotation, float scale, Color color, bool active, int check);
	};
	void deleteEnemy();
	enemy enemies;
public:
	EnemyManager();
	void Draw();
	void enemyUpdate();
	void addingEnemyObj();
	std::deque <enemy> enemyPooling();
	std::deque <enemy> handlers;
};
