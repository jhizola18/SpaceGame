#pragma once
#include "raylib.h"
#include "Enemy.h"
#include "Spaceship.h"
#include "Bullet.h"

class collision_Check {
private:
	EnemyManager enemy_body;
	Player_Ship ship_body;
	BulletManager bullet;
	
public:
	collision_Check();
	void check_collision(EnemyManager& enemy_body, BulletManager& bullet);
	bool on_screen(EnemyManager& enemy_body);
};