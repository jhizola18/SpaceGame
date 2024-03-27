#include "Spaceship.h"
#include <iostream>
#include "assert.h"
#include "Enums.h"

using namespace varHolder;

int magCount;

Player_Ship::Player_Ship()
	:
	bullet()
{
	gravity_Y = 9.08f;
	gravity_X = 0.0f;
	point_Top = {300, 720};
	point_Left = {280 , 750};
	point_Right = { 320, 750 };
	speed = 250.0f;
	health = 100.0f;
}

Player_Ship::~Player_Ship()
{
	std::cout << "OBJECT DESTROYED(SHIP)\n";
}

void Player_Ship::ResetShip()
{
	point_Top = { 0, 0 };
	point_Left = { 0 , 0 };
	point_Right = { 0, 0 };
	speed = 0.0f;
	gravity_Y = 9.08f;
	gravity_X = 0.0f;
	health = 0.0f;
}


Vector2 Player_Ship::getPointTop() const
{
	return point_Top;
}


Vector2 Player_Ship::getPointRight() const
{
	return point_Right;
}

Vector2 Player_Ship::getPointLeft() const
{
	return point_Left;
}
float& Player_Ship::getHealth()
{
	return health;
}
void Player_Ship::Draw()
{
	//counterclockwise
	DrawTriangle(point_Top, point_Left, point_Right, BLUE);
}


//Figure out how to have applied gravity on all directions
void Player_Ship::moveForward()
{
	float deltaF = GetFrameTime();
	point_Top.y -= speed * deltaF;
	point_Left.y -= speed * deltaF;
	point_Right.y -= speed * deltaF;
	gravity_Y++;
}
void Player_Ship::gravityForward()
{
	float deltaF = GetFrameTime();
	point_Top.y -= gravity_Y * deltaF;
	point_Left.y -= gravity_Y * deltaF;
	point_Right.y -= gravity_Y * deltaF;
}

void Player_Ship::moveBackward()
{
	float deltaB = GetFrameTime();
	point_Top.y += speed * deltaB;
	point_Left.y += speed * deltaB;
	point_Right.y += speed * deltaB;
	gravity_Y--;
}

void Player_Ship::gravityBackward()
{
	float deltaB = GetFrameTime();
	point_Top.y -= gravity_Y * deltaB;
	point_Left.y -= gravity_Y * deltaB;
	point_Right.y -= gravity_Y * deltaB;
}


void Player_Ship::moveLeft()
{
	float deltaL = GetFrameTime();
	point_Top.x -= speed * deltaL;
	point_Left.x -= speed * deltaL;
	point_Right.x -= speed * deltaL;
	gravity_X++;
}

void Player_Ship::gravityLeft()
{
	float deltaL = GetFrameTime();
	point_Top.x -= gravity_X  * deltaL;
	point_Left.x -= gravity_X * deltaL;
	point_Right.x -= gravity_X * deltaL;
	
}


void Player_Ship::moveRight()
{
	float deltaR = GetFrameTime();
	point_Top.x += speed * deltaR;
	point_Left.x += speed * deltaR;
	point_Right.x += speed * deltaR;
	gravity_X--;
}

void Player_Ship::gravityRight()
{
	float deltaR = GetFrameTime();
	point_Top.x -= gravity_X * deltaR;
	point_Left.x -= gravity_X * deltaR;
	point_Right.x -= gravity_X * deltaR;
}


void Player_Ship::gravityReset()
{
	int Pressed = GetKeyPressed();
	switch(Pressed){
	case KEY_W:
		gravity_Y = 9.08f;
		break;
	case KEY_S:
		gravity_Y = -9.08f;
		break;
	case KEY_A:
		gravity_X = -9.08f;
		break;
	case KEY_D:
		gravity_X = 9.08f;
		break;
	default:
		break;
	}
}


//OBJECT POOLING
BulletManager::Bullet::Bullet(int id, float dmg, Rectangle rect, int speed, bool alive, Color col)
	:
	id(id),
	damage(dmg),
	rec(rect),
	bulletSpeed(speed),
	bulletAlive(alive),
	color(col)
{
};

BulletManager::BulletManager()
{
	pool = bullet_Pool();
}

void BulletManager::resetBullet(Bullet& getBullet)
{
	getBullet.id = 0;
	getBullet.damage = 0.0f;
	getBullet.rec = { 0.0f, 0.0f, 0.0f, 0.0f };
	getBullet.bulletSpeed = 0;
	getBullet.color = BLACK;
	getBullet.bulletAlive = false;
	if (pool.size() == 20)
	{
		pool.pop_back();
	}
	else {
		pool.push_back(getBullet);
	}
	
}

void BulletManager::deleteBulletFromContainer(Bullet* getBullet)
{
	std::cout << " DELETING BULLET OBJECT: \n";
	delete[] getBullet;
}


void BulletManager::drawBullet()
{
	for (auto& item : extractor)
	{
		if (item.bulletAlive == true)
		{
			DrawRectangle((int)item.rec.x, (int)item.rec.y, (int)item.rec.width, (int)item.rec.height, item.color);
		}
		else {
			continue;
		}
	}
}

void BulletManager::updateBullet(float posX, float posY, Bullet getBullet)
{
	if (getBullet.bulletAlive == false)
	{
		getBullet.id = 1;
		getBullet.damage = 50.0f;
		getBullet.rec.x = posX;
		getBullet.rec.y = posY;
		getBullet.rec.width = 5.0f;
		getBullet.rec.height = 10.0f;
		getBullet.bulletAlive = true;
		getBullet.bulletSpeed = 5;
		getBullet.color = WHITE;
		extractor.push_back(getBullet);
		std::cout << "updated\n";
	}
	
}

void BulletManager::bulletMovement()//int speed)
{
	
	for(auto& item : extractor)
	{
		item.rec.y -= item.bulletSpeed;
	}
}


BulletManager::Bullet BulletManager::getBullet()
{
	Bullet hold = pool.back();
	pool.pop_back();
	if (pool.empty())
	{
		std::cout << "EMPTY!!! ";
		pool = bullet_Pool();
	}

	for (unsigned int i = 0; i < pool.size(); ++i)
	{
		std::cout << " content of the pool: " << i << " ";
	}

	return hold;
	
}


//MAKE SURE THAT THIS IS NOT CREATING NEW WITHOUT 
std::deque<BulletManager::Bullet> BulletManager::bullet_Pool() 
{
	std::deque<Bullet> returnStorage;
	for (int i = 0; i < varHolder::clipSize(); ++i)
	{
		float dmg = 0.0f;
		Rectangle rec = { 0.0f, 0.0f, 0.0f, 0.0f};
		int speed = 0;
		bool alive = false;
		Color color = WHITE;

		Bullet bullet = Bullet(0,dmg,{rec},speed, alive, color);
		returnStorage.push_back(bullet);
		std::cout << " bullet stored ";
	}
	return returnStorage;
}
