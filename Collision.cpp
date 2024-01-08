#include "Collision.h"

collision_Check::collision_Check()
{
}
//Try to access the struct from Player_ship class
void collision_Check::check_collision(EnemyManager& enemy_body, Player_Ship& ship_body)
{

	for (int i = 0; i < enemy_body.handlers.size(); ++i)
	{
		if (ship_body.getBullet()->rec.y == enemy_body.handlers[i].spritePosition.y && ship_body.getBullet()->rec.y == enemy_body.handlers[i].spritePosition.x)
		{
			DrawText("Object Collide", 300, 400, 15, WHITE);
		}
	}
		
	
	
}
