#include "Enemy.h"

int fps = 0;

EnemyManager::EnemyManager()
	:
	enemies({0,0},0,0.0f,BLACK, false,1)
{
	handlers = enemyPooling();
}

EnemyManager::enemy::enemy( Vector2 position, float rotation, float scale, Color color, bool active, int check)
	:
	spriteTexture(LoadTexture("Image/meteor.png")),
	spriteColor (color),
	spritePosition(position),
	spriteRotation(rotation),
	spriteScale(scale),
	spriteActive(active),
	spriteSpeed(GetRandomValue(2, 6)),
	checker(check)
{
	//std::cout << "Enemy Created!!!" << std::endl;
}

//find a way to spawn the objects individually using SPRITEACTIVE
void EnemyManager::Draw()
{
	fps++;
	for (auto& item : handlers)
	{
		if (fps > 148)
		{
			DrawTextureEx(enemies.spriteTexture, item.spritePosition, item.spriteRotation, item.spriteScale, item.spriteColor);
			std::cout << item.checker << " ";
		}
		//std::cout << "Enemy Drawm!!" << std::endl;
	}
	std::cout << "Finish iterating!! " << std::endl;
}

void EnemyManager::enemyUpdate()
{
	
	for (auto& item : handlers) {

		if (fps > 148)
		{
			int minY = -5;
			int maxY = -5;
			int minX = 0;
			int maxX = GetScreenWidth() - 50;
			Vector2 Position = { GetRandomValue(minX, maxX), GetRandomValue(minY, maxY) };
			int minScale = 1;
			int maxScale = 2;
			float Scale = GetRandomValue(minScale, maxScale);

			if (item.spriteActive == false) {

				if (item.spritePosition.y == 0 && item.spritePosition.x == 0)
				{
					item.spritePosition = Position;

				}
				if (item.spriteScale == 0)
				{
					item.spriteScale = Scale;
				}
			}
			item.spritePosition.y += item.spriteSpeed;
		}
	}
	addingEnemyObj();
	deleteEnemy();
}

void EnemyManager::deleteEnemy()
{
	for (int i = 0; i < handlers.size(); ++i)
	{
		if (handlers[i].spritePosition.y > GetScreenHeight())
		{
			handlers.erase(handlers.begin() + i);
		}
	}
}

void EnemyManager::addingEnemyObj()
{
	
	if (handlers.empty())
	{
		std::cout << "Empty!!";
		for (int i = 0; i < varHolder::maxSize(); ++i)
		{
			int minY = -20;
			int maxY = -20;
			int minX = -5;
			int maxX = GetScreenWidth() - 50;
			Vector2 Position = { GetRandomValue(minX, maxX), GetRandomValue(minY, maxY) };
			int minScale = 1;
			int maxScale = 2;
			float Scale = GetRandomValue(minScale, maxScale);

			enemies = enemy{ {Position.x, Position.y}, 0, Scale, WHITE, false,5 };
			handlers.push_back(enemies);
		}	
	}
}

//Change to single push but can spawn immediatley depends on the firs spawn position
std::deque<EnemyManager::enemy> EnemyManager::enemyPooling()
{
	
	std::deque <enemy> enemyStorage;
	for (int i = 0; i < varHolder::maxSize(); ++i)
	{
		enemy* enemies = new enemy{ {0,0}, 0, 0, WHITE, false, 5 };
		enemyStorage.push_back(*enemies);
	}
	return enemyStorage;
}

