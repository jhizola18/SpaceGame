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
		float damage;
		
		Color color;
		Bullet(int id, float dmg ,Rectangle rect, int speed, bool alive, Color col);
	};
	static Bullet bullets;
	 
	
public:
	
	void drawBullet();
	void updateBullet(float posX, float posY, Bullet getBullet);
	void bulletMovement(Vector2 target, float dist);

	BulletManager();
	~BulletManager()noexcept;

	Bullet getBullet();
	void resetBullet(Bullet& getBullet);
	void resetAllBullet();
	std::deque<Bullet> bullet_Pool(); 
	std::deque<Bullet> extractor;
	std::deque<Bullet> pool;
};
