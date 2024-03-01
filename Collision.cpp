#include "Collision.h"
//#include "math.h"
#include "assert.h"
#include <iterator>
#include "algorithm"

collision_Check::collision_Check()
{
}

void collision_Check::check_collision(EnemyManager& enemy_body, BulletManager& bullet)
{
	for (int i = 0; i < bullet.extractor.size(); ++i)
	{
		int spriteDimension = 34;
		for (int j = 0; j < enemy_body.extractor.size(); ++j)
		{
			std::cout << " Bullet count-> " << i << " \nEnemy Count-> " << j << " \n";
			if (bullet.extractor[i].rec.y <= enemy_body.extractor[j].spritePosition.y + (spriteDimension * enemy_body.extractor[j].spriteScale) && bullet.extractor[i].rec.x >= enemy_body.extractor[j].spritePosition.x && bullet.extractor[i].rec.x + bullet.extractor[i].rec.width <= enemy_body.extractor[j].spritePosition.x + (spriteDimension * enemy_body.extractor[j].spriteScale))
			{
				DrawText("Object Collided Bottom Part", 200, 500, 15, WHITE);
				bullet.resetBullet(bullet.extractor[i]);
				enemy_body.resetEnemy(enemy_body.extractor[j]);
			}
			else {
				if (enemy_body.extractor[j].spritePosition.y > 800)
				{
					DrawText(" Out of Bounds ", 200, 500, 15, WHITE);
					enemy_body.resetEnemy(enemy_body.extractor[j]);
					enemy_body.extractor.erase(enemy_body.extractor.begin() + j);
				}
				if (bullet.extractor[i].rec.y + bullet.extractor[i].rec.width < 0)
				{
					bullet.resetBullet(bullet.extractor[i]);
				}
			}
		}
		if (enemy_body.extractor.empty())
		{
			DrawText(" Pool Exhausted ", 200, 500, 15, WHITE);
		}

		for (int i = 0; i < bullet.extractor.size(); ++i)
		{
			if (bullet.extractor[i].id == 0 && bullet.extractor[i].bulletAlive == false)
			{
				bullet.extractor.erase(bullet.extractor.begin() + i);
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





//back burner codes

/*bool bulletReset;
	for (auto it = bullet.extractor.begin(); it != bullet.extractor.end(); it++)
	{
		bulletReset = false;
		int spriteDimension = 34;
		for (auto itr = enemy_body.extractor.begin(); itr != enemy_body.extractor.end(); )
		{

			if (it->rec.y <= itr->spritePosition.y + (spriteDimension * itr->spriteScale) && it->rec.x >= itr->spritePosition.x && it->rec.x + it->rec.width <= itr->spritePosition.x + (spriteDimension * itr->spriteScale))
			{
				int temp = (it - bullet.extractor.begin());
				//std::distance(bullet.extractor.begin(), it);
				DrawText("Object Collided Bottom Part", 200, 500, 15, WHITE);
				//bullet.resetBullet(*it);
				enemy_body.resetEnemy(*itr);
				itr = enemy_body.extractor.erase(itr);
				//it = bullet.extractor.begin();
				bulletReset = true;
			}
			else if (itr->spritePosition.y > 800) {

				int temp = (it - bullet.extractor.begin());
				DrawText(" Out of Bounds ", 200, 500, 15, WHITE);
				enemy_body.resetEnemy(*itr);
				itr = enemy_body.extractor.erase(itr);

				if (it->rec.y + it->rec.width < 0)
				{
					//bullet.resetBullet(*it);
					//it = bullet.extractor.begin();
					bulletReset = true;
				}
			}
			else {
				itr++;
			}
		}

	}*/



	/*for (int i = 0; i < bullet.extractor.size(); ++i)
		{
			int spriteDimension = 34;
			for (int j = 0; j < enemy_body.extractor.size(); ++j)
			{
				std::cout << " Bullet count-> " << i << ", Enemy Count-> " << j << " ";
				if (bullet.extractor[i].rec.y <= enemy_body.extractor[j].spritePosition.y + (spriteDimension * enemy_body.extractor[j].spriteScale) && bullet.extractor[i].rec.x >= enemy_body.extractor[j].spritePosition.x && bullet.extractor[i].rec.x + bullet.extractor[i].rec.width <= enemy_body.extractor[j].spritePosition.x + (spriteDimension * enemy_body.extractor[j].spriteScale))
				{
					DrawText("Object Collided Bottom Part", 200, 500, 15, WHITE);
					bullet.resetBullet(bullet.extractor[i]);
					enemy_body.resetEnemy(enemy_body.extractor[j]);
					enemy_body.extractor.erase(enemy_body.extractor.begin() + j);
				}
				else {
					if (enemy_body.extractor[j].spritePosition.y > 800)
					{
						DrawText(" Out of Bounds ", 200, 500, 15, WHITE);
						enemy_body.resetEnemy(enemy_body.extractor[j]);
						enemy_body.extractor.erase(enemy_body.extractor.begin() + j);
					}
				}
			}
		}*/