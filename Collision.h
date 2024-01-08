#pragma once
#include "raylib.h"
#include "Enemy.h"
#include "Spaceship.h"

class collision_Check {
private:
	EnemyManager enemy_body;
	Player_Ship ship_body;
	

public:
	collision_Check();
	void check_collision(EnemyManager& enemy_body, Player_Ship& ship_body);
	
};