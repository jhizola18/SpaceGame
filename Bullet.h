#pragma once
#include "raylib.h"

class BulletManager {

private:
	class Bullet {
	public:
		Rectangle rec;
		int bulletSpeed;
		bool bulletAlive;
		//int damage;
		
		Color color;
		Bullet(Rectangle rect, int speed, bool alive, Color col);
	};
	static Bullet bullets;
public:
	
	void drawBullet();
	void updateBullet(float posX, float posY, Bullet getBullet);
	void bulletMovement();

	BulletManager();

	Bullet getBullet();
	std::vector<Bullet> bullet_Pool(); 
	std::vector<Bullet> extractor;
	std::vector<Bullet> pool;
	
};
