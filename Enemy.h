#pragma once
#include "raylib.h"
#include<vector>

class EnemyManager {
private:
	class enemy {
	private:
		Texture2D spriteTexture;
		Vector2 spritePosition;
		float spriteRotation;
		float spriteScale;
		Color spriteColor;

	public:
		enemy(Vector2 position, float rotation, float scale, Color color);
		void Draw();
		void movement();
	};

	std::vector<enemy> enemyHandler;
	enemy enemies;
public:

	EnemyManager();
	void Draw();
	void enemyMovement();
	std::vector<enemy> enemyPooling();
};
