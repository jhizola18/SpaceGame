#include "Spaceship.h"
#include <iostream>


//bool bulletActive;
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
	speed = 100.0f;
	bulletVelocity = 0;
}

Vector2 Player_Ship::getPointTop() const
{
	return point_Top;
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
BulletManager::Bullet::Bullet(Rectangle rect, int speed, bool alive, Color col)
{
	rec = rect;
	bulletSpeed = speed;
	bulletAlive = alive;
	color = col;
};

BulletManager::BulletManager()
{
	pool = bullet_Pool();
}

void BulletManager::drawBullet()
{
	for (const auto& item : extractor)
	{
		DrawRectangle(item.rec.x, item.rec.y, item.rec.width, item.rec.height, item.color);
		std::cout << "Drawing\n";
	}
	
}

void BulletManager::updateBullet(float posX, float posY, Bullet getBullet)
{
	if (getBullet.bulletAlive == false)
	{
		getBullet.rec.x = posX;
		getBullet.rec.y = posY;
		getBullet.rec.width = 5.0f;
		getBullet.rec.height = 10.0f;
		getBullet.bulletAlive = true;
		getBullet.bulletSpeed = 5.0f;
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
		/*Bullet bullet = Bullet({0,0,0,0},0,false,WHITE);
		ship.handler.push_back(bullet);*/
		std::cout << "EMPTY!!! ";
	}
	return hold;
}
//MAKE SURE THAT THIS IS NOT CREATING NEW WITHOUT 
std::vector<BulletManager::Bullet> BulletManager::bullet_Pool() 
{
	std::vector<Bullet> returnStorage;
	for (int i = 0; i < varHolder::clipSize(); ++i)
	{
		Rectangle rec = { 0.0f, 0.0f, 0.0f, 0.0f};
		int speed = 5;
		bool alive = false;
		Color color = WHITE;

		Bullet bullet = Bullet({rec},speed, alive, color);
		returnStorage.push_back(bullet);
		std::cout << " bullet stored ";
	}
	
	return returnStorage;
}
