#include "Enemy.h"
#include<vector>
#include<iostream>

EnemyManager::EnemyManager()
	:
	enemies({0,0},0,0.0f,WHITE)
{
}
//Finish try to figure out how to randomize spawn outside the players screen
EnemyManager::enemy::enemy(Vector2 position, float rotation, float scale, Color color)
	:
	spriteTexture(LoadTexture("Image/meteor.png")),
	spriteColor (color),
	spritePosition(position),
	spriteRotation(rotation),
	spriteScale(scale)
{
	std::cout << "Enemy Created!!!" << std::endl;
}

//cant draw suddenly
void EnemyManager::enemy::Draw()
{
	EnemyManager enemymanager;
	std::vector<EnemyManager::enemy> enemies = enemymanager.enemyPooling();
	for (const auto& item : enemies)
	{
		DrawTextureEx(spriteTexture, item.spritePosition,item.spriteRotation, item.spriteScale, item.spriteColor);
		std::cout << "Enemy Drawm!!" << std::endl;
	}
	
}
//Fix the movement and spawing script
void EnemyManager::enemy::movement()
{
	EnemyManager enemymanager;
	std::vector<EnemyManager::enemy> enemiesMovement = enemymanager.enemyPooling();
	for(auto item : enemiesMovement)
	{
		item.spritePosition.y += 5;
	}
}


void EnemyManager::Draw()
{
	enemies.Draw();
}

void EnemyManager::enemyMovement()
{
	enemies.movement();
}

std::vector<EnemyManager::enemy> EnemyManager::enemyPooling()
{
	EnemyManager enemymanager;
	int maxSize = 7;
	int minY = 0;
	int maxY = GetScreenHeight()/4;
	int minX = 0;
	int maxX = GetScreenWidth();
	float minScale = 1.0f;
	float maxScale = 2.0f;
	Color color = WHITE;
	Vector2 spritePosition = {GetRandomValue(minX, maxX),GetRandomValue(minY, maxY)};
	float rotation = 0;
	float spriteScale = GetRandomValue(minScale, maxScale);
	for (int i = 0; i < maxSize; ++i)
	{
		enemy enemies = enemy{ spritePosition, rotation ,spriteScale, color};
		enemyHandler.push_back(enemies);
	}
	return enemyHandler;
}

