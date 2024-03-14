#include "Enemy.h"

int fps = 0;

EnemyManager::EnemyManager()
	:
	enemies(0.0f,{ 0,0 }, 0,0 , BLACK, false, 1),
	enemyMove(0.0f,{ 0,0 }, 0, 0, BLACK, false, 1)
{
	handlers = enemyPooling();
	extractor = getEnemy();
}

EnemyManager::enemy::enemy(float dmg, Vector2 position, float rotation, float scale, Color color, bool active, int check)
	:
	spriteTexture(LoadTexture("Image/Meteor_one.png")),
	damage(dmg),
	health(100.0f),
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

//Giving enemy object parameters
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
			float damage = 20.0f;
			

			if (extractor[i].spriteActive == false)
			{
				if (extractor[i].spriteScale == 0 && extractor[i].spritePosition.x == 0 && extractor[i].spritePosition.y == 0)
				{
					extractor[i].damage = damage;
					extractor[i].spriteScale = Scale;
					extractor[i].spritePosition = Position;
					extractor[i].spriteActive = true;
				}
			}
			
			enemyMovement(extractor[i], getShip);
		}
	}
}

//Calculating the distance between the enemy and the player and getting the magnitude of the Distance Vector || to make enemy move towards player
void EnemyManager::enemyMovement(enemy& getEnemy, Player_Ship& getShip)
{
	//centroid of the triangle
	float new_X = ((getShip.getPointTop().x + getShip.getPointRight().x + getShip.getPointLeft().x) / 3.0f);
	float new_Y = ((getShip.getPointTop().y + getShip.getPointRight().y + getShip.getPointLeft().y) / 3.0f);
	//34x34 original size of the sprite
	float spriteDimension = 34.0f;

	//divide the size of the enemy into half to make it go to the center of the player
	double x_distance = new_X - (getEnemy.spritePosition.x + ((getEnemy.spriteScale * spriteDimension) /2.0f));
	double y_distance = new_Y - (getEnemy.spritePosition.y + ((getEnemy.spriteScale * spriteDimension) / 2.0f));
	//normalizing the vector
	double normalized_V = sqrt(pow(x_distance,2) + pow(y_distance, 2));

	//magnitude
	getEnemy.spritePosition.y += (y_distance  /normalized_V) * getEnemy.spriteSpeed; 
	getEnemy.spritePosition.x += (x_distance / normalized_V) * getEnemy.spriteSpeed; 
}

//reset enemy value to zero and putting back to the pool
void EnemyManager::resetEnemy(enemy& getEnemy)
{
	if (getEnemy.spriteActive == true)
	{
		getEnemy.damage = 0.0f;
		getEnemy.health = 100.0f;
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


//Getting enemy from the pool
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


//Creating a pool
std::vector<EnemyManager::enemy> EnemyManager::enemyPooling()
{
	std::vector <enemy> enemyStorage;
	for (int i = 0; i < varHolder::enemyPool(); ++i)
	{
		enemy enemies = enemy{0.0f,{0,0}, 0, 0, WHITE, false, 5 };
		enemyStorage.push_back(enemies);
	}
	return enemyStorage;
}


