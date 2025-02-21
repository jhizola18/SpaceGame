#include "Spaceship.h"
#include <iostream>
#include "assert.h"
#include "math.h"
#include "MenuManager.h"
#include "raymath.h"

using namespace varHolder;
int magCount;


Player_Ship::Player_Ship()
	:
	bullet()
{
	//create a vector of string to pull the desired color of the player;
	ShipTexture = LoadTexture("Image/ship_red.png");
	point_Top = { 300.0f, 720.0f };
	point_Left = { 280.0f , 750.0f };
	point_Right = { 320.0f, 750.0f };
	vertices = { point_Top, point_Left, point_Right};
	gravity_Y = 9.08f;
	gravity_X = 0.0f;
	speed = 250.0f;
	health = 100.0f;
	position = {0.0f,0.0f};
	ship_colors = 0;
	coloreds = varHolder::ship_Colors();
}

Player_Ship::Player_Ship(const char* shipColor)
{
	this->ShipTexture = LoadTexture(shipColor);
	this->point_Top = {300.0f,720.0f};
	this->point_Left = {280.0f, 750.0f};
	this->point_Right = {320.0f, 750.0f};
	this->vertices = { point_Top, point_Left, point_Right };
	this->gravity_Y = 9.08f;
	this->gravity_X = 0.0f;
	this->speed = 250.0f;
	this->health = 100.0f;
	this->position = {0.0f, 0.0f};
	this->ship_colors = 0;
	this->coloreds = varHolder::ship_Colors();

}

Player_Ship::~Player_Ship()
{
	UnloadTexture(ShipTexture);
}

void Player_Ship::ResetShip()
{
	point_Top = { 300, 720 };
	point_Left = { 280 , 750 };
	point_Right = { 320, 750 };
	vertices = { point_Top, point_Left, point_Right };
	gravity_Y = 9.08f;
	gravity_X = 0.0f;
	speed = 250.0f;
	health = 100.0f;
	position = { 0.0f,0.0f };
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

int& Player_Ship::getship_color()
{
	return ship_colors;
}



float& Player_Ship::getHealth()
{
	return health;
}


void Player_Ship::Draw(int colortype)
{
	float new_X = ((point_Top.x + point_Right.x + point_Left.x)/3.0f);
	float new_Y = ((point_Top.y + point_Right.y + point_Left.y)/3.0f);

	Vector2 centroid = {new_X - 25.0f, new_Y - 35.0f};
	
	Texture2D currentTexture = LoadTexture(coloreds[colortype]);
	DrawTextureEx(currentTexture, centroid, 0.0f, 1.0f, WHITE);
}


void Player_Ship::moveForward()
{
	float deltaF = GetFrameTime();
	if (!pause)
	{
		point_Top.y -= speed * deltaF;
		point_Left.y -= speed * deltaF;
		point_Right.y -= speed * deltaF;
		gravity_Y++;
	}
	else {
		point_Top.y -= 0;
		point_Left.y -= 0;
		point_Right.y -= 0;
		gravity_Y++;
	}
	
}
void Player_Ship::gravityForward()
{
	float deltaF = GetFrameTime();
	if (!pause)
	{
		point_Top.y -= gravity_Y * deltaF;
		point_Left.y -= gravity_Y * deltaF;
		point_Right.y -= gravity_Y * deltaF;
	}
	else {
		point_Top.y -= 0;
		point_Left.y -= 0;
		point_Right.y -= 0;
	}
	
}

void Player_Ship::moveBackward()
{
	float deltaB = GetFrameTime();
	if (!pause)
	{
		point_Top.y += speed * deltaB;
		point_Left.y += speed * deltaB;
		point_Right.y += speed * deltaB;
		gravity_Y--;
	}
	else {
		point_Top.y += 0;
		point_Left.y += 0;
		point_Right.y += 0;
		gravity_Y--;
	}
	
}

void Player_Ship::gravityBackward()
{
	float deltaB = GetFrameTime();
	if (!pause)
	{
		point_Top.y -= gravity_Y * deltaB;
		point_Left.y -= gravity_Y * deltaB;
		point_Right.y -= gravity_Y * deltaB;
	}
	else {
		point_Top.y -= 0;
		point_Left.y -= 0;
		point_Right.y -= 0;
	}
	
}


void Player_Ship::moveLeft()
{
	float deltaL = GetFrameTime();
	if (!pause)
	{
		point_Top.x -= speed * deltaL;
		point_Left.x -= speed * deltaL;
		point_Right.x -= speed * deltaL;
		gravity_X++;
	}
	else {
		point_Top.x -= 0;
		point_Left.x -= 0;
		point_Right.x -= 0;
		gravity_X++;
	}
	
}

void Player_Ship::gravityLeft()
{
	float deltaL = GetFrameTime();
	if (!pause)
	{
		point_Top.x -= gravity_X * deltaL;
		point_Left.x -= gravity_X * deltaL;
		point_Right.x -= gravity_X * deltaL;

	}
	else {
		point_Top.x -= 0;
		point_Left.x -= 0;
		point_Right.x -= 0;
	}
	
	
}


void Player_Ship::moveRight()
{
	float deltaR = GetFrameTime();
	if (!pause)
	{
		point_Top.x += speed * deltaR;
		point_Left.x += speed * deltaR;
		point_Right.x += speed * deltaR;
		gravity_X--;
	}
	else {
		point_Top.x += 0;
		point_Left.x += 0;
		point_Right.x += 0;
		gravity_X--;
	}
	
}

void Player_Ship::gravityRight()
{
	float deltaR = GetFrameTime();
	if (!pause)
	{
		point_Top.x -= gravity_X * deltaR;
		point_Left.x -= gravity_X * deltaR;
		point_Right.x -= gravity_X * deltaR;
	}
	else {
		point_Top.x -= 0;
		point_Left.x -= 0;
		point_Right.x -= 0;
	}
	
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

BulletManager::~BulletManager() noexcept
{
	for (unsigned int i = 0; i < pool.size();++i)
	{
		pool.pop_back();
	}
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

void BulletManager::resetAllBullet()
{
	for (unsigned int i = 0; i < extractor.size(); ++i)
	{
		extractor.pop_back();
	}
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
	}
	
}

void BulletManager::bulletMovement(Vector2 target, float dist)
{
	if (!pause)
	{
		for (auto& item : extractor)
		{
			item.rec.y -= item.bulletSpeed;
		}
	}
	else {
		for (auto& item : extractor)
		{
			item.rec.y -= 0;
		}
	}
	
}


BulletManager::Bullet BulletManager::getBullet()
{
	Bullet hold = pool.back();
	pool.pop_back();
	if (pool.empty())
	{
		pool = bullet_Pool();
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
	}
	return returnStorage;
}


