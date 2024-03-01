#include "Enemy.h"

int fps = 0;

EnemyManager::EnemyManager()
	:
	enemies({ 0,0 }, 0,0 , BLACK, false, 1),
	enemyMove({ 0,0 }, 0, 0, BLACK, false, 1)
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
}

void EnemyManager::Draw()
{
	fps++;
	for (auto& item : extractor)
	{
		if (fps > 148)
		{
			if (item.spriteActive == true)
			{
				DrawTextureEx(enemies.spriteTexture, item.spritePosition, item.spriteRotation, item.spriteScale, item.spriteColor);
			}
			else {
				continue;
			}
			
		}
	}
}

void EnemyManager::enemyUpdate(Player_Ship& getShip)
{
	if (extractor.size() == 2 || extractor.empty())
	{
		extractor = getEnemy();
	}
	if (handlers.empty())
	{
		std::cout << " Empty pool ";
	}
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
				}
			}
			
			enemyMovement(extractor[i], getShip);
		}
	}
}
//study this code and the use of the trigo signs
void EnemyManager::enemyMovement(enemy& getEnemy, Player_Ship& getShip)
{
	double x_distance = getShip.getPointTop().x - getEnemy.spritePosition.x;
	double y_distance = getShip.getPointTop().y - getEnemy.spritePosition.y;

	double normalized_V = sqrt(pow(x_distance, 2) + pow(y_distance, 2));


	getEnemy.spritePosition.y += (y_distance / normalized_V) * getEnemy.spriteSpeed; 
	getEnemy.spritePosition.x += (x_distance / normalized_V) * getEnemy.spriteSpeed; 
}

void EnemyManager::resetEnemy(enemy& getEnemy)
{
	if (getEnemy.spriteActive == true)
	{
		getEnemy.spritePosition.y = 0;
		getEnemy.spritePosition.x = 0;
		getEnemy.spriteRotation = 0;
		getEnemy.spriteScale = 0;
		getEnemy.checker = 0;
		getEnemy.spriteColor = WHITE;
		getEnemy.spriteActive = false;
		handlers.push_back(getEnemy);
	}
}


//Spawn enemy if the container is empty
std::vector<EnemyManager::enemy> EnemyManager::getEnemy()
{
	std::vector<EnemyManager::enemy> hold;
	for (int i = 0; i < varHolder::enemySize(); ++i)
	{
		enemies = handlers.back();
		hold.push_back(enemies);
		handlers.pop_back();
	}
	if (handlers.empty())
	{
		std::cout << " EMPTY Pool ";
	}
	return hold;
}


//check storage of the pool if exhausted
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


