#include "Enemy.h"
#include "Enums.h"
#include "unordered_map"

//Think of ways to implement buffed enemy
using namespace varHolder;
Level_State level_state;

int fps = 0;

EnemyManager::EnemyManager()
	:
	enemies(0.0f,{ 0,0 }, 0,0 , BLACK, false, 1)
{
	handlers = enemyPooling();
	extractor = getEnemy();
}

EnemyManager::~EnemyManager()
{
	std::cout << "Enemy Manager Object Destroyed\n";
}

void EnemyManager::resetEnemy()
{
	for (unsigned int i = 0; i < handlers.size(); ++i)
	{
		handlers.pop_back();
	}
	for (unsigned int j = 0; j < extractor.size(); ++j)
	{
		extractor.pop_back();
	}
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
	spriteSpeed(GetRandomValue(100,250)),
	checker(check)
{
}


void EnemyManager::resetFullEnemy()
{
	level_state = Level1;
	for (unsigned int i = 0; i < extractor.size(); ++i)
	{
		extractor[i].spritePosition = { 0, 0 };
		extractor[i].checker = 0;
		extractor[i].spriteColor = WHITE;
		extractor[i].spriteRotation = 0;
		extractor[i].spriteScale = 0;
		extractor[i].health = 100.0f;
		extractor[i].spriteActive = false;
		extractor[i].damage = 0.0f;
		fps = 0;
	}
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

	int minY = -5;
	int maxY = -5;
	int minX = -5;
	int maxX = 0;
	Vector2 Position = { 0.0f, 0.0f };
	float Scale = 0.0f;
	float damageS = 0.0f;
	int health = 0;
	//LEVEL TRY TO CREATE AN ENDLESS LEVEL USING MATH TO CALCULATE
	switch (level_state)
	{
	case Level1:
		minY = -5;
		maxY = -5;
		minX = 0;
		maxX = GetScreenWidth() - 50;
		Position = { (float)GetRandomValue(minX, maxX), (float)GetRandomValue(minY, maxY) };
		Scale = 1.5f;
		damageS = 20.0f;
		health = 100;
		if (Destroyed == 15)
		{
			DrawText("LEVEL 2", 400, 400, 20, WHITE);
			level_state = Level2;
		}
		break;
	case Level2:
		minY = -5;
		maxY = -5;
		minX = 0;
		maxX = GetScreenWidth() - 50;
		Position = { (float)GetRandomValue(minX, maxX), (float)GetRandomValue(minY, maxY) };
		Scale = 1.2f;
		damageS = 30.0f;
		health = 150.0f;
		if (Destroyed == 30)
		{
			DrawText("LEVEL 3", 400, 400, 20, WHITE);
			level_state = Level3;
		}
		break;
	case Level3:
		minY = -5;
		maxY = -5;
		minX = 0;
		maxX = GetScreenWidth() - 50;
		Position = { (float)GetRandomValue(minX, maxX), (float)GetRandomValue(minY, maxY) };
		Scale = GetRandomValue(1.2f, 1.5f);
		damageS = 50.0f;
		health = 200.0f;
		if (Destroyed == 50)
		{
			DrawText("YOU WIN!!!", 400,400, 20, WHITE);
			gameOver = true;
		}
		break;
	default:
		break;
	}

	for (unsigned int i = 0; i < extractor.size(); i++)
	{
		if (fps > 148)
		{
		
			if (extractor[i].spriteActive == false)
			{
				if (extractor[i].spriteScale == 0 && extractor[i].spritePosition.x == 0 && extractor[i].spritePosition.y == 0)
				{
					extractor[i].health = health;
					extractor[i].damage = damageS;
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
	float delta = GetFrameTime();
	//centroid of the triangle
	float new_X = ((getShip.getPointTop().x + getShip.getPointRight().x + getShip.getPointLeft().x) / 3.0f);
	float new_Y = ((getShip.getPointTop().y + getShip.getPointRight().y + getShip.getPointLeft().y) / 3.0f);
	//34x34 original size of the sprite
	float spriteDimension = 34.0f;

	//Distance between the player and the enemy divide by two to make the enemy move towards the center of the player
	float x_distance = new_X - (getEnemy.spritePosition.x + ((getEnemy.spriteScale * spriteDimension) /2.0f));
	float y_distance = new_Y - (getEnemy.spritePosition.y + ((getEnemy.spriteScale * spriteDimension) / 2.0f));
	//normalizing the vector || magnitude of a vector
	float magnitudeV = sqrt((float)pow(x_distance, 2) + (float)pow(y_distance, 2));

	float norm_X = x_distance / abs(magnitudeV);
	float norm_Y = y_distance / abs(magnitudeV);

	//adding the calculated distance to the new position x,y of the enemy
	getEnemy.spritePosition.y += (norm_Y * getEnemy.spriteSpeed) * delta;
	getEnemy.spritePosition.x += (norm_X * getEnemy.spriteSpeed) * delta;
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


