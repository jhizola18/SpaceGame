#include "Enemy.h"

int fps = 0;

EnemyManager::EnemyManager()
	:
	enemies({ 0,0 }, 0,0 , BLACK, false, 1)
{
	handlers = enemyPooling();
	extractor = getEnemy();
}

EnemyManager::enemy::enemy( Vector2 position, float rotation, float scale, Color color, bool active, int check)
	:
	spriteTexture(LoadTexture("Image/Meteor_one.png")),
	spriteColor (color),
	spritePosition(position),
	spriteScale(scale),
	spriteRotation(rotation),
	spriteActive(active),
	spriteSpeed(GetRandomValue(2,4)),
	checker(check)
{
	//std::cout << "Enemy Created!!!" << std::endl;
}

void EnemyManager::Draw()
{
	fps++;
	for (auto& item : extractor)
	{
		if (fps > 148)
		{
			DrawTextureEx(enemies.spriteTexture,item.spritePosition, item.spriteRotation, item.spriteScale,item.spriteColor);
			//DrawRectangle(item.spritePosition.x, item.spritePosition.y, item.spriteRectangle.width, item.spriteRectangle.height, item.spriteColor);
			std::cout << item.checker << " ";
		}
		//std::cout << "Enemy Drawm!!" << std::endl;
	}
	std::cout << "Finish iterating!! " << std::endl;
}

void EnemyManager::enemyUpdate()
{
	for (int i = 0; i < extractor.size(); i++)
	{
		if (fps > 148)
		{
			int minY = -5;
			int maxY = -5;
			int minX = 0;
			int maxX = GetScreenWidth() - 50;
			Vector2 Position = { GetRandomValue(minX, maxX), GetRandomValue(minY, maxY) };
			float Scale = 1.5f;

			if (extractor[i].spriteActive == false)
			{
				if (extractor[i].spriteScale == 0 && extractor[i].spritePosition.x == 0 && extractor[i].spritePosition.y == 0)
				{
					extractor[i].spriteScale = Scale;
					extractor[i].spritePosition = Position;
					extractor[i].spriteActive = true;
					extractor[i].spriteSpeed = 5;
				}
			}
			extractor[i].spritePosition.y += extractor[i].spriteSpeed;
		}
	}
}

void EnemyManager::resetEnemy()
{
	for (int i = 0; i < extractor.size(); ++i)
	{
		if (extractor[i].spriteActive == false)
		{
			extractor[i].spritePosition.y = 0;
			extractor[i].spritePosition.x = 0;
			extractor[i].spriteSpeed = 0;
			extractor[i].spriteColor = BLACK;
		}
	}
}

void EnemyManager::addingEnemyObj()
{
	std::cout << "ADDING ENEMY!!! ";
	if (handlers.empty())
	{
		std::cout << "Empty!!";
		for (int i = 0; i < varHolder::enemySize(); ++i)
		{
			int minY = -20;
			int maxY = -20;
			int minX = -5;
			int maxX = GetScreenWidth() - 50;
			Vector2 Position = { GetRandomValue(minX, maxX), GetRandomValue(minY, maxY) };
			float Scale = 1.5f;
			enemies = enemy{ {Position.x, Position.y}, 0, Scale, WHITE, false,5};
			
			handlers.push_back(enemies);
		}	
	}
}

std::vector<EnemyManager::enemy> EnemyManager::getEnemy()
{
	std::vector<EnemyManager::enemy> hold;
	for (int i = 0; i < varHolder::enemySize(); ++i)
	{
		enemies = handlers.front();
		hold.push_back(enemies);
		handlers.pop_back();
	}
	
	return hold;
}


//Change to single push but can spawn immediatley depends on the firs spawn position
std::vector<EnemyManager::enemy> EnemyManager::enemyPooling()
{
	std::vector <enemy> enemyStorage;
	for (int i = 0; i < varHolder::enemyPool(); ++i)
	{
		enemy enemies = enemy{ {0,0}, 0, 0, WHITE, false, 5 };
		enemyStorage.push_back(enemies);
	}
	return enemyStorage;
}


