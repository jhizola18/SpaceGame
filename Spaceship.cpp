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

	gravity_Y = 9.08f;
	gravity_X = 0.0f;
	point_Top = {300, 720};
	point_Left = {280 , 750};
	point_Right = { 320, 750 };
	float new_X = ((point_Top.x + point_Right.x + point_Left.x) / 3.0f);
	float new_Y = ((point_Top.y + point_Right.y + point_Left.y) / 3.0f);
	speed = 250.0f;
	health = 100.0f;
	position = {0.0f,0.0f};
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
	DrawTriangle(point_Top, point_Left, point_Right, BLUE);
}

void Player_Ship::rotationShip()
{
	
	
	if (IsCursorOnScreen())
	{
		float new_X = ((point_Top.x + point_Right.x + point_Left.x) / 3.0f);
		float new_Y = ((point_Top.y + point_Right.y + point_Left.y) / 3.0f);
		Vector2 center = {new_X, new_Y};

		Vector2 Top_distance = Vector2Subtract(center, varHolder::cursorPosition());
		Vector2 Right_distance = Vector2Subtract(center, varHolder::cursorPosition());
		Vector2 Left_distance = Vector2Subtract(center, varHolder::cursorPosition());
		

		Camera2D camera = { 0 };
		camera.offset = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2};
		camera.zoom = 1.0f;
		camera.rotation = 0.0f;
		Vector2 mousePos = GetScreenToWorld2D(varHolder::cursorPosition(), camera);
		Vector2 DirectionT = Vector2Subtract(center, mousePos);
		Vector2 DirectionR = Vector2Subtract(center, mousePos);
		Vector2 DirectionL = Vector2Subtract(center, mousePos);
		float angleT = atan2f(DirectionT.y, DirectionT.x);//Vector2Angle(DirectionT, mousePos) * DEG2RAD;
		float angleR = atan2f(DirectionR.y, DirectionR.x);
		float angleL = atan2f(DirectionL.y, DirectionL.x);//Vector2Angle(DirectionR, mousePos) * DEG2RAD;
		//float angleL = Vector2Angle({ Left_distanceX, Left_distanceY }, mousePos) * DEG2RAD;

		//float directionT = sqrt((Top_distanceX * Top_distanceX) + (Top_distanceY * Top_distanceY));
		//float directionR = sqrt((Right_distanceX * Right_distanceX) + (Right_distanceY * Right_distanceY));
		//float directionL = sqrt((Left_distanceX * Left_distanceX) + (Left_distanceY * Left_distanceY));
		
		//float magnitudeTX = Top_distanceX / directionT * speed * GetFrameTime();
		//float magnitudeTY = Top_distanceY / directionT;

		//float magnitudeRX = Right_distanceX / directionR;
		//float magnitudeRY = Right_distanceY / directionR;

		//float magnitudeLX = Left_distanceX / directionL;
		//float magnitudeLY = Left_distanceY / directionL;
		
		
		point_Top.x -= DirectionT.x * -cos(angleT) * speed * GetFrameTime();
		point_Top.y -= DirectionT.y * sin(angleT) * speed * GetFrameTime();
		//point_Top = Vector2Rotate(DirectionT, angleT);
		//point_Right = Vector2Rotate(DirectionR, angleR);
		//point_Left = Vector2Rotate(DirectionL, angleL);

		//point_Right = {magnitudeTX, magnitudeTY};

		//point_Left = Vector2Subtract(point_Top, point_Right)
		//point_Right.x -= magnitudeRX * -cos(angleR) * speed * GetFrameTime();
		//point_Right.y -= magnitudeRY * sin(angleR) * speed * GetFrameTime();

		//point_Left.x -= magnitudeLX * cos(angleT) * speed * GetFrameTime();
		//point_Left.y -= magnitudeLY * -sin(angleT) * speed * GetFrameTime();


	}
	

	
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
	for (int i = 0; i < pool.size();++i)
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


//Extra Codes
/*float Top_distanceX = GetMouseX() - point_Top.x;
	float Top_distanceY = GetMouseY() - point_Top.y;

	float Right_distanceX = GetMouseX() - point_Right.x;
	float Right_distanceY = GetMouseY() - point_Right.y;

	float Left_distanceX = GetMouseX() - point_Left.x;
	float Left_distanceY = GetMouseY() - point_Left.y;

	/*	Vector2 top{Top_distanceX, Top_distanceY};
	Vector2 right{Right_distanceX, Right_distanceY};
	Vector2 left{Left_distanceX, Left_distanceY};


	float normalizeT = sqrt(pow(Top_distanceX, 2) + pow(Top_distanceY, 2));
	float normalizeR = sqrt(pow(Right_distanceX, 2) + pow(Right_distanceY, 2));
	float normalizeL = sqrt(pow(Left_distanceX, 2) + pow(Left_distanceY, 2));

	point_Top.x = tan(Top_distanceX / normalizeT);
	point_Top.y = tan(Top_distanceY / normalizeT);
	point_Left.x = tan(Left_distanceX / normalizeL);
	point_Left.y = tan(Left_distanceY / normalizeL);
	point_Right.x = tan(Right_distanceX / normalizeR);
	point_Right.y = tan(Right_distanceY / normalizeR); */

