#include "Collision.h"
#include "assert.h"
#include <iterator>
#include "algorithm"
#include "Enums.h"

using namespace varHolder;

bool gameOver = false;
collision_Check::collision_Check()
{
}

void collision_Check::check_collision(EnemyManager& enemy_body, BulletManager& bullet, Player_Ship& ship_body)
{
	int spriteDimension = 34;
	for (int i = 0; i < bullet.extractor.size(); ++i)
	{
		//enemy to bullet and enemy to outbounds collision
		for (int j = 0; j < enemy_body.extractor.size(); ++j)
		{
			std::cout << " Bullet count-> " << i << " \nEnemy Count-> " << j << " \n";
			if (bullet.extractor[i].rec.y < enemy_body.extractor[j].spritePosition.y + (spriteDimension * enemy_body.extractor[j].spriteScale) && bullet.extractor[i].rec.x > enemy_body.extractor[j].spritePosition.x  && bullet.extractor[i].rec.x + bullet.extractor[i].rec.width < enemy_body.extractor[j].spritePosition.x + (spriteDimension * enemy_body.extractor[j].spriteScale))
			{
				enemy_body.extractor[j].health -= bullet.extractor[i].damage; 
				DrawText(TextFormat("Enemy_HEALTH: %f", enemy_body.extractor[j].health), 50, 50, 50, WHITE);
				//bullet.resetBullet(bullet.extractor[i]);
				if (enemy_body.extractor[j].health == 0.00f)
				{
					DrawText("Object Collided Bottom Part", 200, 500, 15, WHITE);
					bullet.resetBullet(bullet.extractor[i]);
					enemy_body.resetEnemy(enemy_body.extractor[j]);
				}
				
			}
			else {
				if (enemy_body.extractor[j].spritePosition.y > GetScreenHeight())
				{
					DrawText(" Out of Bounds ", 200, 500, 15, WHITE);
				}
				if (bullet.extractor[i].rec.y + bullet.extractor[i].rec.width < -GetScreenHeight())
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

	
	//another method to try getting the centroid of the triangle
	float new_X = ((ship_body.getPointTop().x + ship_body.getPointRight().x + ship_body.getPointLeft().x) /3);
	float new_Y = ((ship_body.getPointTop().y + ship_body.getPointRight().y + ship_body.getPointLeft().y) / 3);
	//enemy-player collision
	
	for (int check = 0; check < enemy_body.extractor.size(); ++check)
	{
		if (new_X > enemy_body.extractor[check].spritePosition.x && new_X  < enemy_body.extractor[check].spritePosition.x + (enemy_body.extractor[check].spriteScale * spriteDimension) && new_Y  > enemy_body.extractor[check].spritePosition.y && new_Y  < enemy_body.extractor[check].spritePosition.y + (enemy_body.extractor[check].spriteScale * spriteDimension))
		{
			
			ship_body.getHealth() -= enemy_body.extractor[check].damage;
			DrawText(TextFormat("Player Health: %f", ship_body.getHealth()), 50, 50, 50, WHITE);
			enemy_body.resetEnemy(enemy_body.extractor[check]);
			DrawText(" HIT ", 200, 500, 15, WHITE);
			if (ship_body.getHealth() == 0.0f)
			{
				gameOver = true;
				DrawText("Player Dead ", 200, 500, 15, WHITE);
				enemy_body.resetEnemy(enemy_body.extractor[check]);
			}
			
			
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