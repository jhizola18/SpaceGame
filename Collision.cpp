#include "Collision.h"
#include "math.h"
#include "assert.h"

collision_Check::collision_Check()
{
}

//Find a way to not exhaust the bullet storage
void collision_Check::check_collision(EnemyManager& enemy_body, BulletManager& bullet)
{
		
		for (int i = 0; i < enemy_body.extractor.size(); ++i)
		{
			//assert(!enemy_body.handlers.empty());
			int spriteDimension = 34;
			for (int j = 0; j < bullet.extractor.size(); ++j)
			{
				
				if (bullet.extractor[j].rec.y <= enemy_body.extractor[i].spritePosition.y + (spriteDimension * enemy_body.extractor[i].spriteScale) && bullet.extractor[j].rec.x >= enemy_body.extractor[i].spritePosition.x && bullet.extractor[j].rec.x + bullet.extractor[j].rec.width <= enemy_body.extractor[i].spritePosition.x + (spriteDimension * enemy_body.extractor[i].spriteScale))
				{
					DrawText("Object Collided Bottom Part", 200, 500, 15, WHITE);
					//enemy_body.extractor.erase(enemy_body.extractor.begin() + i);
					enemy_body.resetEnemy();

				}
				else if (enemy_body.extractor[i].spritePosition.y >= GetScreenHeight())
				{
					enemy_body.resetEnemy();
					//enemy_body.extractor.erase(enemy_body.extractor.begin() + i);
				}
			}
		}
}

bool collision_Check::on_screen(EnemyManager& enemy_body)
{
	int spriteDimension = 34;
	for (int i = 0; i < enemy_body.extractor.size(); ++i)
	{
		if (enemy_body.extractor[i].spritePosition.y + (spriteDimension * enemy_body.extractor[i].spriteScale) > GetScreenHeight())
		{
			return false;
		}
		else {
			return true;
		}

		
	}
}

