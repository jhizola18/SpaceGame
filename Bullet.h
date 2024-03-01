#pragma once
#include "raylib.h"
#include "deque"

class BulletManager {

private:
	class Bullet {
	public:
		int id;
		Rectangle rec;
		int bulletSpeed;
		bool bulletAlive;
		//int damage;
		
		Color color;
		Bullet(int id, Rectangle rect, int speed, bool alive, Color col);
	};
	static Bullet bullets;
	 
	
public:
	
	void drawBullet();
	void updateBullet(float posX, float posY, Bullet getBullet);
	void bulletMovement();

	BulletManager();

	Bullet getBullet();
	void resetBullet(Bullet& getBullet);
	void deleteBulletFromContainer(Bullet* getBullet);
	std::deque<Bullet> bullet_Pool(); 
	std::deque<Bullet> extractor;
	std::deque<Bullet> pool;
	//std::vector<Bullet>::iterator it;
	
};
